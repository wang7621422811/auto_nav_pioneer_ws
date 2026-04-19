// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_nav_pioneer_interfaces:msg/WaypointList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "auto_nav_pioneer_interfaces/msg/waypoint_list.h"


#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT_LIST__STRUCT_H_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'waypoints'
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.h"

/// Struct defined in msg/WaypointList in the package auto_nav_pioneer_interfaces.
/**
  * An ordered list of waypoints defining a mission.
 */
typedef struct auto_nav_pioneer_interfaces__msg__WaypointList
{
  std_msgs__msg__Header header;
  auto_nav_pioneer_interfaces__msg__Waypoint__Sequence waypoints;
} auto_nav_pioneer_interfaces__msg__WaypointList;

// Struct for a sequence of auto_nav_pioneer_interfaces__msg__WaypointList.
typedef struct auto_nav_pioneer_interfaces__msg__WaypointList__Sequence
{
  auto_nav_pioneer_interfaces__msg__WaypointList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_nav_pioneer_interfaces__msg__WaypointList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT_LIST__STRUCT_H_
