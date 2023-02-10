// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ma_interfaces:srv/AuctionResult.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/srv/detail/auction_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `t`
#include "ma_interfaces/msg/detail/task__functions.h"
// Member `b`
#include "ma_interfaces/msg/detail/bid__functions.h"

bool
ma_interfaces__srv__AuctionResult_Request__init(ma_interfaces__srv__AuctionResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // t
  if (!ma_interfaces__msg__Task__init(&msg->t)) {
    ma_interfaces__srv__AuctionResult_Request__fini(msg);
    return false;
  }
  // b
  if (!ma_interfaces__msg__Bid__init(&msg->b)) {
    ma_interfaces__srv__AuctionResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
ma_interfaces__srv__AuctionResult_Request__fini(ma_interfaces__srv__AuctionResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // t
  ma_interfaces__msg__Task__fini(&msg->t);
  // b
  ma_interfaces__msg__Bid__fini(&msg->b);
}

bool
ma_interfaces__srv__AuctionResult_Request__are_equal(const ma_interfaces__srv__AuctionResult_Request * lhs, const ma_interfaces__srv__AuctionResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // t
  if (!ma_interfaces__msg__Task__are_equal(
      &(lhs->t), &(rhs->t)))
  {
    return false;
  }
  // b
  if (!ma_interfaces__msg__Bid__are_equal(
      &(lhs->b), &(rhs->b)))
  {
    return false;
  }
  return true;
}

bool
ma_interfaces__srv__AuctionResult_Request__copy(
  const ma_interfaces__srv__AuctionResult_Request * input,
  ma_interfaces__srv__AuctionResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // t
  if (!ma_interfaces__msg__Task__copy(
      &(input->t), &(output->t)))
  {
    return false;
  }
  // b
  if (!ma_interfaces__msg__Bid__copy(
      &(input->b), &(output->b)))
  {
    return false;
  }
  return true;
}

ma_interfaces__srv__AuctionResult_Request *
ma_interfaces__srv__AuctionResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Request * msg = (ma_interfaces__srv__AuctionResult_Request *)allocator.allocate(sizeof(ma_interfaces__srv__AuctionResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__srv__AuctionResult_Request));
  bool success = ma_interfaces__srv__AuctionResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__srv__AuctionResult_Request__destroy(ma_interfaces__srv__AuctionResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__srv__AuctionResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__srv__AuctionResult_Request__Sequence__init(ma_interfaces__srv__AuctionResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Request * data = NULL;

  if (size) {
    data = (ma_interfaces__srv__AuctionResult_Request *)allocator.zero_allocate(size, sizeof(ma_interfaces__srv__AuctionResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__srv__AuctionResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__srv__AuctionResult_Request__fini(&data[i - 1]);
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
ma_interfaces__srv__AuctionResult_Request__Sequence__fini(ma_interfaces__srv__AuctionResult_Request__Sequence * array)
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
      ma_interfaces__srv__AuctionResult_Request__fini(&array->data[i]);
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

ma_interfaces__srv__AuctionResult_Request__Sequence *
ma_interfaces__srv__AuctionResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Request__Sequence * array = (ma_interfaces__srv__AuctionResult_Request__Sequence *)allocator.allocate(sizeof(ma_interfaces__srv__AuctionResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__srv__AuctionResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__srv__AuctionResult_Request__Sequence__destroy(ma_interfaces__srv__AuctionResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__srv__AuctionResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__srv__AuctionResult_Request__Sequence__are_equal(const ma_interfaces__srv__AuctionResult_Request__Sequence * lhs, const ma_interfaces__srv__AuctionResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__srv__AuctionResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__srv__AuctionResult_Request__Sequence__copy(
  const ma_interfaces__srv__AuctionResult_Request__Sequence * input,
  ma_interfaces__srv__AuctionResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__srv__AuctionResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__srv__AuctionResult_Request * data =
      (ma_interfaces__srv__AuctionResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__srv__AuctionResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__srv__AuctionResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__srv__AuctionResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ma_interfaces__srv__AuctionResult_Response__init(ma_interfaces__srv__AuctionResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
ma_interfaces__srv__AuctionResult_Response__fini(ma_interfaces__srv__AuctionResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
ma_interfaces__srv__AuctionResult_Response__are_equal(const ma_interfaces__srv__AuctionResult_Response * lhs, const ma_interfaces__srv__AuctionResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
ma_interfaces__srv__AuctionResult_Response__copy(
  const ma_interfaces__srv__AuctionResult_Response * input,
  ma_interfaces__srv__AuctionResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

ma_interfaces__srv__AuctionResult_Response *
ma_interfaces__srv__AuctionResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Response * msg = (ma_interfaces__srv__AuctionResult_Response *)allocator.allocate(sizeof(ma_interfaces__srv__AuctionResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__srv__AuctionResult_Response));
  bool success = ma_interfaces__srv__AuctionResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__srv__AuctionResult_Response__destroy(ma_interfaces__srv__AuctionResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__srv__AuctionResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__srv__AuctionResult_Response__Sequence__init(ma_interfaces__srv__AuctionResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Response * data = NULL;

  if (size) {
    data = (ma_interfaces__srv__AuctionResult_Response *)allocator.zero_allocate(size, sizeof(ma_interfaces__srv__AuctionResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__srv__AuctionResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__srv__AuctionResult_Response__fini(&data[i - 1]);
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
ma_interfaces__srv__AuctionResult_Response__Sequence__fini(ma_interfaces__srv__AuctionResult_Response__Sequence * array)
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
      ma_interfaces__srv__AuctionResult_Response__fini(&array->data[i]);
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

ma_interfaces__srv__AuctionResult_Response__Sequence *
ma_interfaces__srv__AuctionResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AuctionResult_Response__Sequence * array = (ma_interfaces__srv__AuctionResult_Response__Sequence *)allocator.allocate(sizeof(ma_interfaces__srv__AuctionResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__srv__AuctionResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__srv__AuctionResult_Response__Sequence__destroy(ma_interfaces__srv__AuctionResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__srv__AuctionResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__srv__AuctionResult_Response__Sequence__are_equal(const ma_interfaces__srv__AuctionResult_Response__Sequence * lhs, const ma_interfaces__srv__AuctionResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__srv__AuctionResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__srv__AuctionResult_Response__Sequence__copy(
  const ma_interfaces__srv__AuctionResult_Response__Sequence * input,
  ma_interfaces__srv__AuctionResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__srv__AuctionResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__srv__AuctionResult_Response * data =
      (ma_interfaces__srv__AuctionResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__srv__AuctionResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__srv__AuctionResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__srv__AuctionResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
