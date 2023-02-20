// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:msg/ActionFeedback.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__STRUCT_HPP_
#define MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__msg__ActionFeedback __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__msg__ActionFeedback __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActionFeedback_
{
  using Type = ActionFeedback_<ContainerAllocator>;

  explicit ActionFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = "";
      this->agent_id = "";
      this->name = "";
      this->st = 0.0f;
      this->action_started = 0l;
      this->action_completed = 0l;
      this->action_failed = 0l;
    }
  }

  explicit ActionFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
      this->st = 0.0f;
      this->action_started = 0l;
      this->action_completed = 0l;
      this->action_failed = 0l;
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
  using _st_type =
    float;
  _st_type st;
  using _action_started_type =
    int32_t;
  _action_started_type action_started;
  using _action_completed_type =
    int32_t;
  _action_completed_type action_completed;
  using _action_failed_type =
    int32_t;
  _action_failed_type action_failed;

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
  Type & set__st(
    const float & _arg)
  {
    this->st = _arg;
    return *this;
  }
  Type & set__action_started(
    const int32_t & _arg)
  {
    this->action_started = _arg;
    return *this;
  }
  Type & set__action_completed(
    const int32_t & _arg)
  {
    this->action_completed = _arg;
    return *this;
  }
  Type & set__action_failed(
    const int32_t & _arg)
  {
    this->action_failed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::msg::ActionFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::msg::ActionFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::ActionFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::ActionFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__msg__ActionFeedback
    std::shared_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__msg__ActionFeedback
    std::shared_ptr<ma_interfaces::msg::ActionFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActionFeedback_ & other) const
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
    if (this->st != other.st) {
      return false;
    }
    if (this->action_started != other.action_started) {
      return false;
    }
    if (this->action_completed != other.action_completed) {
      return false;
    }
    if (this->action_failed != other.action_failed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActionFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActionFeedback_

// alias to use template instance with default allocator
using ActionFeedback =
  ma_interfaces::msg::ActionFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__ACTION_FEEDBACK__STRUCT_HPP_
