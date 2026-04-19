// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__rosidl_typesupport_introspection_c.h"
#include "auto_nav_pioneer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__functions.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.h"


// Include directives for member types
// Member `cone_side`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auto_nav_pioneer_interfaces__msg__Waypoint__init(message_memory);
}

void auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_fini_function(void * message_memory)
{
  auto_nav_pioneer_interfaces__msg__Waypoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[6] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arrival_tolerance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, arrival_tolerance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "requires_photo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, requires_photo),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_side",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_nav_pioneer_interfaces__msg__Waypoint, cone_side),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_members = {
  "auto_nav_pioneer_interfaces__msg",  // message namespace
  "Waypoint",  // message name
  6,  // number of fields
  sizeof(auto_nav_pioneer_interfaces__msg__Waypoint),
  false,  // has_any_key_member_
  auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array,  // message members
  auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_init_function,  // function to initialize message memory (memory has to be allocated)
  auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle = {
  0,
  &auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_members,
  get_message_typesupport_handle_function,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_hash,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auto_nav_pioneer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_nav_pioneer_interfaces, msg, Waypoint)() {
  if (!auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle.typesupport_identifier) {
    auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &auto_nav_pioneer_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
