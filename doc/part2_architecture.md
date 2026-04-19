# AUTO4508 Part 2 Architecture

## 1. Design target

Part 2 needs one system that can:

1. Follow a GPS waypoint list.
2. Avoid collisions with lidar.
3. Detect the orange waypoint cone and keep it on the robot's right.
4. Weave through cones between waypoint 1 and waypoint 2.
5. Detect an extra coloured object near each waypoint, classify its shape, and estimate its distance from the waypoint cone.
6. Support manual/auto switching with a Bluetooth controller.
7. Stop immediately when the dead-man trigger is released.
8. Save a journey summary at mission completion.

The safest way to build this is a layered architecture:

1. Hardware/simulator drivers
2. Robot interface abstraction
3. Perception
4. Navigation and behaviours
5. Mission state machine
6. Logging and reporting

## 2. Recommended ROS2 package layout

Create a `src/` folder and split the system into these packages:

### `pioneer_description`

Purpose:
- URDF/Xacro
- sensor mounting frames
- Gazebo plugins

Owns:
- `urdf/`
- `meshes/`
- `config/robot_geometry.yaml`
- `launch/view_robot.launch.py`

Publishes:
- TF via `robot_state_publisher`

Subscribes:
- none

### `pioneer_gazebo`

Purpose:
- Gazebo world, spawn, simulated sensors, simulation launch

Owns:
- `worlds/james_oval.world`
- `launch/sim_bringup.launch.py`
- sensor plugin configs

Publishes:
- simulated `/scan`
- simulated camera topics
- simulated odometry if using Gazebo diff-drive/skid-steer plugin

Subscribes:
- `/cmd_vel`

### `pioneer_bringup`

Purpose:
- one place to start either simulation or real robot stack
- choose drivers by launch argument

Owns:
- `launch/sim.launch.py`
- `launch/robot.launch.py`
- `launch/navigation.launch.py`
- common parameter YAML files

Publishes:
- none directly

Subscribes:
- none directly

### `pioneer_base`

Purpose:
- unify base motion interface for simulation and real Pioneer
- expose a consistent odom/cmd_vel API

Owns:
- adapter node from Gazebo or `rosaria` into common topics
- velocity limiting and watchdog

Publishes:
- `/odom`
- `/joint_states` if needed
- `/base/status`

Subscribes:
- `/cmd_vel`
- driver-specific status topics

Notes:
- In simulation this can be mostly pass-through.
- On hardware this wraps `AriaCoda` or `rosaria`.

### `pioneer_localization`

Purpose:
- convert GPS, IMU and wheel odometry into a stable local frame
- provide `map -> odom -> base_link`

Owns:
- EKF configuration
- GPS to local ENU conversion
- waypoint frame utilities

Publishes:
- `/odometry/filtered`
- `/local_xy_origin`
- TF `map -> odom`

Subscribes:
- `/gps/fix`
- `/imu/data`
- `/odom`

Notes:
- In Gazebo, fake GPS can be generated from ground-truth pose.
- On hardware this is where GPS noise handling belongs.

### `pioneer_perception`

Purpose:
- vision and lidar perception for cones and coloured objects

Owns:
- orange cone detector
- coloured object detector
- shape classifier
- distance estimator

Publishes:
- `/perception/waypoint_cone`
- `/perception/target_object`
- `/perception/debug_image`

Subscribes:
- camera image
- camera info
- depth image or point cloud if used
- `/scan` if lidar assists detection

Output messages should include:
- detection flag
- bearing relative to robot
- range estimate
- bbox or contour
- class label
- confidence

### `pioneer_navigation`

Purpose:
- move robot to goals while avoiding obstacles

Owns:
- GPS waypoint follower
- local planner wrapper
- cone-right-side approach controller
- slalom behaviour

Publishes:
- `/cmd_vel_nav`
- `/nav/current_goal`
- `/nav/status`

Subscribes:
- `/odometry/filtered`
- `/scan`
- `/perception/waypoint_cone`
- `/mission/current_waypoint`

Internal modules:
- `gps_waypoint_follower`
- `obstacle_avoider`
- `right_side_approach`
- `slalom_controller`

Notes:
- Keep the interface simple: navigation outputs motion commands, but does not decide mission order.

### `pioneer_teleop`

Purpose:
- controller input, manual drive, mode switching, dead-man safety

Owns:
- joystick mapping
- manual drive conversion
- mode service or topic

Publishes:
- `/cmd_vel_teleop`
- `/teleop/enable_auto`
- `/teleop/enable_manual`
- `/safety/deadman_ok`

Subscribes:
- `/joy`

Rules:
- `X` enters auto mode
- `O` enters manual mode
- rear trigger released => zero velocity immediately

### `pioneer_mission`

Purpose:
- top-level state machine for Part 2

Owns:
- waypoint list handling
- mission progress
- task sequencing
- return-to-home logic

Publishes:
- `/mission/current_waypoint`
- `/mission/state`
- `/mission/events`

Subscribes:
- `/teleop/enable_auto`
- `/teleop/enable_manual`
- `/safety/deadman_ok`
- `/nav/status`
- `/perception/waypoint_cone`
- `/perception/target_object`

