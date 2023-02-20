// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ma_interfaces:msg/ActionDispatch.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__FUNCTIONS_H_
#define MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ma_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ma_interfaces/msg/detail/action_dispatch__struct.h"

/// Initialize msg/ActionDispatch message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ma_interfaces__msg__ActionDispatch
 * )) before or use
 * ma_interfaces__msg__ActionDispatch__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__init(ma_interfaces__msg__ActionDispatch * msg);

/// Finalize msg/ActionDispatch message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
void
ma_interfaces__msg__ActionDispatch__fini(ma_interfaces__msg__ActionDispatch * msg);

/// Create msg/ActionDispatch message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ma_interfaces__msg__ActionDispatch__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
ma_interfaces__msg__ActionDispatch *
ma_interfaces__msg__ActionDispatch__create();

/// Destroy msg/ActionDispatch message.
/**
 * It calls
 * ma_interfaces__msg__ActionDispatch__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
void
ma_interfaces__msg__ActionDispatch__destroy(ma_interfaces__msg__ActionDispatch * msg);

/// Check for msg/ActionDispatch message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__are_equal(const ma_interfaces__msg__ActionDispatch * lhs, const ma_interfaces__msg__ActionDispatch * rhs);

/// Copy a msg/ActionDispatch message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__copy(
  const ma_interfaces__msg__ActionDispatch * input,
  ma_interfaces__msg__ActionDispatch * output);

/// Initialize array of msg/ActionDispatch messages.
/**
 * It allocates the memory for the number of elements and calls
 * ma_interfaces__msg__ActionDispatch__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__Sequence__init(ma_interfaces__msg__ActionDispatch__Sequence * array, size_t size);

/// Finalize array of msg/ActionDispatch messages.
/**
 * It calls
 * ma_interfaces__msg__ActionDispatch__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
void
ma_interfaces__msg__ActionDispatch__Sequence__fini(ma_interfaces__msg__ActionDispatch__Sequence * array);

/// Create array of msg/ActionDispatch messages.
/**
 * It allocates the memory for the array and calls
 * ma_interfaces__msg__ActionDispatch__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
ma_interfaces__msg__ActionDispatch__Sequence *
ma_interfaces__msg__ActionDispatch__Sequence__create(size_t size);

/// Destroy array of msg/ActionDispatch messages.
/**
 * It calls
 * ma_interfaces__msg__ActionDispatch__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
void
ma_interfaces__msg__ActionDispatch__Sequence__destroy(ma_interfaces__msg__ActionDispatch__Sequence * array);

/// Check for msg/ActionDispatch message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__Sequence__are_equal(const ma_interfaces__msg__ActionDispatch__Sequence * lhs, const ma_interfaces__msg__ActionDispatch__Sequence * rhs);

/// Copy an array of msg/ActionDispatch messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ma_interfaces
bool
ma_interfaces__msg__ActionDispatch__Sequence__copy(
  const ma_interfaces__msg__ActionDispatch__Sequence * input,
  ma_interfaces__msg__ActionDispatch__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__FUNCTIONS_H_
