// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/ActionDispatch.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'action_id'
// Member 'agent_id'
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ActionDispatch in the package ma_interfaces.
typedef struct ma_interfaces__msg__ActionDispatch
{
  rosidl_runtime_c__String action_id;
  rosidl_runtime_c__String agent_id;
  rosidl_runtime_c__String name;
  float duration;
  float start_time;
} ma_interfaces__msg__ActionDispatch;

// Struct for a sequence of ma_interfaces__msg__ActionDispatch.
typedef struct ma_interfaces__msg__ActionDispatch__Sequence
{
  ma_interfaces__msg__ActionDispatch * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__ActionDispatch__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_H_
