// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:msg/ActionDispatch.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_HPP_
#define MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__msg__ActionDispatch __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__msg__ActionDispatch __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActionDispatch_
{
  using Type = ActionDispatch_<ContainerAllocator>;

  explicit ActionDispatch_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = "";
      this->agent_id = "";
      this->name = "";
      this->num_agents = 0l;
      this->execution_range = 0.0;
      this->duration = 0.0;
      this->start_time = 0.0;
    }
  }

  explicit ActionDispatch_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action_id(_alloc),
    agent_id(_alloc),
    name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = "";
      this->agent_id = "";
      this->name = "";
      this->num_agents = 0l;
      this->execution_range = 0.0;
      this->duration = 0.0;
      this->start_time = 0.0;
    }
  }

  // field types and members
  using _action_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_id_type action_id;
  using _agent_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agent_id_type agent_id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _num_agents_type =
    int32_t;
  _num_agents_type num_agents;
  using _execution_range_type =
    double;
  _execution_range_type execution_range;
  using _duration_type =
    double;
  _duration_type duration;
  using _start_time_type =
    double;
  _start_time_type start_time;

  // setters for named parameter idiom
  Type & set__action_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_id = _arg;
    return *this;
  }
  Type & set__agent_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agent_id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__num_agents(
    const int32_t & _arg)
  {
    this->num_agents = _arg;
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
  Type & set__start_time(
    const double & _arg)
  {
    this->start_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::msg::ActionDispatch_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::msg::ActionDispatch_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::ActionDispatch_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::ActionDispatch_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__msg__ActionDispatch
    std::shared_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__msg__ActionDispatch
    std::shared_ptr<ma_interfaces::msg::ActionDispatch_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActionDispatch_ & other) const
  {
    if (this->action_id != other.action_id) {
      return false;
    }
    if (this->agent_id != other.agent_id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->num_agents != other.num_agents) {
      return false;
    }
    if (this->execution_range != other.execution_range) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->start_time != other.start_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActionDispatch_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActionDispatch_

// alias to use template instance with default allocator
using ActionDispatch =
  ma_interfaces::msg::ActionDispatch_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_DISPATCH__STRUCT_HPP_
