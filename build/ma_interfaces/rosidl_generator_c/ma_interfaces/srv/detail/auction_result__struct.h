// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_H_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 't'
#include "ma_interfaces/msg/detail/task__struct.h"
// Member 'b'
#include "ma_interfaces/msg/detail/bid__struct.h"

/// Struct defined in srv/AuctionResult in the package ma_interfaces.
typedef struct ma_interfaces__srv__AuctionResult_Request
{
  ma_interfaces__msg__Task t;
  ma_interfaces__msg__Bid b;
} ma_interfaces__srv__AuctionResult_Request;

// Struct for a sequence of ma_interfaces__srv__AuctionResult_Request.
typedef struct ma_interfaces__srv__AuctionResult_Request__Sequence
{
  ma_interfaces__srv__AuctionResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__AuctionResult_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AuctionResult in the package ma_interfaces.
typedef struct ma_interfaces__srv__AuctionResult_Response
{
  uint8_t structure_needs_at_least_one_member;
} ma_interfaces__srv__AuctionResult_Response;

// Struct for a sequence of ma_interfaces__srv__AuctionResult_Response.
typedef struct ma_interfaces__srv__AuctionResult_Response__Sequence
{
  ma_interfaces__srv__AuctionResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__AuctionResult_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_RESULT__STRUCT_H_
