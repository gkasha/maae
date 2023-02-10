// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Goal in the package ma_interfaces.
typedef struct ma_interfaces__msg__Goal
{
  rosidl_runtime_c__String name;
} ma_interfaces__msg__Goal;

// Struct for a sequence of ma_interfaces__msg__Goal.
typedef struct ma_interfaces__msg__Goal__Sequence
{
  ma_interfaces__msg__Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__Goal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_
