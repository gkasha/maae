// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ma_interfaces:msg/ActionDispatch.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/msg/detail/action_dispatch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `action_id`
// Member `agent_id`
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
ma_interfaces__msg__ActionDispatch__init(ma_interfaces__msg__ActionDispatch * msg)
{
  if (!msg) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__init(&msg->action_id)) {
    ma_interfaces__msg__ActionDispatch__fini(msg);
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__init(&msg->agent_id)) {
    ma_interfaces__msg__ActionDispatch__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    ma_interfaces__msg__ActionDispatch__fini(msg);
    return false;
  }
  // duration
  // start_time
  return true;
}

void
ma_interfaces__msg__ActionDispatch__fini(ma_interfaces__msg__ActionDispatch * msg)
{
  if (!msg) {
    return;
  }
  // action_id
  rosidl_runtime_c__String__fini(&msg->action_id);
  // agent_id
  rosidl_runtime_c__String__fini(&msg->agent_id);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // duration
  // start_time
}

bool
ma_interfaces__msg__ActionDispatch__are_equal(const ma_interfaces__msg__ActionDispatch * lhs, const ma_interfaces__msg__ActionDispatch * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_id), &(rhs->action_id)))
  {
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->agent_id), &(rhs->agent_id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  // start_time
  if (lhs->start_time != rhs->start_time) {
    return false;
  }
  return true;
}

bool
ma_interfaces__msg__ActionDispatch__copy(
  const ma_interfaces__msg__ActionDispatch * input,
  ma_interfaces__msg__ActionDispatch * output)
{
  if (!input || !output) {
    return false;
  }
  // action_id
  if (!rosidl_runtime_c__String__copy(
      &(input->action_id), &(output->action_id)))
  {
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__copy(
      &(input->agent_id), &(output->agent_id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // duration
  output->duration = input->duration;
  // start_time
  output->start_time = input->start_time;
  return true;
}

ma_interfaces__msg__ActionDispatch *
ma_interfaces__msg__ActionDispatch__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__ActionDispatch * msg = (ma_interfaces__msg__ActionDispatch *)allocator.allocate(sizeof(ma_interfaces__msg__ActionDispatch), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__msg__ActionDispatch));
  bool success = ma_interfaces__msg__ActionDispatch__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__msg__ActionDispatch__destroy(ma_interfaces__msg__ActionDispatch * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__msg__ActionDispatch__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__msg__ActionDispatch__Sequence__init(ma_interfaces__msg__ActionDispatch__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__ActionDispatch * data = NULL;

  if (size) {
    data = (ma_interfaces__msg__ActionDispatch *)allocator.zero_allocate(size, sizeof(ma_interfaces__msg__ActionDispatch), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__msg__ActionDispatch__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__msg__ActionDispatch__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ma_interfaces__msg__ActionDispatch__Sequence__fini(ma_interfaces__msg__ActionDispatch__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ma_interfaces__msg__ActionDispatch__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ma_interfaces__msg__ActionDispatch__Sequence *
ma_interfaces__msg__ActionDispatch__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__ActionDispatch__Sequence * array = (ma_interfaces__msg__ActionDispatch__Sequence *)allocator.allocate(sizeof(ma_interfaces__msg__ActionDispatch__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__msg__ActionDispatch__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__msg__ActionDispatch__Sequence__destroy(ma_interfaces__msg__ActionDispatch__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__msg__ActionDispatch__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__msg__ActionDispatch__Sequence__are_equal(const ma_interfaces__msg__ActionDispatch__Sequence * lhs, const ma_interfaces__msg__ActionDispatch__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__msg__ActionDispatch__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__msg__ActionDispatch__Sequence__copy(
  const ma_interfaces__msg__ActionDispatch__Sequence * input,
  ma_interfaces__msg__ActionDispatch__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__msg__ActionDispatch);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__msg__ActionDispatch * data =
      (ma_interfaces__msg__ActionDispatch *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__msg__ActionDispatch__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__msg__ActionDispatch__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__msg__ActionDispatch__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
