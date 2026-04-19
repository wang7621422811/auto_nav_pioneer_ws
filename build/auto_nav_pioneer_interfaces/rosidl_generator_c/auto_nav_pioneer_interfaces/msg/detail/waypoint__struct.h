// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "auto_nav_pioneer_interfaces/msg/waypoint.h"


#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'cone_side'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Waypoint in the package auto_nav_pioneer_interfaces.
/**
  * A single navigation target for the Pioneer robot.
  * Coordinates are in the local 'odom' frame (meters).
 */
typedef struct auto_nav_pioneer_interfaces__msg__Waypoint
{
  /// Waypoint sequence number (0, 1, 2...)
  uint32_t id;
  /// Target position X (meters)
  double x;
  /// Target position Y (meters)
  double y;
  /// Accept as "reached" within this radius (meters)
  double arrival_tolerance;
  /// Take a photo when arriving
  bool requires_photo;
  /// "left" or "right" — which side to leave the cone
  rosidl_runtime_c__String cone_side;
} auto_nav_pioneer_interfaces__msg__Waypoint;

// Struct for a sequence of auto_nav_pioneer_interfaces__msg__Waypoint.
typedef struct auto_nav_pioneer_interfaces__msg__Waypoint__Sequence
{
  auto_nav_pioneer_interfaces__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_nav_pioneer_interfaces__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_
