"""
Safety teleop node for AUTO 4508 Pioneer robot.

Responsibilities:
1. Read gamepad input from /joy topic.
2. Mange three modes: IDLE, MANUAL, AUTO.
3. Implement dead-man switch for AUTO mode safety.
4. Output final `/cmd_vel` command to robot.
"""

from enum import Enum

import rclpy # ROS 2 Python client library
from rclpy.node import Node
from sensor_msgs.msg import Joy # Message type for gamepad input
from geometry_msgs.msg import Twist # Message type for velocity commands
from auto_nav_pioneer_pkg.teleop.gamepad_config import get_profile

class RobotMode(Enum):
    IDLE = "IDLE"
    """Robot is in idle mode, no control input received."""
    MANUAL = "MANUAL"
    """Robot is in manual mode, controlled by gamepad input."""
    AUTO = "AUTO"
    """Robot is in autonomous mode, controlled by navigation stack."""

class SafetyTelopNode(Node):
    """
    作用: 安全遥控节点，管理机器人模式和控制输入，确保在自动模式下的安全性。
    """

    def __init__(self):
        super().__init__("safety_teleop_node")
        self.get_logger().info("Initializing Safety Teleop Node...")

        # ------ Parameters from YAML
        # --- Parameters (tunable via YAML) ---
        self.declare_parameter('max_linear_speed', 0.5)     # m/s
        self.declare_parameter('max_angular_speed', 1.0)    # rad/s
        self.declare_parameter('publish_rate_hz', 20.0)
        self.declare_parameter('gamepad_profile', 'ps4')  # NEW

        self.max_lin = self.get_parameter('max_linear_speed').value
        self.max_ang = self.get_parameter('max_angular_speed').value
        rate = self.get_parameter('publish_rate_hz').value
        profile_name = self.get_parameter('gamepad_profile').value

        self.profile = get_profile(profile_name)
        self.get_logger().info(f"Using gamepad profile: {self.profile.name}")

        # --- State ---
        # 给当前机器人对象，设置【模式】变量
        self.mode = RobotMode.IDLE

        # 给当前机器人对象，设置【死区按键/使能键】状态变量
        self.deadman_pressed = False

        # 给当前机器人对象，创建【手动控制指令】变量（存摇杆数据）
        self.manual_cmd = Twist()

        # 给当前机器人对象，创建【自动控制指令】变量
        self.auto_cmd = Twist()

        # Track previous button state to detect rising edge (button just pressed)
        # 1. 定义类成员变量 `prev_cross`，初始值设为 0，用于记录上一时刻十字按键的状态
        # 2. 定义类成员变量 `prev_circle`，初始值设为 0，用于记录上一时刻圆圈按键的状态
        # 3. 通过保存按键历史状态，后续可对比当前按键值与历史值，检测按键**上升沿触发**（也就是按键刚刚被按下的瞬间）
        # 4. 初始默认按键均为未按下状态，保证第一次按键判断逻辑正常生效
        self.prev_cross = 0
        self.prev_circle = 0


        # --- ROS2 interfaces ---
        self.joy_sub = self.create_subscription(Joy, '/joy', self.joy_callback, 10)
        self.auto_sub = self.create_subscription(
            Twist, '/cmd_vel_auto', self.auto_callback, 10)
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Periodic publisher — publishes at fixed rate, even without new input
        self.timer = self.create_timer(1.0 / rate, self.publish_cmd)

        self.get_logger().info(
            f'Safety teleop started. Mode={self.mode.value}. '
            f'Press X for AUTO (hold back trigger), O for MANUAL.')

    
    # Callbacks
    def joy_callback(self, msg: Joy):
        """
        Process raw gamepad input: mode switches and stick values.
        """

        p = self.profile  # shorthand

        # --- Safety check: verify the gamepad has enough buttons/axes ---
        if not self._validate_arrays(msg):
            return  # Skip this message, keep robot stopped

        # 1. Detect mode switches (rising edge)

        # --- Mode switches (rising edge) ---
        btn_auto = msg.buttons[p.btn_enable_auto]
        btn_manual = msg.buttons[p.btn_enable_manual]
        if btn_auto == 1 and self.prev_auto == 0:
            self._switch_mode(RobotMode.AUTO)
        if btn_manual == 1 and self.prev_manual == 0:
            self._switch_mode(RobotMode.MANUAL)
        self.prev_auto = btn_auto
        self.prev_manual = btn_manual

        # # If press button x → AUTO mode, otherwise MANUAL
        # if cross == 1 and self.prev_cross == 0:
        #     self._switch_mode(RobotMode.AUTO)
        # if circle == 1 and self.prev_circle == 0:
        #     self._switch_mode(RobotMode.MANUAL)

        # self.prev_cross = cross
        # self.prev_circle = circle

        # # 2. Update dead-man state
        # # Either L2 or R2 triggers the dead-man 
        # l2 = msg.axes[MAPPING.AXIS_L2_TRIGGER]
        # r2 = msg.axes[MAPPING.AXIS_R2_TRIGGER]

        # --- Dead-man: check whichever type the profile uses ---
        l2_held = self._is_trigger_held(msg, p.l2_axis, p.l2_button)
        r2_held = self._is_trigger_held(msg, p.r2_axis, p.r2_button)
        self.deadman_pressed = l2_held or r2_held

        #if self.deadman_pressed:
            # self.get_logger().info(f"self.deadman_pressed: whether pressed l2 {l2_held} or r2 {r2_held}: {self.deadman_pressed}")

        # 3. Update manual stick command
        # 1. 读取游戏手柄左侧摇杆上下方向的轴数值，对应映射常量`MAPPING.AXIS_LEFT_STICK_Y`
        # 2. 将该摇杆数值乘以最大线速度`self.max_lin`，赋值给小车前后移动的线速度指令`self.manual_cmd.linear.x`
        # 3. 读取游戏手柄右侧摇杆左右方向的轴数值，对应映射常量`MAPPING.AXIS_RIGHT_STICK_X`
        # 4. 将该摇杆数值乘以最大角速度`self.max_ang`，赋值给小车左右转向的角速度指令`self.manual_cmd.angular.z`
        # 5. 整体实现手柄摇杆控制机器人直线前后移动、原地左右旋转运动
        # self.manual_cmd.linear.x = msg.axes[MAPPING.AXIS_LEFT_STICK_Y] * self.max_lin
        # self.manual_cmd.angular.z = msg.axes[MAPPING.AXIS_RIGHT_STICK_X] * self.max_ang

        # --- Sticks ---
        self.manual_cmd.linear.x = msg.axes[p.axis_forward] * self.max_lin
        self.manual_cmd.angular.z = msg.axes[p.axis_turn] * self.max_ang

    def _is_trigger_held(self, msg: Joy, axis_idx, button_idx) -> bool:
        """Check trigger state, handling both analog axis and digital button."""
        if button_idx is not None:
            # Digital (Switch-style): button = 1 means pressed
            return msg.buttons[button_idx] == 1
        if axis_idx is not None:
            # Analog (PS4-style): axis goes toward -1.0 when pressed
            # Guard against uninitialized state (value near 0.0)
            return msg.axes[axis_idx] < self.profile.trigger_pressed_threshold
        return False

    def auto_callback(self, msg: Twist):
        """
        Recive commands from navigation planner
        """
        self.auto_cmd = msg


    # -------------------------------
    # Core logic
    # -------------------------------

    def publish_cmd(self):
        """
        Decide and publish the final /cmd_vel at a fixed rate.
        """

        out = Twist()

        if self.mode == RobotMode.MANUAL:
            out = self.manual_cmd
        elif self.mode == RobotMode.AUTO:
            # Dead-man rule: only forward auto command if trigger is held.
            if self.deadman_pressed:
                out = self.auto_cmd
            else:
                # Trigger relased -- force stop
                pass # out stays zero

        # IDLE mode always publishes zeros
        self.cmd_pub.publish(out)

    def _switch_mode(self, new_mode: RobotMode):
        if self.mode!= new_mode:
            self.get_logger().info(
                f'Mode change: {self.mode.value} -> {new_mode.value}')
            self.mode = new_mode

    def _validate_arrays(self, msg: Joy) -> bool:
        """Check that the gamepad has all the indices the profile needs."""
        p = self.profile

        # Collect all required indices
        required_buttons = [p.btn_enable_auto, p.btn_enable_manual]
        if p.l2_button is not None:
            required_buttons.append(p.l2_button)
        if p.r2_button is not None:
            required_buttons.append(p.r2_button)

        required_axes = [p.axis_forward, p.axis_turn]
        if p.l2_axis is not None:
            required_axes.append(p.l2_axis)
        if p.r2_axis is not None:
            required_axes.append(p.r2_axis)

        # Check bounds
        max_btn = max(required_buttons)
        max_axis = max(required_axes)

        if max_btn >= len(msg.buttons) or max_axis >= len(msg.axes):
            # Warn once per second to avoid spam
            self.get_logger().warn(
                f'Gamepad has {len(msg.buttons)} buttons, {len(msg.axes)} axes '
                f'but profile "{p.name}" needs button[{max_btn}], axis[{max_axis}]. '
                f'Check if the correct gamepad is connected.',
                throttle_duration_sec=2.0)
            return False

        return True
            
def main(args=None):
    rclpy.init(args=args)
    node = SafetyTelopNode()
    try:
        # 调用 ROS2 Python 接口 rclpy 的 spin 方法，传入当前节点 node
        # 让节点进入循环等待状态，持续监听 ROS2 话题、服务、动作等消息事件
        # 阻塞当前程序主线程，不会往下执行后续代码
        # 节点实时处理订阅回调、服务响应等 ROS2 通信逻辑
        # 只有节点被正常关闭时，循环才会退出，程序继续往下运行
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        # Guard against double-shutdown (Jazzy signal handler auto-shutdowns)
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main()