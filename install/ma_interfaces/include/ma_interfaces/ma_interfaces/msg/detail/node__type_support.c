// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ma_interfaces:msg/Node.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ma_interfaces/msg/detail/node__rosidl_typesupport_introspection_c.h"
#include "ma_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ma_interfaces/msg/detail/node__functions.h"
#include "ma_interfaces/msg/detail/node__struct.h"


// Include directives for member types
// Member `name`
// Member `children`
// Member `next`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ma_interfaces__msg__Node__init(message_memory);
}

void ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_fini_function(void * message_memory)
{
  ma_interfaces__msg__Node__fini(message_memory);
}

size_t ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__size_function__Node__children(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__children(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__children(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__fetch_function__Node__children(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__children(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__assign_function__Node__children(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__children(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__resize_function__Node__children(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array[4] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Node, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "children",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Node, children),  // bytes offset in struct
    NULL,  // default value
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__size_function__Node__children,  // size() function pointer
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__children,  // get_const(index) function pointer
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__children,  // get(index) function pointer
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__fetch_function__Node__children,  // fetch(index, &value) function pointer
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__assign_function__Node__children,  // assign(index, value) function pointer
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__resize_function__Node__children  // resize(index) function pointer
  },
  {
    "next",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Node, next),  // bytes offset in struct
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
    offsetof(ma_interfaces__msg__Node, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_members = {
  "ma_interfaces__msg",  // message namespace
  "Node",  // message name
  4,  // number of fields
  sizeof(ma_interfaces__msg__Node),
  ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array,  // message members
  ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_init_function,  // function to initialize message memory (memory has to be allocated)
  ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle = {
  0,
  &ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ma_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ma_interfaces, msg, Node)() {
  if (!ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle.typesupport_identifier) {
    ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ma_interfaces__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
