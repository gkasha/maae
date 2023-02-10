// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ma_interfaces:srv/GetGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__GET_GOAL__STRUCT_H_
#define MA_INTERFACES__SRV__DETAIL__GET_GOAL__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetGoal in the package ma_interfaces.
typedef struct ma_interfaces__srv__GetGoal_Request
{
  rosidl_runtime_c__String id;
} ma_interfaces__srv__GetGoal_Request;

// Struct for a sequence of ma_interfaces__srv__GetGoal_Request.
typedef struct ma_interfaces__srv__GetGoal_Request__Sequence
{
  ma_interfaces__srv__GetGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__GetGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'g'
#include "ma_interfaces/msg/detail/goal__struct.h"

/// Struct defined in srv/GetGoal in the package ma_interfaces.
typedef struct ma_interfaces__srv__GetGoal_Response
{
  ma_interfaces__msg__Goal g;
  int64_t num_agents;
} ma_interfaces__srv__GetGoal_Response;

// Struct for a sequence of ma_interfaces__srv__GetGoal_Response.
typedef struct ma_interfaces__srv__GetGoal_Response__Sequence
{
  ma_interfaces__srv__GetGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ma_interfaces__srv__GetGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__SRV__DETAIL__GET_GOAL__STRUCT_H_
