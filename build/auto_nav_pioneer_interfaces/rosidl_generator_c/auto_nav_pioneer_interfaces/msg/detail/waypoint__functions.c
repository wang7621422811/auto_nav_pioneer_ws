// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cone_side`
#include "rosidl_runtime_c/string_functions.h"

bool
auto_nav_pioneer_interfaces__msg__Waypoint__init(auto_nav_pioneer_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // x
  // y
  // arrival_tolerance
  // requires_photo
  // cone_side
  if (!rosidl_runtime_c__String__init(&msg->cone_side)) {
    auto_nav_pioneer_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  return true;
}

void
auto_nav_pioneer_interfaces__msg__Waypoint__fini(auto_nav_pioneer_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return;
  }
  // id
  // x
  // y
  // arrival_tolerance
  // requires_photo
  // cone_side
  rosidl_runtime_c__String__fini(&msg->cone_side);
}

bool
auto_nav_pioneer_interfaces__msg__Waypoint__are_equal(const auto_nav_pioneer_interfaces__msg__Waypoint * lhs, const auto_nav_pioneer_interfaces__msg__Waypoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // arrival_tolerance
  if (lhs->arrival_tolerance != rhs->arrival_tolerance) {
    return false;
  }
  // requires_photo
  if (lhs->requires_photo != rhs->requires_photo) {
    return false;
  }
  // cone_side
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cone_side), &(rhs->cone_side)))
  {
    return false;
  }
  return true;
}

bool
auto_nav_pioneer_interfaces__msg__Waypoint__copy(
  const auto_nav_pioneer_interfaces__msg__Waypoint * input,
  auto_nav_pioneer_interfaces__msg__Waypoint * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // arrival_tolerance
  output->arrival_tolerance = input->arrival_tolerance;
  // requires_photo
  output->requires_photo = input->requires_photo;
  // cone_side
  if (!rosidl_runtime_c__String__copy(
      &(input->cone_side), &(output->cone_side)))
  {
    return false;
  }
  return true;
}

auto_nav_pioneer_interfaces__msg__Waypoint *
auto_nav_pioneer_interfaces__msg__Waypoint__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_nav_pioneer_interfaces__msg__Waypoint * msg = (auto_nav_pioneer_interfaces__msg__Waypoint *)allocator.allocate(sizeof(auto_nav_pioneer_interfaces__msg__Waypoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auto_nav_pioneer_interfaces__msg__Waypoint));
  bool success = auto_nav_pioneer_interfaces__msg__Waypoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auto_nav_pioneer_interfaces__msg__Waypoint__destroy(auto_nav_pioneer_interfaces__msg__Waypoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auto_nav_pioneer_interfaces__msg__Waypoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__init(auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_nav_pioneer_interfaces__msg__Waypoint * data = NULL;

  if (size) {
    data = (auto_nav_pioneer_interfaces__msg__Waypoint *)allocator.zero_allocate(size, sizeof(auto_nav_pioneer_interfaces__msg__Waypoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auto_nav_pioneer_interfaces__msg__Waypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auto_nav_pioneer_interfaces__msg__Waypoint__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__fini(auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auto_nav_pioneer_interfaces__msg__Waypoint__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

auto_nav_pioneer_interfaces__msg__Waypoint__Sequence *
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * array = (auto_nav_pioneer_interfaces__msg__Waypoint__Sequence *)allocator.allocate(sizeof(auto_nav_pioneer_interfaces__msg__Waypoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__destroy(auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__are_equal(const auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * lhs, const auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auto_nav_pioneer_interfaces__msg__Waypoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auto_nav_pioneer_interfaces__msg__Waypoint__Sequence__copy(
  const auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * input,
  auto_nav_pioneer_interfaces__msg__Waypoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auto_nav_pioneer_interfaces__msg__Waypoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auto_nav_pioneer_interfaces__msg__Waypoint * data =
      (auto_nav_pioneer_interfaces__msg__Waypoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auto_nav_pioneer_interfaces__msg__Waypoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auto_nav_pioneer_interfaces__msg__Waypoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auto_nav_pioneer_interfaces__msg__Waypoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
