// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "auto_nav_pioneer_interfaces/msg/waypoint.hpp"


#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_nav_pioneer_interfaces
{

namespace msg
{

namespace builder
{

class Init_Waypoint_cone_side
{
public:
  explicit Init_Waypoint_cone_side(::auto_nav_pioneer_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  ::auto_nav_pioneer_interfaces::msg::Waypoint cone_side(::auto_nav_pioneer_interfaces::msg::Waypoint::_cone_side_type arg)
  {
    msg_.cone_side = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_requires_photo
{
public:
  explicit Init_Waypoint_requires_photo(::auto_nav_pioneer_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_cone_side requires_photo(::auto_nav_pioneer_interfaces::msg::Waypoint::_requires_photo_type arg)
  {
    msg_.requires_photo = std::move(arg);
    return Init_Waypoint_cone_side(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_arrival_tolerance
{
public:
  explicit Init_Waypoint_arrival_tolerance(::auto_nav_pioneer_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_requires_photo arrival_tolerance(::auto_nav_pioneer_interfaces::msg::Waypoint::_arrival_tolerance_type arg)
  {
    msg_.arrival_tolerance = std::move(arg);
    return Init_Waypoint_requires_photo(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_y
{
public:
  explicit Init_Waypoint_y(::auto_nav_pioneer_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_arrival_tolerance y(::auto_nav_pioneer_interfaces::msg::Waypoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Waypoint_arrival_tolerance(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_x
{
public:
  explicit Init_Waypoint_x(::auto_nav_pioneer_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_y x(::auto_nav_pioneer_interfaces::msg::Waypoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Waypoint_y(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_id
{
public:
  Init_Waypoint_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Waypoint_x id(::auto_nav_pioneer_interfaces::msg::Waypoint::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Waypoint_x(msg_);
  }

private:
  ::auto_nav_pioneer_interfaces::msg::Waypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_nav_pioneer_interfaces::msg::Waypoint>()
{
  return auto_nav_pioneer_interfaces::msg::builder::Init_Waypoint_id();
}

}  // namespace auto_nav_pioneer_interfaces

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
