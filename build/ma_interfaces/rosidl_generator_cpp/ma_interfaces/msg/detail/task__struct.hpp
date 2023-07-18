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
      this->num_agents = 0ll;
      this->value = 0.0;
      this->execution_range = 0.0;
      this->duration = 0.0;
      this->st = 0.0;
      this->et = 0.0;
      this->x = 0.0;
      this->y = 0.0;
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
      this->num_agents = 0ll;
      this->value = 0.0;
      this->execution_range = 0.0;
      this->duration = 0.0;
      this->st = 0.0;
      this->et = 0.0;
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _owner_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _owner_type owner;
  using _num_agents_type =
    int64_t;
  _num_agents_type num_agents;
  using _value_type =
    double;
  _value_type value;
  using _execution_range_type =
    double;
  _execution_range_type execution_range;
  using _duration_type =
    double;
  _duration_type duration;
  using _st_type =
    double;
  _st_type st;
  using _et_type =
    double;
  _et_type et;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

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
  Type & set__num_agents(
    const int64_t & _arg)
  {
    this->num_agents = _arg;
    return *this;
  }
  Type & set__value(
    const double & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__execution_range(
    const double & _arg)
  {
    this->execution_range = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }
  Type & set__st(
    const double & _arg)
  {
    this->st = _arg;
    return *this;
  }
  Type & set__et(
    const double & _arg)
  {
    this->et = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
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
    if (this->num_agents != other.num_agents) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    if (this->execution_range != other.execution_range) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->st != other.st) {
      return false;
    }
    if (this->et != other.et) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
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
