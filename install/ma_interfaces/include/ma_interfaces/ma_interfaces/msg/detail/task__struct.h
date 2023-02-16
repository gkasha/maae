// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'owner'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Task in the package ma_interfaces.
typedef struct ma_interfaces__msg__Task
{
  rosidl_runtime_c__String id;
  rosidl_runtime_c__String owner;
  int64_t duration;
  int64_t value;
} ma_interfaces__msg__Task;

// Struct for a sequence of ma_interfaces__msg__Task.
typedef struct ma_interfaces__msg__Task__Sequence
{
  ma_interfaces__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
