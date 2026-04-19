// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from auto_nav_pioneer_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#include "auto_nav_pioneer_interfaces/msg/detail/waypoint__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_auto_nav_pioneer_interfaces
const rosidl_type_hash_t *
auto_nav_pioneer_interfaces__msg__Waypoint__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbf, 0x32, 0xbc, 0xb1, 0x8f, 0x73, 0xf2, 0x24,
      0x3a, 0xe8, 0x3f, 0xb8, 0xc6, 0x08, 0x01, 0xa2,
      0xc9, 0xdf, 0x81, 0x18, 0x79, 0x5c, 0xfb, 0x5b,
      0xbd, 0xc2, 0x56, 0x23, 0x12, 0xa1, 0x26, 0x4e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char auto_nav_pioneer_interfaces__msg__Waypoint__TYPE_NAME[] = "auto_nav_pioneer_interfaces/msg/Waypoint";

// Define type names, field names, and default values
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__id[] = "id";
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__x[] = "x";
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__y[] = "y";
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__arrival_tolerance[] = "arrival_tolerance";
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__requires_photo[] = "requires_photo";
static char auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__cone_side[] = "cone_side";

static rosidl_runtime_c__type_description__Field auto_nav_pioneer_interfaces__msg__Waypoint__FIELDS[] = {
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__arrival_tolerance, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__requires_photo, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {auto_nav_pioneer_interfaces__msg__Waypoint__FIELD_NAME__cone_side, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {auto_nav_pioneer_interfaces__msg__Waypoint__TYPE_NAME, 40, 40},
      {auto_nav_pioneer_interfaces__msg__Waypoint__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# A single navigation target for the Pioneer robot.\n"
  "# Coordinates are in the local 'odom' frame (meters).\n"
  "\n"
  "uint32 id                          # Waypoint sequence number (0, 1, 2...)\n"
  "float64 x                          # Target position X (meters)\n"
  "float64 y                          # Target position Y (meters)\n"
  "float64 arrival_tolerance          # Accept as \"reached\" within this radius (meters)\n"
  "bool requires_photo                # Take a photo when arriving\n"
  "string cone_side                   # \"left\" or \"right\" \\xe2\\x80\\x94 which side to leave the cone";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
auto_nav_pioneer_interfaces__msg__Waypoint__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {auto_nav_pioneer_interfaces__msg__Waypoint__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 544, 544},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
auto_nav_pioneer_interfaces__msg__Waypoint__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *auto_nav_pioneer_interfaces__msg__Waypoint__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
