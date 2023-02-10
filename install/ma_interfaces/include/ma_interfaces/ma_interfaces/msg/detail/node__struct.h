// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__NODE__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__NODE__STRUCT_H_

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
// Member 'children'
// Member 'next'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Node in the package ma_interfaces.
typedef struct ma_interfaces__msg__Node
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String__Sequence children;
  rosidl_runtime_c__String next;
  double value;
} ma_interfaces__msg__Node;

// Struct for a sequence of ma_interfaces__msg__Node.
typedef struct ma_interfaces__msg__Node__Sequence
{
  ma_interfaces__msg__Node * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__Node__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__NODE__STRUCT_H_
