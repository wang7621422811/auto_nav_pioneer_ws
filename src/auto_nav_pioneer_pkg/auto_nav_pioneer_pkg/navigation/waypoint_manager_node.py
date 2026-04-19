"""
Waypoint Manager Node.

Manages a list of waypoints, publishes the current target, and advances
to the next one when the robot arrives within tolerance.
"""

from enum import Enum
from math import hypot
from typing import List, Optional

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool

from auto_nav_pioneer_interfaces.msg import Waypoint
from auto_nav_pioneer_pkg.utils.waypoint_loader import load_waypoints_from_yaml


class MissionState(Enum):
    IDLE = "IDLE"
    NAVIGATING = "NAVIGATING"
    ARRIVED = "ARRIVED"
    COMPLETE = "COMPLETE"


class WaypointManagerNode(Node):
    def __init__(self):
        super().__init__('waypoint_manager_node')

        # --- Parameters ---
        self.declare_parameter('waypoint_file', '')
        self.declare_parameter('publish_rate_hz', 10.0) # 10 Hz
        self.declare_parameter('arrival_pause_sec', 2.0) # 2 seconds pausing

        self.mission_active_pub = self.create_publisher(Bool, '/mission_active', 10)

        # wp_file : [waypoint,waypoint,]
        wp_file = self.get_parameter('waypoint_file').value 
        rate = self.get_parameter('publish_rate_hz').value
        self.arrival_pause = self.get_parameter('arrival_pause_sec').value

        if not wp_file:
            self.get_logger().error(
                'No waypoint_file parameter provided. Shutting down.')
            raise RuntimeError('waypoint_file is required')

        # --- Load waypoints ---
        try:
            self.waypoints: List[Waypoint] = load_waypoints_from_yaml(wp_file)
        except Exception as e:
            self.get_logger().error(f'Failed to load waypoints: {e}')
            raise

        self.get_logger().info(
            f'Loaded {len(self.waypoints)} waypoints from {wp_file}')

        # --- State ---
        self.state = MissionState.IDLE
        self.current_index = 0
        self.current_pose_x: Optional[float] = None
        self.current_pose_y: Optional[float] = None
        self.arrived_at_time: Optional[float] = None

        # --- ROS interfaces ---
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)
        self.waypoint_pub = self.create_publisher(Waypoint, '/current_waypoint', 10)
        self.mission_complete_pub = self.create_publisher(Bool, '/mission_complete', 10)

        self.timer = self.create_timer(1.0 / rate, self.tick)

        # Start navigating right away (we'll add a start service later)
        self._transition_to(MissionState.NAVIGATING)

    # ----------------------------------------------------------
    # Callbacks
    # ----------------------------------------------------------
    def odom_callback(self, msg: Odometry):
        """Update the robot's current position from odometry."""
        self.current_pose_x = msg.pose.pose.position.x
        self.current_pose_y = msg.pose.pose.position.y

    # ----------------------------------------------------------
    # Main loop
    # ----------------------------------------------------------
    def tick(self):
        """Called at publish_rate_hz. Evaluates state and publishes targets."""

        is_active = (self.state == MissionState.NAVIGATING)
        msg = Bool()
        msg.data = is_active
        self.mission_active_pub.publish(msg)

        if self.state == MissionState.NAVIGATING:
            self._handle_navigating()
        elif self.state == MissionState.ARRIVED:
            self._handle_arrived()
        elif self.state == MissionState.COMPLETE:
            self._publish_mission_complete(True)
        # IDLE does nothing

    def _handle_navigating(self):
        if self.current_pose_x is None:
            # No odom yet — wait
            self.get_logger().warn(
                'Waiting for /odom...', throttle_duration_sec=2.0)
            return

        wp = self.waypoints[self.current_index]
        self.waypoint_pub.publish(wp)

        distance = hypot(
            wp.x - self.current_pose_x,
            wp.y - self.current_pose_y)

        self.get_logger().info(
            f'Heading to WP {wp.id}: distance={distance:.2f}m',
            throttle_duration_sec=1.0)

        if distance <= wp.arrival_tolerance:
            self.get_logger().info(
                f'ARRIVED at waypoint {wp.id} (distance={distance:.2f}m)')
            self.arrived_at_time = self.get_clock().now().nanoseconds / 1e9
            self._transition_to(MissionState.ARRIVED)

    def _handle_arrived(self):
        """Wait at the waypoint for arrival_pause_sec, then advance."""
        now = self.get_clock().now().nanoseconds / 1e9
        elapsed = now - self.arrived_at_time

        if elapsed < self.arrival_pause:
            return  # still pausing

        # Move to next waypoint
        self.current_index += 1
        if self.current_index >= len(self.waypoints):
            self.get_logger().info('All waypoints complete!')
            self._transition_to(MissionState.COMPLETE)
        else:
            self.get_logger().info(
                f'Advancing to waypoint {self.current_index}')
            self._transition_to(MissionState.NAVIGATING)

    # ----------------------------------------------------------
    # Helpers
    # ----------------------------------------------------------
    def _transition_to(self, new_state: MissionState):
        if self.state != new_state:
            self.get_logger().info(
                f'State: {self.state.value} -> {new_state.value}')
            self.state = new_state

    def _publish_mission_complete(self, value: bool):
        msg = Bool()
        msg.data = value
        self.mission_complete_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    try:
        node = WaypointManagerNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f'Fatal error: {e}')
    finally:
        # Guard against double-shutdown (Jazzy signal handler auto-shutdowns)
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()