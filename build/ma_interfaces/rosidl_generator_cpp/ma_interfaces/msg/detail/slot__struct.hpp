// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:msg/Slot.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_HPP_
#define MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__msg__Slot __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__msg__Slot __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Slot_
{
  using Type = Slot_<ContainerAllocator>;

  explicit Slot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = "";
      this->owner_id = "";
      this->task_id = "";
      this->st = 0.0;
      this->et = 0.0;
      this->x1 = 0.0;
      this->y1 = 0.0;
      this->x2 = 0.0;
      this->y2 = 0.0;
      this->speed = 0.0;
    }
  }

  explicit Slot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : agent_id(_alloc),
    owner_id(_alloc),
    task_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = "";
      this->owner_id = "";
      this->task_id = "";
      this->st = 0.0;
      this->et = 0.0;
      this->x1 = 0.0;
      this->y1 = 0.0;
      this->x2 = 0.0;
      this->y2 = 0.0;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _agent_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agent_id_type agent_id;
  using _owner_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _owner_id_type owner_id;
  using _task_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_id_type task_id;
  using _st_type =
    double;
  _st_type st;
  using _et_type =
    double;
  _et_type et;
  using _x1_type =
    double;
  _x1_type x1;
  using _y1_type =
    double;
  _y1_type y1;
  using _x2_type =
    double;
  _x2_type x2;
  using _y2_type =
    double;
  _y2_type y2;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__agent_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agent_id = _arg;
    return *this;
  }
  Type & set__owner_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->owner_id = _arg;
    return *this;
  }
  Type & set__task_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_id = _arg;
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
  Type & set__x1(
    const double & _arg)
  {
    this->x1 = _arg;
    return *this;
  }
  Type & set__y1(
    const double & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__x2(
    const double & _arg)
  {
    this->x2 = _arg;
    return *this;
  }
  Type & set__y2(
    const double & _arg)
  {
    this->y2 = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::msg::Slot_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::msg::Slot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::msg::Slot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::msg::Slot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Slot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Slot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Slot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Slot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::msg::Slot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::msg::Slot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__msg__Slot
    std::shared_ptr<ma_interfaces::msg::Slot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__msg__Slot
    std::shared_ptr<ma_interfaces::msg::Slot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Slot_ & other) const
  {
    if (this->agent_id != other.agent_id) {
      return false;
    }
    if (this->owner_id != other.owner_id) {
      return false;
    }
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->st != other.st) {
      return false;
    }
    if (this->et != other.et) {
      return false;
    }
    if (this->x1 != other.x1) {
      return false;
    }
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->x2 != other.x2) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Slot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Slot_

// alias to use template instance with default allocator
using Slot =
  ma_interfaces::msg::Slot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__SLOT__STRUCT_HPP_
