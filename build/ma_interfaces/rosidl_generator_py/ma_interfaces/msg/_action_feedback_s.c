// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ma_interfaces:msg/ActionFeedback.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ma_interfaces/msg/detail/action_feedback__struct.h"
#include "ma_interfaces/msg/detail/action_feedback__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ma_interfaces__msg__action_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ma_interfaces.msg._action_feedback.ActionFeedback", full_classname_dest, 49) == 0);
  }
  ma_interfaces__msg__ActionFeedback * ros_message = _ros_message;
  {  // action_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->action_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // agent_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "agent_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->agent_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // st
    PyObject * field = PyObject_GetAttrString(_pymsg, "st");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->st = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // action_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_started");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->action_started = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // action_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_completed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->action_completed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // action_failed
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_failed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->action_failed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ma_interfaces__msg__action_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ActionFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ma_interfaces.msg._action_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ActionFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ma_interfaces__msg__ActionFeedback * ros_message = (ma_interfaces__msg__ActionFeedback *)raw_ros_message;
  {  // action_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->action_id.data,
      strlen(ros_message->action_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agent_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->agent_id.data,
      strlen(ros_message->agent_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "agent_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // st
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->st);
    {
      int rc = PyObject_SetAttrString(_pymessage, "st", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // action_started
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->action_started);
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // action_completed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->action_completed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // action_failed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->action_failed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_failed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
