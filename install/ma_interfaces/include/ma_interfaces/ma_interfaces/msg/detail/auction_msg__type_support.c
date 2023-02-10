// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ma_interfaces:msg/AuctionMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ma_interfaces/msg/detail/auction_msg__rosidl_typesupport_introspection_c.h"
#include "ma_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ma_interfaces/msg/detail/auction_msg__functions.h"
#include "ma_interfaces/msg/detail/auction_msg__struct.h"


// Include directives for member types
// Member `graph`
#include "ma_interfaces/msg/node.h"
// Member `graph`
#include "ma_interfaces/msg/detail/node__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ma_interfaces__msg__AuctionMsg__init(message_memory);
}

void ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_fini_function(void * message_memory)
{
  ma_interfaces__msg__AuctionMsg__fini(message_memory);
}

size_t ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__size_function__AuctionMsg__graph(
  const void * untyped_member)
{
  const ma_interfaces__msg__Node__Sequence * member =
    (const ma_interfaces__msg__Node__Sequence *)(untyped_member);
  return member->size;
}

const void * ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_const_function__AuctionMsg__graph(
  const void * untyped_member, size_t index)
{
  const ma_interfaces__msg__Node__Sequence * member =
    (const ma_interfaces__msg__Node__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_function__AuctionMsg__graph(
  void * untyped_member, size_t index)
{
  ma_interfaces__msg__Node__Sequence * member =
    (ma_interfaces__msg__Node__Sequence *)(untyped_member);
  return &member->data[index];
}

void ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__fetch_function__AuctionMsg__graph(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ma_interfaces__msg__Node * item =
    ((const ma_interfaces__msg__Node *)
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_const_function__AuctionMsg__graph(untyped_member, index));
  ma_interfaces__msg__Node * value =
    (ma_interfaces__msg__Node *)(untyped_value);
  *value = *item;
}

void ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__assign_function__AuctionMsg__graph(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ma_interfaces__msg__Node * item =
    ((ma_interfaces__msg__Node *)
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_function__AuctionMsg__graph(untyped_member, index));
  const ma_interfaces__msg__Node * value =
    (const ma_interfaces__msg__Node *)(untyped_value);
  *item = *value;
}

bool ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__resize_function__AuctionMsg__graph(
  void * untyped_member, size_t size)
{
  ma_interfaces__msg__Node__Sequence * member =
    (ma_interfaces__msg__Node__Sequence *)(untyped_member);
  ma_interfaces__msg__Node__Sequence__fini(member);
  return ma_interfaces__msg__Node__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_member_array[1] = {
  {
    "graph",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__AuctionMsg, graph),  // bytes offset in struct
    NULL,  // default value
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__size_function__AuctionMsg__graph,  // size() function pointer
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_const_function__AuctionMsg__graph,  // get_const(index) function pointer
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__get_function__AuctionMsg__graph,  // get(index) function pointer
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__fetch_function__AuctionMsg__graph,  // fetch(index, &value) function pointer
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__assign_function__AuctionMsg__graph,  // assign(index, value) function pointer
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__resize_function__AuctionMsg__graph  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_members = {
  "ma_interfaces__msg",  // message namespace
  "AuctionMsg",  // message name
  1,  // number of fields
  sizeof(ma_interfaces__msg__AuctionMsg),
  ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_member_array,  // message members
  ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_type_support_handle = {
  0,
  &ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ma_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ma_interfaces, msg, AuctionMsg)() {
  ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ma_interfaces, msg, Node)();
  if (!ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_type_support_handle.typesupport_identifier) {
    ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ma_interfaces__msg__AuctionMsg__rosidl_typesupport_introspection_c__AuctionMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
