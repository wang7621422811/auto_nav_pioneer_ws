// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "auto_nav_pioneer_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_serialize_auto_nav_pioneer_interfaces__msg__Waypoint(
  const auto_nav_pioneer_interfaces__msg__Waypoint * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_deserialize_auto_nav_pioneer_interfaces__msg__Waypoint(
  eprosima::fastcdr::Cdr &,
  auto_nav_pioneer_interfaces__msg__Waypoint * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t get_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t max_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_serialize_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  const auto_nav_pioneer_interfaces__msg__Waypoint * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t get_serialized_size_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t max_serialized_size_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auto_nav_pioneer_interfaces, msg, Waypoint)();

#ifdef __cplusplus
}
#endif

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
