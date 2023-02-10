// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ma_interfaces:msg/Bid.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/msg/detail/bid__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id`
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
ma_interfaces__msg__Bid__init(ma_interfaces__msg__Bid * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    ma_interfaces__msg__Bid__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    ma_interfaces__msg__Bid__fini(msg);
    return false;
  }
  // st
  // et
  // value
  return true;
}

void
ma_interfaces__msg__Bid__fini(ma_interfaces__msg__Bid * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // st
  // et
  // value
}

bool
ma_interfaces__msg__Bid__are_equal(const ma_interfaces__msg__Bid * lhs, const ma_interfaces__msg__Bid * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
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
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
ma_interfaces__msg__Bid__copy(
  const ma_interfaces__msg__Bid * input,
  ma_interfaces__msg__Bid * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // st
  output->st = input->st;
  // et
  output->et = input->et;
  // value
  output->value = input->value;
  return true;
}

ma_interfaces__msg__Bid *
ma_interfaces__msg__Bid__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Bid * msg = (ma_interfaces__msg__Bid *)allocator.allocate(sizeof(ma_interfaces__msg__Bid), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__msg__Bid));
  bool success = ma_interfaces__msg__Bid__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__msg__Bid__destroy(ma_interfaces__msg__Bid * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__msg__Bid__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__msg__Bid__Sequence__init(ma_interfaces__msg__Bid__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Bid * data = NULL;

  if (size) {
    data = (ma_interfaces__msg__Bid *)allocator.zero_allocate(size, sizeof(ma_interfaces__msg__Bid), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__msg__Bid__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__msg__Bid__fini(&data[i - 1]);
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
ma_interfaces__msg__Bid__Sequence__fini(ma_interfaces__msg__Bid__Sequence * array)
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
      ma_interfaces__msg__Bid__fini(&array->data[i]);
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

ma_interfaces__msg__Bid__Sequence *
ma_interfaces__msg__Bid__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__msg__Bid__Sequence * array = (ma_interfaces__msg__Bid__Sequence *)allocator.allocate(sizeof(ma_interfaces__msg__Bid__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__msg__Bid__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__msg__Bid__Sequence__destroy(ma_interfaces__msg__Bid__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__msg__Bid__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__msg__Bid__Sequence__are_equal(const ma_interfaces__msg__Bid__Sequence * lhs, const ma_interfaces__msg__Bid__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__msg__Bid__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__msg__Bid__Sequence__copy(
  const ma_interfaces__msg__Bid__Sequence * input,
  ma_interfaces__msg__Bid__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__msg__Bid);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__msg__Bid * data =
      (ma_interfaces__msg__Bid *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__msg__Bid__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__msg__Bid__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__msg__Bid__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
