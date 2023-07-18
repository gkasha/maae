// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ma_interfaces:msg/Slot.idl
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
#include "ma_interfaces/msg/detail/slot__struct.h"
#include "ma_interfaces/msg/detail/slot__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ma_interfaces__msg__slot__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[29];
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
    assert(strncmp("ma_interfaces.msg._slot.Slot", full_classname_dest, 28) == 0);
  }
  ma_interfaces__msg__Slot * ros_message = _ros_message;
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
  {  // owner_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "owner_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->owner_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // task_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->task_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // st
    PyObject * field = PyObject_GetAttrString(_pymsg, "st");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->st = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // et
    PyObject * field = PyObject_GetAttrString(_pymsg, "et");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->et = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x1
    PyObject * field = PyObject_GetAttrString(_pymsg, "x1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y1
    PyObject * field = PyObject_GetAttrString(_pymsg, "y1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x2
    PyObject * field = PyObject_GetAttrString(_pymsg, "x2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x2 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y2
    PyObject * field = PyObject_GetAttrString(_pymsg, "y2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y2 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ma_interfaces__msg__slot__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Slot */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ma_interfaces.msg._slot");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Slot");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ma_interfaces__msg__Slot * ros_message = (ma_interfaces__msg__Slot *)raw_ros_message;
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
  {  // owner_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->owner_id.data,
      strlen(ros_message->owner_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "owner_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->task_id.data,
      strlen(ros_message->task_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_id", field);
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
  {  // et
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->et);
    {
      int rc = PyObject_SetAttrString(_pymessage, "et", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
