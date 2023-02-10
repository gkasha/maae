// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:msg/AuctionMsg.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__STRUCT_H_
#define MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'graph'
#include "ma_interfaces/msg/detail/node__struct.h"

/// Struct defined in msg/AuctionMsg in the package ma_interfaces.
typedef struct ma_interfaces__msg__AuctionMsg
{
  ma_interfaces__msg__Node__Sequence graph;
} ma_interfaces__msg__AuctionMsg;

// Struct for a sequence of ma_interfaces__msg__AuctionMsg.
typedef struct ma_interfaces__msg__AuctionMsg__Sequence
{
  ma_interfaces__msg__AuctionMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__msg__AuctionMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__AUCTION_MSG__STRUCT_H_
