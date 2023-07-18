// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/Slot.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'agent_id'
// Member 'owner_id'
// Member 'task_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Slot in the package ma_interfaces.
typedef struct ma_interfaces__msg__Slot
{
  rosidl_runtime_c__String agent_id;
  rosidl_runtime_c__String owner_id;
  rosidl_runtime_c__String task_id;
  double st;
  double et;
  double x1;
  double y1;
  double x2;
  double y2;
  double speed;
} ma_interfaces__msg__Slot;

// Struct for a sequence of ma_interfaces__msg__Slot.
typedef struct ma_interfaces__msg__Slot__Sequence
{
  ma_interfaces__msg__Slot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__Slot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_H_
