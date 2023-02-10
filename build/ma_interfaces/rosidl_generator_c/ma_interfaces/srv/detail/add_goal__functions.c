// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ma_interfaces:srv/AddGoal.idl
// generated code does not contain a copyright notice
#include "ma_interfaces/srv/detail/add_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `g`
#include "ma_interfaces/msg/detail/goal__functions.h"

bool
ma_interfaces__srv__AddGoal_Request__init(ma_interfaces__srv__AddGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // g
  if (!ma_interfaces__msg__Goal__init(&msg->g)) {
    ma_interfaces__srv__AddGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
ma_interfaces__srv__AddGoal_Request__fini(ma_interfaces__srv__AddGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // g
  ma_interfaces__msg__Goal__fini(&msg->g);
}

bool
ma_interfaces__srv__AddGoal_Request__are_equal(const ma_interfaces__srv__AddGoal_Request * lhs, const ma_interfaces__srv__AddGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // g
  if (!ma_interfaces__msg__Goal__are_equal(
      &(lhs->g), &(rhs->g)))
  {
    return false;
  }
  return true;
}

bool
ma_interfaces__srv__AddGoal_Request__copy(
  const ma_interfaces__srv__AddGoal_Request * input,
  ma_interfaces__srv__AddGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // g
  if (!ma_interfaces__msg__Goal__copy(
      &(input->g), &(output->g)))
  {
    return false;
  }
  return true;
}

ma_interfaces__srv__AddGoal_Request *
ma_interfaces__srv__AddGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Request * msg = (ma_interfaces__srv__AddGoal_Request *)allocator.allocate(sizeof(ma_interfaces__srv__AddGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__srv__AddGoal_Request));
  bool success = ma_interfaces__srv__AddGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__srv__AddGoal_Request__destroy(ma_interfaces__srv__AddGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__srv__AddGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__srv__AddGoal_Request__Sequence__init(ma_interfaces__srv__AddGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Request * data = NULL;

  if (size) {
    data = (ma_interfaces__srv__AddGoal_Request *)allocator.zero_allocate(size, sizeof(ma_interfaces__srv__AddGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__srv__AddGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__srv__AddGoal_Request__fini(&data[i - 1]);
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
ma_interfaces__srv__AddGoal_Request__Sequence__fini(ma_interfaces__srv__AddGoal_Request__Sequence * array)
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
      ma_interfaces__srv__AddGoal_Request__fini(&array->data[i]);
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

ma_interfaces__srv__AddGoal_Request__Sequence *
ma_interfaces__srv__AddGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Request__Sequence * array = (ma_interfaces__srv__AddGoal_Request__Sequence *)allocator.allocate(sizeof(ma_interfaces__srv__AddGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__srv__AddGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__srv__AddGoal_Request__Sequence__destroy(ma_interfaces__srv__AddGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__srv__AddGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__srv__AddGoal_Request__Sequence__are_equal(const ma_interfaces__srv__AddGoal_Request__Sequence * lhs, const ma_interfaces__srv__AddGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__srv__AddGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__srv__AddGoal_Request__Sequence__copy(
  const ma_interfaces__srv__AddGoal_Request__Sequence * input,
  ma_interfaces__srv__AddGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__srv__AddGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__srv__AddGoal_Request * data =
      (ma_interfaces__srv__AddGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__srv__AddGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__srv__AddGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__srv__AddGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ma_interfaces__srv__AddGoal_Response__init(ma_interfaces__srv__AddGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  return true;
}

void
ma_interfaces__srv__AddGoal_Response__fini(ma_interfaces__srv__AddGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
}

bool
ma_interfaces__srv__AddGoal_Response__are_equal(const ma_interfaces__srv__AddGoal_Response * lhs, const ma_interfaces__srv__AddGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
ma_interfaces__srv__AddGoal_Response__copy(
  const ma_interfaces__srv__AddGoal_Response * input,
  ma_interfaces__srv__AddGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  return true;
}

ma_interfaces__srv__AddGoal_Response *
ma_interfaces__srv__AddGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Response * msg = (ma_interfaces__srv__AddGoal_Response *)allocator.allocate(sizeof(ma_interfaces__srv__AddGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ma_interfaces__srv__AddGoal_Response));
  bool success = ma_interfaces__srv__AddGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ma_interfaces__srv__AddGoal_Response__destroy(ma_interfaces__srv__AddGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ma_interfaces__srv__AddGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ma_interfaces__srv__AddGoal_Response__Sequence__init(ma_interfaces__srv__AddGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Response * data = NULL;

  if (size) {
    data = (ma_interfaces__srv__AddGoal_Response *)allocator.zero_allocate(size, sizeof(ma_interfaces__srv__AddGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ma_interfaces__srv__AddGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ma_interfaces__srv__AddGoal_Response__fini(&data[i - 1]);
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
ma_interfaces__srv__AddGoal_Response__Sequence__fini(ma_interfaces__srv__AddGoal_Response__Sequence * array)
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
      ma_interfaces__srv__AddGoal_Response__fini(&array->data[i]);
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

ma_interfaces__srv__AddGoal_Response__Sequence *
ma_interfaces__srv__AddGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ma_interfaces__srv__AddGoal_Response__Sequence * array = (ma_interfaces__srv__AddGoal_Response__Sequence *)allocator.allocate(sizeof(ma_interfaces__srv__AddGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ma_interfaces__srv__AddGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ma_interfaces__srv__AddGoal_Response__Sequence__destroy(ma_interfaces__srv__AddGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ma_interfaces__srv__AddGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ma_interfaces__srv__AddGoal_Response__Sequence__are_equal(const ma_interfaces__srv__AddGoal_Response__Sequence * lhs, const ma_interfaces__srv__AddGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ma_interfaces__srv__AddGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ma_interfaces__srv__AddGoal_Response__Sequence__copy(
  const ma_interfaces__srv__AddGoal_Response__Sequence * input,
  ma_interfaces__srv__AddGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ma_interfaces__srv__AddGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ma_interfaces__srv__AddGoal_Response * data =
      (ma_interfaces__srv__AddGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ma_interfaces__srv__AddGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ma_interfaces__srv__AddGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ma_interfaces__srv__AddGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
