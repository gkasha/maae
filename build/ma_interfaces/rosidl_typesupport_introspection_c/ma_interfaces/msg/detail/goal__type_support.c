// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ma_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ma_interfaces/msg/detail/goal__rosidl_typesupport_introspection_c.h"
#include "ma_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ma_interfaces/msg/detail/goal__functions.h"
#include "ma_interfaces/msg/detail/goal__struct.h"


// Include directives for member types
// Member `id`
// Member `owner`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ma_interfaces__msg__Goal__init(message_memory);
}

void ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_fini_function(void * message_memory)
{
  ma_interfaces__msg__Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_member_array[6] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "owner",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, owner),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_agents",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, num_agents),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "deadline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, deadline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ma_interfaces__msg__Goal, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_members = {
  "ma_interfaces__msg",  // message namespace
  "Goal",  // message name
  6,  // number of fields
  sizeof(ma_interfaces__msg__Goal),
  ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_member_array,  // message members
  ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_type_support_handle = {
  0,
  &ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ma_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ma_interfaces, msg, Goal)() {
  if (!ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_type_support_handle.typesupport_identifier) {
    ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ma_interfaces__msg__Goal__rosidl_typesupport_introspection_c__Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
