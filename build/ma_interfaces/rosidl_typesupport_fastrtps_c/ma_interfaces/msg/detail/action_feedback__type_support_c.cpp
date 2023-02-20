// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ma_interfaces:msg/ActionFeedback.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/msg/detail/action_feedback__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ma_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ma_interfaces/msg/detail/action_feedback__struct.h"
#include "ma_interfaces/msg/detail/action_feedback__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // action_id, agent_id, name
#include "rosidl_runtime_c/string_functions.h"  // action_id, agent_id, name

// forward declare type support functions


using _ActionFeedback__ros_msg_type = ma_interfaces__msg__ActionFeedback;

static bool _ActionFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ActionFeedback__ros_msg_type * ros_message = static_cast<const _ActionFeedback__ros_msg_type *>(untyped_ros_message);
  // Field name: action_id
  {
    const rosidl_runtime_c__String * str = &ros_message->action_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: agent_id
  {
    const rosidl_runtime_c__String * str = &ros_message->agent_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: st
  {
    cdr << ros_message->st;
  }

  // Field name: action_started
  {
    cdr << ros_message->action_started;
  }

  // Field name: action_completed
  {
    cdr << ros_message->action_completed;
  }

  // Field name: action_failed
  {
    cdr << ros_message->action_failed;
  }

  return true;
}

static bool _ActionFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ActionFeedback__ros_msg_type * ros_message = static_cast<_ActionFeedback__ros_msg_type *>(untyped_ros_message);
  // Field name: action_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->action_id.data) {
      rosidl_runtime_c__String__init(&ros_message->action_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->action_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'action_id'\n");
      return false;
    }
  }

  // Field name: agent_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->agent_id.data) {
      rosidl_runtime_c__String__init(&ros_message->agent_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->agent_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'agent_id'\n");
      return false;
    }
  }

  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: st
  {
    cdr >> ros_message->st;
  }

  // Field name: action_started
  {
    cdr >> ros_message->action_started;
  }

  // Field name: action_completed
  {
    cdr >> ros_message->action_completed;
  }

  // Field name: action_failed
  {
    cdr >> ros_message->action_failed;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t get_serialized_size_ma_interfaces__msg__ActionFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ActionFeedback__ros_msg_type * ros_message = static_cast<const _ActionFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name action_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->action_id.size + 1);
  // field.name agent_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->agent_id.size + 1);
  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name st
  {
    size_t item_size = sizeof(ros_message->st);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name action_started
  {
    size_t item_size = sizeof(ros_message->action_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name action_completed
  {
    size_t item_size = sizeof(ros_message->action_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name action_failed
  {
    size_t item_size = sizeof(ros_message->action_failed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ActionFeedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ma_interfaces__msg__ActionFeedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t max_serialized_size_ma_interfaces__msg__ActionFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: action_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: agent_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: st
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: action_started
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: action_completed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: action_failed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ActionFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ma_interfaces__msg__ActionFeedback(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ActionFeedback = {
  "ma_interfaces::msg",
  "ActionFeedback",
  _ActionFeedback__cdr_serialize,
  _ActionFeedback__cdr_deserialize,
  _ActionFeedback__get_serialized_size,
  _ActionFeedback__max_serialized_size
};

static rosidl_message_type_support_t _ActionFeedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ActionFeedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, msg, ActionFeedback)() {
  return &_ActionFeedback__type_support;
}

#if defined(__cplusplus)
}
#endif
