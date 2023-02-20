// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
#define MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__msg__Task __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__msg__Task __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Task_
{
  using Type = Task_<ContainerAllocator>;

  explicit Task_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->owner = "";
      this->duration = 0.0f;
      this->value = 0ll;
    }
  }

  explicit Task_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc),
    owner(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->owner = "";
      this->duration = 0.0f;
      this->value = 0ll;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _owner_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _owner_type owner;
  using _duration_type =
    float;
  _duration_type duration;
  using _value_type =
    int64_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__owner(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->owner = _arg;
    return *this;
  }
  Type & set__duration(
    const float & _arg)
  {
    this->duration = _arg;
    return *this;
  }
  Type & set__value(
    const int64_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::msg::Task_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::msg::Task_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::msg::Task_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Task_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Task_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Task_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Task_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::msg::Task_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__msg__Task
    std::shared_ptr<ma_interfaces::msg::Task_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__msg__Task
    std::shared_ptr<ma_interfaces::msg::Task_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->owner != other.owner) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_

// alias to use template instance with default allocator
using Task =
  ma_interfaces::msg::Task_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
