// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:msg/Bid.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__MSG__DETAIL__BID__STRUCT_HPP_
#define MA_INTERFACES__MSG__DETAIL__BID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__msg__Bid __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__msg__Bid __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Bid_
{
  using Type = Bid_<ContainerAllocator>;

  explicit Bid_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = "";
      this->auction_id = "";
      this->status = 0l;
      this->st = 0.0;
      this->et = 0.0;
      this->value = 0ll;
    }
  }

  explicit Bid_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : agent_id(_alloc),
    auction_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = "";
      this->auction_id = "";
      this->status = 0l;
      this->st = 0.0;
      this->et = 0.0;
      this->value = 0ll;
    }
  }

  // field types and members
  using _agent_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agent_id_type agent_id;
  using _auction_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _auction_id_type auction_id;
  using _status_type =
    int32_t;
  _status_type status;
  using _st_type =
    double;
  _st_type st;
  using _et_type =
    double;
  _et_type et;
  using _value_type =
    int64_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__agent_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agent_id = _arg;
    return *this;
  }
  Type & set__auction_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->auction_id = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
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
  Type & set__value(
    const int64_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::msg::Bid_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::msg::Bid_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::msg::Bid_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::msg::Bid_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Bid_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Bid_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::msg::Bid_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::msg::Bid_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::msg::Bid_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::msg::Bid_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__msg__Bid
    std::shared_ptr<ma_interfaces::msg::Bid_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__msg__Bid
    std::shared_ptr<ma_interfaces::msg::Bid_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bid_ & other) const
  {
    if (this->agent_id != other.agent_id) {
      return false;
    }
    if (this->auction_id != other.auction_id) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->st != other.st) {
      return false;
    }
    if (this->et != other.et) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bid_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bid_

// alias to use template instance with default allocator
using Bid =
  ma_interfaces::msg::Bid_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__MSG__DETAIL__BID__STRUCT_HPP_
