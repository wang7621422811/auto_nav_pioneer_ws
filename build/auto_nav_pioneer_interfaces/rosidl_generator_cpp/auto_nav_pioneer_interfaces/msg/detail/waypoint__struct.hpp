// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "auto_nav_pioneer_interfaces/msg/waypoint.hpp"


#ifndef AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
#define AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auto_nav_pioneer_interfaces__msg__Waypoint __attribute__((deprecated))
#else
# define DEPRECATED__auto_nav_pioneer_interfaces__msg__Waypoint __declspec(deprecated)
#endif

namespace auto_nav_pioneer_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Waypoint_
{
  using Type = Waypoint_<ContainerAllocator>;

  explicit Waypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->x = 0.0;
      this->y = 0.0;
      this->arrival_tolerance = 0.0;
      this->requires_photo = false;
      this->cone_side = "";
    }
  }

  explicit Waypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cone_side(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->x = 0.0;
      this->y = 0.0;
      this->arrival_tolerance = 0.0;
      this->requires_photo = false;
      this->cone_side = "";
    }
  }

  // field types and members
  using _id_type =
    uint32_t;
  _id_type id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _arrival_tolerance_type =
    double;
  _arrival_tolerance_type arrival_tolerance;
  using _requires_photo_type =
    bool;
  _requires_photo_type requires_photo;
  using _cone_side_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cone_side_type cone_side;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__arrival_tolerance(
    const double & _arg)
  {
    this->arrival_tolerance = _arg;
    return *this;
  }
  Type & set__requires_photo(
    const bool & _arg)
  {
    this->requires_photo = _arg;
    return *this;
  }
  Type & set__cone_side(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cone_side = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auto_nav_pioneer_interfaces__msg__Waypoint
    std::shared_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auto_nav_pioneer_interfaces__msg__Waypoint
    std::shared_ptr<auto_nav_pioneer_interfaces::msg::Waypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Waypoint_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->arrival_tolerance != other.arrival_tolerance) {
      return false;
    }
    if (this->requires_photo != other.requires_photo) {
      return false;
    }
    if (this->cone_side != other.cone_side) {
      return false;
    }
    return true;
  }
  bool operator!=(const Waypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Waypoint_

// alias to use template instance with default allocator
using Waypoint =
  auto_nav_pioneer_interfaces::msg::Waypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auto_nav_pioneer_interfaces

#endif  // AUTO_NAV_PIONEER_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
