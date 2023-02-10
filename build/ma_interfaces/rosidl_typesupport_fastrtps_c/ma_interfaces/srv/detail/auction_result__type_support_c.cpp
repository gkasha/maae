// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/srv/detail/auction_result__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ma_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ma_interfaces/srv/detail/auction_result__struct.h"
#include "ma_interfaces/srv/detail/auction_result__functions.h"
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

#include "ma_interfaces/msg/detail/bid__functions.h"  // b
#include "ma_interfaces/msg/detail/task__functions.h"  // t

// forward declare type support functions
size_t get_serialized_size_ma_interfaces__msg__Bid(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_ma_interfaces__msg__Bid(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Bid)();
size_t get_serialized_size_ma_interfaces__msg__Task(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_ma_interfaces__msg__Task(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Task)();


using _AuctionResult_Request__ros_msg_type = ma_interfaces__srv__AuctionResult_Request;

static bool _AuctionResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AuctionResult_Request__ros_msg_type * ros_message = static_cast<const _AuctionResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: t
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Task
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->t, cdr))
    {
      return false;
    }
  }

  // Field name: b
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Bid
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->b, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _AuctionResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AuctionResult_Request__ros_msg_type * ros_message = static_cast<_AuctionResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: t
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Task
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->t))
    {
      return false;
    }
  }

  // Field name: b
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, ma_interfaces, msg, Bid
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->b))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t get_serialized_size_ma_interfaces__srv__AuctionResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AuctionResult_Request__ros_msg_type * ros_message = static_cast<const _AuctionResult_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name t

  current_alignment += get_serialized_size_ma_interfaces__msg__Task(
    &(ros_message->t), current_alignment);
  // field.name b

  current_alignment += get_serialized_size_ma_interfaces__msg__Bid(
    &(ros_message->b), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _AuctionResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ma_interfaces__srv__AuctionResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t max_serialized_size_ma_interfaces__srv__AuctionResult_Request(
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

  // member: t
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_ma_interfaces__msg__Task(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: b
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_ma_interfaces__msg__Bid(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _AuctionResult_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ma_interfaces__srv__AuctionResult_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AuctionResult_Request = {
  "ma_interfaces::srv",
  "AuctionResult_Request",
  _AuctionResult_Request__cdr_serialize,
  _AuctionResult_Request__cdr_deserialize,
  _AuctionResult_Request__get_serialized_size,
  _AuctionResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _AuctionResult_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AuctionResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, srv, AuctionResult_Request)() {
  return &_AuctionResult_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ma_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ma_interfaces/srv/detail/auction_result__struct.h"
// already included above
// #include "ma_interfaces/srv/detail/auction_result__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


// forward declare type support functions


using _AuctionResult_Response__ros_msg_type = ma_interfaces__srv__AuctionResult_Response;

static bool _AuctionResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AuctionResult_Response__ros_msg_type * ros_message = static_cast<const _AuctionResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _AuctionResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AuctionResult_Response__ros_msg_type * ros_message = static_cast<_AuctionResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t get_serialized_size_ma_interfaces__srv__AuctionResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AuctionResult_Response__ros_msg_type * ros_message = static_cast<const _AuctionResult_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AuctionResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ma_interfaces__srv__AuctionResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ma_interfaces
size_t max_serialized_size_ma_interfaces__srv__AuctionResult_Response(
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

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _AuctionResult_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ma_interfaces__srv__AuctionResult_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AuctionResult_Response = {
  "ma_interfaces::srv",
  "AuctionResult_Response",
  _AuctionResult_Response__cdr_serialize,
  _AuctionResult_Response__cdr_deserialize,
  _AuctionResult_Response__get_serialized_size,
  _AuctionResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _AuctionResult_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AuctionResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, srv, AuctionResult_Response)() {
  return &_AuctionResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ma_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ma_interfaces/srv/auction_result.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t AuctionResult__callbacks = {
  "ma_interfaces::srv",
  "AuctionResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, srv, AuctionResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, srv, AuctionResult_Response)(),
};

static rosidl_service_type_support_t AuctionResult__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &AuctionResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ma_interfaces, srv, AuctionResult)() {
  return &AuctionResult__handle;
}

#if defined(__cplusplus)
}
#endif
