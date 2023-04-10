// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/Bid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__BID__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__BID__STRUCT_H_

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
// Member 'auction_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Bid in the package ma_interfaces.
typedef struct ma_interfaces__msg__Bid
{
  rosidl_runtime_c__String agent_id;
  rosidl_runtime_c__String auction_id;
  int32_t status;
  double st;
  double et;
  double value;
} ma_interfaces__msg__Bid;

// Struct for a sequence of ma_interfaces__msg__Bid.
typedef struct ma_interfaces__msg__Bid__Sequence
{
  ma_interfaces__msg__Bid * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__Bid__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__BID__STRUCT_H_
