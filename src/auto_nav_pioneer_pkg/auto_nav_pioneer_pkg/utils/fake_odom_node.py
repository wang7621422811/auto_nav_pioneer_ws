"""
Fake odometry node for closed-loop testing without a simulator.

Integrates /cmd_vel into /odom using a simple differential-drive model.
NOT for real robot use — only for testing the navigation stack end-to-end.
"""

from math import cos, sin

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

from auto_nav_pioneer_pkg.utils.geometry import wrap_angle


class FakeOdomNode(Node):
    def __init__(self):
        super().__init__('fake_odom_node')

        self.declare_parameter('publish_rate_hz', 30.0)
        self.declare_parameter('initial_x', 0.0)
        self.declare_parameter('initial_y', 0.0)
        self.declare_parameter('initial_yaw', 0.0)

        rate = self.get_parameter('publish_rate_hz').value
        self.x = self.get_parameter('initial_x').value
        self.y = self.get_parameter('initial_y').value
        self.yaw = self.get_parameter('initial_yaw').value

        self.last_cmd = Twist()
        self.last_time = self.get_clock().now()

        self.create_subscription(Twist, '/cmd_vel', self.cmd_callback, 10)
        self.odom_pub = self.create_publisher(Odometry, '/odom', 10)
        self.timer = self.create_timer(1.0 / rate, self.tick)

        self.get_logger().info(
            f'Fake odom started at ({self.x:.2f}, {self.y:.2f}, '
            f'yaw={self.yaw:.2f})')

    def cmd_callback(self, msg: Twist):
        self.last_cmd = msg

    def tick(self):
        # Compute dt
        now = self.get_clock().now()
        dt = (now - self.last_time).nanoseconds / 1e9
        self.last_time = now

        if dt <= 0 or dt > 0.5:
            return  # Skip bad dt (startup or long pauses)

        # Integrate differential-drive kinematics
        v = self.last_cmd.linear.x
        w = self.last_cmd.angular.z
        self.x += v * cos(self.yaw) * dt
        self.y += v * sin(self.yaw) * dt
        self.yaw = wrap_angle(self.yaw + w * dt)

        # Publish as Odometry
        msg = Odometry()
        msg.header.stamp = now.to_msg()
        msg.header.frame_id = 'odom'
        msg.child_frame_id = 'base_link'
        msg.pose.pose.position.x = self.x
        msg.pose.pose.position.y = self.y
        # Yaw → quaternion (simplified 2D case)
        from math import cos as c, sin as s
        msg.pose.pose.orientation.z = s(self.yaw / 2.0)
        msg.pose.pose.orientation.w = c(self.yaw / 2.0)
        msg.twist.twist.linear.x = v
        msg.twist.twist.angular.z = w

        self.odom_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    try:
        rclpy.spin(FakeOdomNode())
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()