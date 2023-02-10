// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:srv/GetBid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_H_
#define MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_H_

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

/// Struct defined in srv/GetBid in the package ma_interfaces.
typedef struct ma_interfaces__srv__GetBid_Request
{
  ma_interfaces__msg__Task t;
} ma_interfaces__srv__GetBid_Request;

// Struct for a sequence of ma_interfaces__srv__GetBid_Request.
typedef struct ma_interfaces__srv__GetBid_Request__Sequence
{
  ma_interfaces__srv__GetBid_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__GetBid_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'b'
#include "ma_interfaces/msg/detail/bid__struct.h"

/// Struct defined in srv/GetBid in the package ma_interfaces.
typedef struct ma_interfaces__srv__GetBid_Response
{
  ma_interfaces__msg__Bid b;
} ma_interfaces__srv__GetBid_Response;

// Struct for a sequence of ma_interfaces__srv__GetBid_Response.
typedef struct ma_interfaces__srv__GetBid_Response__Sequence
{
  ma_interfaces__srv__GetBid_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__GetBid_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__SRV__DETAIL__GET_BID__STRUCT_H_