Suggested states:
- `IDLE`
- `MANUAL`
- `AUTO_TRANSIT`
- `AUTO_APPROACH_CONE`
- `AUTO_CAPTURE_MARKER`
- `AUTO_SEARCH_OBJECT`
- `AUTO_SLALOM`
- `AUTO_RETURN_HOME`
- `MISSION_COMPLETE`
- `SAFE_STOP`

### `pioneer_logging`

Purpose:
- save mission artifacts and produce summary

Owns:
- path logger
- image capture service
- event logger
- summary generator

Publishes:
- optional `/mission/summary_ready`

Subscribes:
- `/mission/state`
- `/odometry/filtered`
- `/gps/fix`
- perception results

Outputs:
- `logs/<run_id>/trajectory.csv`
- `logs/<run_id>/events.json`
- `logs/<run_id>/images/`
- `logs/<run_id>/summary.md`

## 3. Topic-level architecture

Use this command chain model:

1. `pioneer_navigation` publishes `/cmd_vel_nav`
2. `pioneer_teleop` publishes `/cmd_vel_teleop`
3. a small mux node selects one source and publishes final `/cmd_vel`
4. `pioneer_base` sends `/cmd_vel` to simulator or hardware

Recommended arbitration rules:

1. If dead-man is false, output zero velocity.
2. If mode is manual, use `/cmd_vel_teleop`.
3. If mode is auto and dead-man is true, use `/cmd_vel_nav`.
4. Any safety stop overrides everything with zero velocity.

This prevents the mission logic from talking directly to motor drivers.

## 4. Suggested custom messages

Create one interface package:

### `pioneer_interfaces`

Add messages like:

- `ConeDetection.msg`
- `ObjectDetection.msg`
- `MissionState.msg`
- `WaypointTask.msg`
- `JourneyEvent.msg`

Recommended `ConeDetection.msg` fields:

- `std_msgs/Header header`
- `bool detected`
- `float32 range_m`
- `float32 bearing_rad`
- `bool cone_on_right`
- `float32 confidence`

Recommended `ObjectDetection.msg` fields:

- `std_msgs/Header header`
- `bool detected`
- `string color`
- `string shape`
- `float32 range_from_robot_m`
- `float32 distance_from_waypoint_m`
- `float32 bearing_rad`
- `float32 confidence`

## 5. State machine split

Do not put all logic in one node. Split responsibility like this:

### Mission manager decides:
- which waypoint is active
- whether the robot should travel, inspect, slalom, or return home
- whether the current task is complete

### Navigation decides:
- how to physically move toward the current target
- how to avoid obstacles while moving
- how to keep the cone on the right during final approach

### Perception decides:
- whether the cone is visible
- whether the extra object is visible
- the object's shape and estimated distance

### Teleop/safety decides:
- whether autonomous motion is even allowed right now

This separation is important because the same navigation and perception blocks will be reused in Part 3.

## 6. Simulation-first implementation order

Implement in this order:

1. `pioneer_description`
2. `pioneer_gazebo`
3. `pioneer_interfaces`
4. `pioneer_base`
5. `pioneer_teleop`
6. `pioneer_localization`
7. `pioneer_navigation`
8. `pioneer_perception`
9. `pioneer_mission`
10. `pioneer_logging`
11. `pioneer_bringup`

Reason:
- first make the robot exist
- then make it move safely
- then localize
- then navigate
- then perceive
- then coordinate mission logic
- then save outputs

## 7. Minimal deliverable for the first build

Before doing full Part 2, get this minimum system running:

1. Gazebo robot spawns correctly.
2. `/cmd_vel` drives the robot.
3. `/scan` and camera image topics are alive.
4. joystick can switch manual/auto.
5. dead-man release stops the robot.
6. a list of local 2D waypoints can be followed in simulation.
7. lidar local avoidance prevents simple collisions.

Only after that should you add:

1. GPS handling
2. cone-right-side final approach
3. slalom
4. object classification
5. reporting

## 8. Real robot migration notes

Keep these interfaces identical between simulation and hardware:

- final `/cmd_vel`
- `/odom`
- `/scan`
- camera topics
- `/imu/data`
- `/gps/fix`
- TF tree

If you preserve those interfaces, migration becomes mostly a launch problem instead of a rewrite.

For the real Pioneer:

1. replace simulated base with `AriaCoda` or `rosaria`
2. replace simulated lidar with SICK or Lakibeam driver
3. replace simulated camera with OAK-D ROS driver
4. replace fake GPS with real GPS driver
5. keep mission, perception and most navigation nodes unchanged

## 9. Workspace shape

Recommended tree:

```text
auto_nav_pioneer_ws/
  src/
    pioneer_description/
    pioneer_gazebo/
    pioneer_bringup/
    pioneer_base/
    pioneer_localization/
    pioneer_navigation/
    pioneer_perception/
    pioneer_teleop/
    pioneer_mission/
    pioneer_logging/
    pioneer_interfaces/
  config/
  doc/
  worlds/
```

## 10. What to build next

The next concrete step should be:

1. create `src/`
2. create `pioneer_interfaces`
3. create `pioneer_description`
4. move the current URDF into `pioneer_description`
5. create one minimal `sim_bringup.launch.py`

That gives you a clean base to start actual implementation.
