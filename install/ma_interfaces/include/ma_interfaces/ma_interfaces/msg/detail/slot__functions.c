// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ma_interfaces:msg/Slot.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/msg/detail/slot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `agent_id`
// Member `owner_id`
// Member `task_id`
#include "rosidl_runtime_c/string_functions.h"

bool
ma_interfaces__msg__Slot__init(ma_interfaces__msg__Slot * msg)
{
  if (!msg) {
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__init(&msg->agent_id)) {
    ma_interfaces__msg__Slot__fini(msg);
    return false;
  }
  // owner_id
  if (!rosidl_runtime_c__String__init(&msg->owner_id)) {
    ma_interfaces__msg__Slot__fini(msg);
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__init(&msg->task_id)) {
    ma_interfaces__msg__Slot__fini(msg);
    return false;
  }
  // st
  // et
  // x1
  // y1
  // x2
  // y2
  // speed
  return true;
}

void
ma_interfaces__msg__Slot__fini(ma_interfaces__msg__Slot * msg)
{
  if (!msg) {
    return;
  }
  // agent_id
  rosidl_runtime_c__String__fini(&msg->agent_id);
  // owner_id
  rosidl_runtime_c__String__fini(&msg->owner_id);
  // task_id
  rosidl_runtime_c__String__fini(&msg->task_id);
  // st
  // et
  // x1
  // y1
  // x2
  // y2
  // speed
}

bool
ma_interfaces__msg__Slot__are_equal(const ma_interfaces__msg__Slot * lhs, const ma_interfaces__msg__Slot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->agent_id), &(rhs->agent_id)))
  {
    return false;
  }
  // owner_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->owner_id), &(rhs->owner_id)))
  {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_id), &(rhs->task_id)))
  {
    return false;
  }
  // st
  if (lhs->st != rhs->st) {
    return false;
  }
  // et
  if (lhs->et != rhs->et) {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
ma_interfaces__msg__Slot__copy(
  const ma_interfaces__msg__Slot * input,
  ma_interfaces__msg__Slot * output)
{
  if (!input || !output) {
    return false;
  }
  // agent_id
  if (!rosidl_runtime_c__String__copy(
      &(input->agent_id), &(output->agent_id)))
  {
    return false;
  }
  // owner_id
  if (!rosidl_runtime_c__String__copy(
      &(input->owner_id), &(output->owner_id)))
  {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__copy(
      &(input->task_id), &(output->task_id)))
  {
    return false;
  }
  // st
  output->st = input->st;
  // et
  output->et = input->et;
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // speed
  output->speed = input->speed;
  return true;
}

ma_interfaces__msg__Slot *
ma_interfaces__msg__Slot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Slot * msg = (ma_interfaces__msg__Slot *)allocator.allocate(sizeof(ma_interfaces__msg__Slot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__msg__Slot));
  bool success = ma_interfaces__msg__Slot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__msg__Slot__destroy(ma_interfaces__msg__Slot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__msg__Slot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__msg__Slot__Sequence__init(ma_interfaces__msg__Slot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Slot * data = NULL;

  if (size) {
    data = (ma_interfaces__msg__Slot *)allocator.zero_allocate(size, sizeof(ma_interfaces__msg__Slot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__msg__Slot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__msg__Slot__fini(&data[i - 1]);
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
ma_interfaces__msg__Slot__Sequence__fini(ma_interfaces__msg__Slot__Sequence * array)
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
      ma_interfaces__msg__Slot__fini(&array->data[i]);
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

ma_interfaces__msg__Slot__Sequence *
ma_interfaces__msg__Slot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Slot__Sequence * array = (ma_interfaces__msg__Slot__Sequence *)allocator.allocate(sizeof(ma_interfaces__msg__Slot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__msg__Slot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__msg__Slot__Sequence__destroy(ma_interfaces__msg__Slot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__msg__Slot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__msg__Slot__Sequence__are_equal(const ma_interfaces__msg__Slot__Sequence * lhs, const ma_interfaces__msg__Slot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__msg__Slot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__msg__Slot__Sequence__copy(
  const ma_interfaces__msg__Slot__Sequence * input,
  ma_interfaces__msg__Slot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__msg__Slot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__msg__Slot * data =
      (ma_interfaces__msg__Slot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__msg__Slot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__msg__Slot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__msg__Slot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
