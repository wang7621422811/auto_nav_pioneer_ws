// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__rosidl_typesupport_fastrtps_cpp.hpp"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__functions.h"
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace auto_nav_pioneer_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
cdr_serialize(
  const auto_nav_pioneer_interfaces::msg::Waypoint & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;

  // Member: x
  cdr << ros_message.x;

  // Member: y
  cdr << ros_message.y;

  // Member: arrival_tolerance
  cdr << ros_message.arrival_tolerance;

  // Member: requires_photo
  cdr << (ros_message.requires_photo ? true : false);

  // Member: cone_side
  cdr << ros_message.cone_side;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  auto_nav_pioneer_interfaces::msg::Waypoint & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: x
  cdr >> ros_message.x;

  // Member: y
  cdr >> ros_message.y;

  // Member: arrival_tolerance
  cdr >> ros_message.arrival_tolerance;

  // Member: requires_photo
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.requires_photo = tmp ? true : false;
  }

  // Member: cone_side
  cdr >> ros_message.cone_side;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
get_serialized_size(
  const auto_nav_pioneer_interfaces::msg::Waypoint & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: arrival_tolerance
  {
    size_t item_size = sizeof(ros_message.arrival_tolerance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: requires_photo
  {
    size_t item_size = sizeof(ros_message.requires_photo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: cone_side
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.cone_side.size() + 1);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
max_serialized_size_Waypoint(
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

  // Member: id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: arrival_tolerance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: requires_photo
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: cone_side
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
    using DataType = auto_nav_pioneer_interfaces::msg::Waypoint;
    is_plain =
      (
      offsetof(DataType, cone_side) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
cdr_serialize_key(
  const auto_nav_pioneer_interfaces::msg::Waypoint & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;

  // Member: x
  cdr << ros_message.x;

  // Member: y
  cdr << ros_message.y;

  // Member: arrival_tolerance
  cdr << ros_message.arrival_tolerance;

  // Member: requires_photo
  cdr << (ros_message.requires_photo ? true : false);

  // Member: cone_side
  cdr << ros_message.cone_side;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
get_serialized_size_key(
  const auto_nav_pioneer_interfaces::msg::Waypoint & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: arrival_tolerance
  {
    size_t item_size = sizeof(ros_message.arrival_tolerance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: requires_photo
  {
    size_t item_size = sizeof(ros_message.requires_photo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: cone_side
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.cone_side.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auto_nav_pioneer_interfaces
max_serialized_size_key_Waypoint(
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

  // Member: id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: arrival_tolerance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: requires_photo
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cone_side
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
    using DataType = auto_nav_pioneer_interfaces::msg::Waypoint;
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
  auto typed_message =
    static_cast<const auto_nav_pioneer_interfaces::msg::Waypoint *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Waypoint__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<auto_nav_pioneer_interfaces::msg::Waypoint *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Waypoint__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const auto_nav_pioneer_interfaces::msg::Waypoint *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Waypoint__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Waypoint(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Waypoint__callbacks = {
  "auto_nav_pioneer_interfaces::msg",
  "Waypoint",
  _Waypoint__cdr_serialize,
  _Waypoint__cdr_deserialize,
  _Waypoint__get_serialized_size,
  _Waypoint__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Waypoint__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Waypoint__callbacks,
  get_message_typesupport_handle_function,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_hash,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description,
  &auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace auto_nav_pioneer_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_auto_nav_pioneer_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<auto_nav_pioneer_interfaces::msg::Waypoint>()
{
  return &auto_nav_pioneer_interfaces::msg::typesupport_fastrtps_cpp::_Waypoint__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, auto_nav_pioneer_interfaces, msg, Waypoint)() {
  return &auto_nav_pioneer_interfaces::msg::typesupport_fastrtps_cpp::_Waypoint__handle;
}

#ifdef __cplusplus
}
#endif
