// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "auto_nav_pioneer_interfaces/msg/waypoint.hpp"


#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace auto_nav_pioneer_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Waypoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: arrival_tolerance
  {
    out << "arrival_tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.arrival_tolerance, out);
    out << ", ";
  }

  // member: requires_photo
  {
    out << "requires_photo: ";
    rosidl_generator_traits::value_to_yaml(msg.requires_photo, out);
    out << ", ";
  }

  // member: cone_side
  {
    out << "cone_side: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_side, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: arrival_tolerance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arrival_tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.arrival_tolerance, out);
    out << "\n";
  }

  // member: requires_photo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "requires_photo: ";
    rosidl_generator_traits::value_to_yaml(msg.requires_photo, out);
    out << "\n";
  }

  // member: cone_side
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_side: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_side, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Waypoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace auto_nav_pioneer_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use auto_nav_pioneer_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auto_nav_pioneer_interfaces::msg::Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  auto_nav_pioneer_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auto_nav_pioneer_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const auto_nav_pioneer_interfaces::msg::Waypoint & msg)
{
  return auto_nav_pioneer_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<auto_nav_pioneer_interfaces::msg::Waypoint>()
{
  return "auto_nav_pioneer_interfaces::msg::Waypoint";
}

template<>
inline const char * name<auto_nav_pioneer_interfaces::msg::Waypoint>()
{
  return "auto_nav_pioneer_interfaces/msg/Waypoint";
}

template<>
struct has_fixed_size<auto_nav_pioneer_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<auto_nav_pioneer_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<auto_nav_pioneer_interfaces::msg::Waypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
