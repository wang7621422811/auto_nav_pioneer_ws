"""
Pure Pursuit Controller Node.

Subscribes to:
  /current_waypoint  - target from waypoint_manager
  /odom              - robot pose from simulation/real robot

Publishes:
  /cmd_vel_auto      - velocity command for safety_teleop to forward
"""

from math import atan2, sin, fabs, pi

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

from auto_nav_pioneer_interfaces.msg import Waypoint
from auto_nav_pioneer_pkg.utils.geometry import (
    wrap_angle, quaternion_to_yaw, distance_2d)
from std_msgs.msg import Bool


class PurePursuitControllerNode(Node):
    def __init__(self):
        super().__init__('pure_pursuit_controller_node')

        # --- Parameters (all tunable via YAML) ---
        self.declare_parameter('max_linear_speed', 0.4)    # m/s
        self.declare_parameter('max_angular_speed', 0.8)   # rad/s
        self.declare_parameter('lookahead_distance', 1.0)  # m (Ld)
        self.declare_parameter('stop_distance', 0.3)       # m (smaller than arrival_tolerance)
        self.declare_parameter('rotate_in_place_angle', 1.0)  # rad, ~57 deg
        self.declare_parameter('control_rate_hz', 20.0)

        self.v_max = self.get_parameter('max_linear_speed').value
        self.w_max = self.get_parameter('max_angular_speed').value
        self.Ld = self.get_parameter('lookahead_distance').value
        self.stop_dist = self.get_parameter('stop_distance').value
        self.rotate_thresh = self.get_parameter('rotate_in_place_angle').value
        rate = self.get_parameter('control_rate_hz').value

        self.in_rotate_mode = False  # NEW: track current mode with hysteresis

        self.mission_active = False
        self.create_subscription(Bool, '/mission_active', self.active_callback, 10)

        # --- State ---
        self.current_target = None           # type: Waypoint | None
        self.robot_x = None
        self.robot_y = None
        self.robot_yaw = None

        # --- ROS interfaces ---
        self.create_subscription(
            Waypoint, '/current_waypoint', self.waypoint_callback, 10)
        self.create_subscription(
            Odometry, '/odom', self.odom_callback, 10)
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel_auto', 10)

        self.timer = self.create_timer(1.0 / rate, self.control_loop)

        self.get_logger().info(
            f'Pure pursuit started. Ld={self.Ld}m, v_max={self.v_max}m/s')
        
    def active_callback(self, msg: Bool):
        self.mission_active = msg.data

    # ----------------------------------------------------------
    # Callbacks
    # ----------------------------------------------------------
    def waypoint_callback(self, msg: Waypoint):
        # Detect target change — reset state to avoid stale commands
        if self.current_target is None or self.current_target.id != msg.id:
            self.in_rotate_mode = False  # Re-evaluate rotation need
            self.get_logger().info(
                f'New target: WP {msg.id} at ({msg.x:.2f}, {msg.y:.2f})')
        self.current_target = msg

    def odom_callback(self, msg: Odometry):
        self.robot_x = msg.pose.pose.position.x
        self.robot_y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.robot_yaw = quaternion_to_yaw(q.x, q.y, q.z, q.w)

    # ----------------------------------------------------------
    # Main control loop
    # ----------------------------------------------------------
    def control_loop(self):
        """Called at control_rate_hz. Computes and publishes /cmd_vel_auto."""
        cmd = Twist()  # defaults to all zeros

        if not self.mission_active:
            self.cmd_pub.publish(Twist())  # zero command
            self.in_rotate_mode = False
            self.get_logger().info(
                'Mission paused (ARRIVED/IDLE), holding still',
                throttle_duration_sec=2.0)
            return

        # Sanity checks — don't move if we're missing data
        if self.current_target is None:
            self.cmd_pub.publish(cmd)
            self.get_logger().warn(
                'No target yet', throttle_duration_sec=2.0)
            return

        if self.robot_x is None:
            self.cmd_pub.publish(cmd)
            self.get_logger().warn(
                'No odometry yet', throttle_duration_sec=2.0)
            return

        # --- Compute errors ---
        dx = self.current_target.x - self.robot_x
        dy = self.current_target.y - self.robot_y
        distance = distance_2d(
            self.robot_x, self.robot_y,
            self.current_target.x, self.current_target.y)

        target_angle = atan2(dy, dx)
        alpha = wrap_angle(target_angle - self.robot_yaw)


        # --- Decide action with hysteresis ---
        stop_threshold = self.current_target.arrival_tolerance
        if distance < stop_threshold:
            self.cmd_pub.publish(cmd)
            self.in_rotate_mode = False
            self.get_logger().info(
                f'At target WP {self.current_target.id} '
                f'(dist={distance:.2f}m <= {stop_threshold:.2f}m), holding still',
                throttle_duration_sec=2.0)
            return

        # Hysteresis: enter rotate mode at 1.0 rad, exit at 0.3 rad
        enter_thresh = self.rotate_thresh       # e.g. 1.0
        exit_thresh = self.rotate_thresh * 0.3  # e.g. 0.3

        if not self.in_rotate_mode and fabs(alpha) > enter_thresh:
            self.in_rotate_mode = True
        elif self.in_rotate_mode and fabs(alpha) < exit_thresh:
            self.in_rotate_mode = False

        if self.in_rotate_mode:
            cmd.linear.x = 0.0
            Kp = 1.5
            cmd.angular.z = self._clamp(Kp * alpha, -self.w_max, self.w_max)
            self.get_logger().info(
                f'Rotate in place: alpha={alpha:.2f}rad ω={cmd.angular.z:.2f}',
                throttle_duration_sec=1.0)
        else:
            # Normal pure pursuit
            cmd.linear.x = self.v_max
            omega = (2.0 * self.v_max * sin(alpha)) / self.Ld
            cmd.angular.z = self._clamp(omega, -self.w_max, self.w_max)
            self.get_logger().info(
                f'Pursuing WP {self.current_target.id}: '
                f'd={distance:.2f}m α={alpha:.2f}rad ω={cmd.angular.z:.2f}',
                throttle_duration_sec=1.0)

        self.cmd_pub.publish(cmd)

        # --- Decide action ---
        # if distance < self.stop_dist:
        #     # Arrived — command zero velocity
        #     self.cmd_pub.publish(cmd)
        #     self.get_logger().info(
        #         f'At target (dist={distance:.2f}m), holding still',
        #         throttle_duration_sec=2.0)
        #     return

        # if fabs(alpha) > self.rotate_thresh:
        #     # # Target is sharply off-heading → rotate in place
        #     # cmd.linear.x = 0.0
        #     # cmd.angular.z = self._clamp(
        #     #     self.w_max * (1.0 if alpha > 0 else -1.0),
        #     #     -self.w_max, self.w_max)

        #      # Target is sharply off-heading → rotate in place
        #     cmd.linear.x = 0.0
        #     # Proportional control: turn slower as we align with the target
        #     # Kp is a gain, e.g. 1.5 rad/s per rad of error
        #     Kp = 1.5
        #     omega_raw = Kp * alpha
        #     cmd.angular.z = self._clamp(omega_raw, -self.w_max, self.w_max)


        #     self.get_logger().info(
        #         f'Rotate in place: alpha={alpha:.2f}rad',
        #         throttle_duration_sec=1.0)
        # else:
        #     # Normal pure pursuit
        #     cmd.linear.x = self.v_max
        #     # Core pure pursuit formula: ω = 2·v·sin(α) / Ld
        #     omega = (2.0 * self.v_max * sin(alpha)) / self.Ld
        #     cmd.angular.z = self._clamp(omega, -self.w_max, self.w_max)

        #     # self.get_logger().info(
        #     #     f'Pursuing WP {self.current_target.id}: '
        #     #     f'd={distance:.2f}m α={alpha:.2f}rad ω={cmd.angular.z:.2f}',
        #     #     throttle_duration_sec=1.0)

        # self.cmd_pub.publish(cmd)

    # ----------------------------------------------------------
    # Helpers
    # ----------------------------------------------------------
    @staticmethod
    def _clamp(value: float, lo: float, hi: float) -> float:
        return max(lo, min(hi, value))


def main(args=None):
    rclpy.init(args=args)
    try:
        node = PurePursuitControllerNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # Guard against double-shutdown (Jazzy signal handler auto-shutdowns)
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()