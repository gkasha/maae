// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ma_interfaces:srv/AddGoal.idl
// generated code does not contain a copyright notice

#ifndef MA_INTERFACES__SRV__DETAIL__ADD_GOAL__STRUCT_HPP_
#define MA_INTERFACES__SRV__DETAIL__ADD_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'g'
#include "ma_interfaces/msg/detail/goal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AddGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AddGoal_Request __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddGoal_Request_
{
  using Type = AddGoal_Request_<ContainerAllocator>;

  explicit AddGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : g(_init)
  {
    (void)_init;
  }

  explicit AddGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : g(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _g_type =
    ma_interfaces::msg::Goal_<ContainerAllocator>;
  _g_type g;

  // setters for named parameter idiom
  Type & set__g(
    const ma_interfaces::msg::Goal_<ContainerAllocator> & _arg)
  {
    this->g = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AddGoal_Request
    std::shared_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AddGoal_Request
    std::shared_ptr<ma_interfaces::srv::AddGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddGoal_Request_ & other) const
  {
    if (this->g != other.g) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddGoal_Request_

// alias to use template instance with default allocator
using AddGoal_Request =
  ma_interfaces::srv::AddGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces


#ifndef _WIN32
# define DEPRECATED__ma_interfaces__srv__AddGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__ma_interfaces__srv__AddGoal_Response __declspec(deprecated)
#endif

namespace ma_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddGoal_Response_
{
  using Type = AddGoal_Response_<ContainerAllocator>;

  explicit AddGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  explicit AddGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  // field types and members
  using _status_type =
    bool;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const bool & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ma_interfaces__srv__AddGoal_Response
    std::shared_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ma_interfaces__srv__AddGoal_Response
    std::shared_ptr<ma_interfaces::srv::AddGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddGoal_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddGoal_Response_

// alias to use template instance with default allocator
using AddGoal_Response =
  ma_interfaces::srv::AddGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ma_interfaces

namespace ma_interfaces
{

namespace srv
{

struct AddGoal
{
  using Request = ma_interfaces::srv::AddGoal_Request;
  using Response = ma_interfaces::srv::AddGoal_Response;
};

}  // namespace srv

}  // namespace ma_interfaces

#endif  // MA_INTERFACES__SRV__DETAIL__ADD_GOAL__STRUCT_HPP_
