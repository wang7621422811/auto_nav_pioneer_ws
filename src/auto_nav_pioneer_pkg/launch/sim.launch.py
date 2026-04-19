"""
Launch the full autonomous navigation stack with fake odometry
TODO It need to be tested on real data on real poineer
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    pkg_share = get_package_share_directory('auto_nav_pioneer_pkg')
    default_params = os.path.join(pkg_share, 'config', 'sim_params.yaml')
    default_waypoints = os.path.join(pkg_share, 'config', 'waypoints_sim.yaml')

    params_file = LaunchConfiguration('params_file')
    waypoint_file = LaunchConfiguration('waypoint_file')

    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file', default_value=default_params,
            description='Path to sim_params.yaml'),
        DeclareLaunchArgument(
            'waypoint_file', default_value=default_waypoints,
            description='Path to waypoint list YAML'),

        # Gamepad reader
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            parameters=[{'deadzone': 0.1, 'autorepeat_rate': 20.0}],
        ),

        # Safety + mode switcher
        Node(
            package='auto_nav_pioneer_pkg',
            executable='safety_teleop_node',
            name='safety_teleop_node',
            parameters=[params_file],
            output='screen',
        ),

        # Waypoint sequencer
        Node(
            package='auto_nav_pioneer_pkg',
            executable='waypoint_manager_node',
            name='waypoint_manager_node',
            parameters=[params_file, {'waypoint_file': waypoint_file}],
            output='screen',
        ),

        # Path tracker
        Node(
            package='auto_nav_pioneer_pkg',
            executable='pure_pursuit_controller_node',
            name='pure_pursuit_controller_node',
            parameters=[params_file],
            output='screen',
        ),

        # Fake robot (integrates cmd_vel → odom)
        Node(
            package='auto_nav_pioneer_pkg',
            executable='fake_odom_node',
            name='fake_odom_node',
            parameters=[params_file],
            output='screen',
        ),
    ])