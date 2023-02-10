// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:srv/AuctionSrv.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_H_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_H_

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

/// Struct defined in srv/AuctionSrv in the package ma_interfaces.
typedef struct ma_interfaces__srv__AuctionSrv_Request
{
  rosidl_runtime_c__String name;
} ma_interfaces__srv__AuctionSrv_Request;

// Struct for a sequence of ma_interfaces__srv__AuctionSrv_Request.
typedef struct ma_interfaces__srv__AuctionSrv_Request__Sequence
{
  ma_interfaces__srv__AuctionSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__AuctionSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AuctionSrv in the package ma_interfaces.
typedef struct ma_interfaces__srv__AuctionSrv_Response
{
  rosidl_runtime_c__String status;
} ma_interfaces__srv__AuctionSrv_Response;

// Struct for a sequence of ma_interfaces__srv__AuctionSrv_Response.
typedef struct ma_interfaces__srv__AuctionSrv_Response__Sequence
{
  ma_interfaces__srv__AuctionSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__AuctionSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_H_
