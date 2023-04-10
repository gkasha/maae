// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ma_interfaces:msg/Bid.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ma_interfaces/msg/detail/bid__rosidl_typesupport_introspection_c.h"
#include "ma_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ma_interfaces/msg/detail/bid__functions.h"
#include "ma_interfaces/msg/detail/bid__struct.h"


// Include directives for member types
// Member `agent_id`
// Member `auction_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ma_interfaces__msg__Bid__init(message_memory);
}

void ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_fini_function(void * message_memory)
{
  ma_interfaces__msg__Bid__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_member_array[6] = {
  {
    "agent_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, agent_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "auction_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, auction_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "st",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, st),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "et",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, et),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Bid, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_members = {
  "ma_interfaces__msg",  // message namespace
  "Bid",  // message name
  6,  // number of fields
  sizeof(ma_interfaces__msg__Bid),
  ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_member_array,  // message members
  ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_init_function,  // function to initialize message memory (memory has to be allocated)
  ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_type_support_handle = {
  0,
  &ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ma_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ma_interfaces, msg, Bid)() {
  if (!ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_type_support_handle.typesupport_identifier) {
    ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ma_interfaces__msg__Bid__rosidl_typesupport_introspection_c__Bid_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
