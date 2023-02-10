// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:srv/AuctionSrv.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_HPP_
#define MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AuctionSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AuctionSrv_Request __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AuctionSrv_Request_
{
  using Type = AuctionSrv_Request_<ContainerAllocator>;

  explicit AuctionSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit AuctionSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AuctionSrv_Request
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AuctionSrv_Request
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AuctionSrv_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const AuctionSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AuctionSrv_Request_

// alias to use template instance with default allocator
using AuctionSrv_Request =
  ma_interfaces::srv::AuctionSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AuctionSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AuctionSrv_Response __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AuctionSrv_Response_
{
  using Type = AuctionSrv_Response_<ContainerAllocator>;

  explicit AuctionSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit AuctionSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AuctionSrv_Response
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AuctionSrv_Response
    std::shared_ptr<ma_interfaces::srv::AuctionSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AuctionSrv_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const AuctionSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AuctionSrv_Response_

// alias to use template instance with default allocator
using AuctionSrv_Response =
  ma_interfaces::srv::AuctionSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces

namespace ma_interfaces
{

namespace srv
{

struct AuctionSrv
{
  using Request = ma_interfaces::srv::AuctionSrv_Request;
  using Response = ma_interfaces::srv::AuctionSrv_Response;
};

}  // namespace srv

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__AUCTION_SRV__STRUCT_HPP_
