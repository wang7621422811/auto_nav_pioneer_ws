// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auto_nav_pioneer_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // cone_side
#include "rosidl_runtime_c/string_functions.h"  // cone_side

// forward declare type support functions


using _Waypoint__ros_msg_type = auto_nav_pioneer_interfaces__msg__Waypoint;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_serialize_auto_nav_pioneer_interfaces__msg__Waypoint(
  const auto_nav_pioneer_interfaces__msg__Waypoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: arrival_tolerance
  {
    cdr << ros_message->arrival_tolerance;
  }

  // Field name: requires_photo
  {
    cdr << (ros_message->requires_photo ? true : false);
  }

  // Field name: cone_side
  {
    const rosidl_runtime_c__String * str = &ros_message->cone_side;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_deserialize_auto_nav_pioneer_interfaces__msg__Waypoint(
  eprosima::fastcdr::Cdr & cdr,
  auto_nav_pioneer_interfaces__msg__Waypoint * ros_message)
{
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: arrival_tolerance
  {
    cdr >> ros_message->arrival_tolerance;
  }

  // Field name: requires_photo
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->requires_photo = tmp ? true : false;
  }

  // Field name: cone_side
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cone_side.data) {
      rosidl_runtime_c__String__init(&ros_message->cone_side);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cone_side,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cone_side'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t get_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Waypoint__ros_msg_type * ros_message = static_cast<const _Waypoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: arrival_tolerance
  {
    size_t item_size = sizeof(ros_message->arrival_tolerance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: requires_photo
  {
    size_t item_size = sizeof(ros_message->requires_photo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cone_side
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cone_side.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t max_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: arrival_tolerance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: requires_photo
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: cone_side
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = auto_nav_pioneer_interfaces__msg__Waypoint;
    is_plain =
      (
      offsetof(DataType, cone_side) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
bool cdr_serialize_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  const auto_nav_pioneer_interfaces__msg__Waypoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: arrival_tolerance
  {
    cdr << ros_message->arrival_tolerance;
  }

  // Field name: requires_photo
  {
    cdr << (ros_message->requires_photo ? true : false);
  }

  // Field name: cone_side
  {
    const rosidl_runtime_c__String * str = &ros_message->cone_side;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t get_serialized_size_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Waypoint__ros_msg_type * ros_message = static_cast<const _Waypoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: arrival_tolerance
  {
    size_t item_size = sizeof(ros_message->arrival_tolerance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: requires_photo
  {
    size_t item_size = sizeof(ros_message->requires_photo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cone_side
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cone_side.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auto_nav_pioneer_interfaces
size_t max_serialized_size_key_auto_nav_pioneer_interfaces__msg__Waypoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: arrival_tolerance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: requires_photo
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: cone_side
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = auto_nav_pioneer_interfaces__msg__Waypoint;
    is_plain =
      (
      offsetof(DataType, cone_side) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Waypoint__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const auto_nav_pioneer_interfaces__msg__Waypoint * ros_message = static_cast<const auto_nav_pioneer_interfaces__msg__Waypoint *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_auto_nav_pioneer_interfaces__msg__Waypoint(ros_message, cdr);
}

static bool _Waypoint__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  auto_nav_pioneer_interfaces__msg__Waypoint * ros_message = static_cast<auto_nav_pioneer_interfaces__msg__Waypoint *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_auto_nav_pioneer_interfaces__msg__Waypoint(cdr, ros_message);
}

static uint32_t _Waypoint__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
      untyped_ros_message, 0));
}

static size_t _Waypoint__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_auto_nav_pioneer_interfaces__msg__Waypoint(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Waypoint = {
  "auto_nav_pioneer_interfaces::msg",
  "Waypoint",
  _Waypoint__cdr_serialize,
  _Waypoint__cdr_deserialize,
  _Waypoint__get_serialized_size,
  _Waypoint__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Waypoint__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Waypoint,
  get_message_typesupport_handle_function,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_hash,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auto_nav_pioneer_interfaces, msg, Waypoint)() {
  return &_Waypoint__type_support;
}

#if defined(__cplusplus)
}
#endif
