"""Launch full nav stack inside Gazebo Harmonic simulation."""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    SetEnvironmentVariable,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg_share = get_package_share_directory('auto_nav_pioneer_pkg')
    default_params = os.path.join(pkg_share, 'config', 'sim_params.yaml')
    default_waypoints = os.path.join(pkg_share, 'config', 'waypoints_sim.yaml')
    default_world = os.path.join(pkg_share, 'worlds', 'mission_world.sdf')
    bridge_config = os.path.join(pkg_share, 'config', 'gz_bridge.yaml')

    params_file = LaunchConfiguration('params_file')
    waypoint_file = LaunchConfiguration('waypoint_file')
    world_file = LaunchConfiguration('world_file')

    # Help Gazebo find our package's mesh files
    set_gz_resource_path = SetEnvironmentVariable(
        name='GZ_SIM_RESOURCE_PATH',
        value=os.path.dirname(pkg_share))

    # Start Gazebo with our world
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch',
                'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'--render-engine ogre -r -v 3 {default_world}'
        }.items()
    )

    # Bridge between Gazebo and ROS2
    gz_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='gz_ros_bridge',
        parameters=[{'config_file': bridge_config}],
        output='screen',
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file', default_value=default_params),
        DeclareLaunchArgument(
            'waypoint_file', default_value=default_waypoints),
        DeclareLaunchArgument(
            'world_file', default_value=default_world),

        set_gz_resource_path,
        gz_sim,
        gz_bridge,

        # Gamepad
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            parameters=[{'deadzone': 0.1, 'autorepeat_rate': 20.0}],
        ),

        # Our full nav stack — fake_odom is REMOVED (Gazebo replaces it)
        Node(
            package='auto_nav_pioneer_pkg',
            executable='safety_teleop_node',
            name='safety_teleop_node',
            parameters=[params_file],
            output='screen',
        ),
        Node(
            package='auto_nav_pioneer_pkg',
            executable='waypoint_manager_node',
            name='waypoint_manager_node',
            parameters=[params_file, {'waypoint_file': waypoint_file}],
            output='screen',
        ),
        Node(
            package='auto_nav_pioneer_pkg',
            executable='pure_pursuit_controller_node',
            name='pure_pursuit_controller_node',
            parameters=[params_file],
            output='screen',
        ),
    ])