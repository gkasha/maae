# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ma_interfaces:msg/Slot.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Slot(type):
    """Metaclass of message 'Slot'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ma_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ma_interfaces.msg.Slot')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__slot
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__slot
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__slot
            cls._TYPE_SUPPORT = module.type_support_msg__msg__slot
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__slot

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Slot(metaclass=Metaclass_Slot):
    """Message class 'Slot'."""

    __slots__ = [
        '_agent_id',
        '_owner_id',
        '_task_id',
        '_st',
        '_et',
        '_x1',
        '_y1',
        '_x2',
        '_y2',
        '_speed',
    ]

    _fields_and_field_types = {
        'agent_id': 'string',
        'owner_id': 'string',
        'task_id': 'string',
        'st': 'double',
        'et': 'double',
        'x1': 'double',
        'y1': 'double',
        'x2': 'double',
        'y2': 'double',
        'speed': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.agent_id = kwargs.get('agent_id', str())
        self.owner_id = kwargs.get('owner_id', str())
        self.task_id = kwargs.get('task_id', str())
        self.st = kwargs.get('st', float())
        self.et = kwargs.get('et', float())
        self.x1 = kwargs.get('x1', float())
        self.y1 = kwargs.get('y1', float())
        self.x2 = kwargs.get('x2', float())
        self.y2 = kwargs.get('y2', float())
        self.speed = kwargs.get('speed', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.agent_id != other.agent_id:
            return False
        if self.owner_id != other.owner_id:
            return False
        if self.task_id != other.task_id:
            return False
        if self.st != other.st:
            return False
        if self.et != other.et:
            return False
        if self.x1 != other.x1:
            return False
        if self.y1 != other.y1:
            return False
        if self.x2 != other.x2:
            return False
        if self.y2 != other.y2:
            return False
        if self.speed != other.speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def agent_id(self):
        """Message field 'agent_id'."""
        return self._agent_id

    @agent_id.setter
    def agent_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'agent_id' field must be of type 'str'"
        self._agent_id = value

    @builtins.property
    def owner_id(self):
        """Message field 'owner_id'."""
        return self._owner_id

    @owner_id.setter
    def owner_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'owner_id' field must be of type 'str'"
        self._owner_id = value

    @builtins.property
    def task_id(self):
        """Message field 'task_id'."""
        return self._task_id

    @task_id.setter
    def task_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'task_id' field must be of type 'str'"
        self._task_id = value

    @builtins.property
    def st(self):
        """Message field 'st'."""
        return self._st

    @st.setter
    def st(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'st' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'st' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._st = value

    @builtins.property
    def et(self):
        """Message field 'et'."""
        return self._et

    @et.setter
    def et(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'et' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'et' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._et = value

    @builtins.property
    def x1(self):
        """Message field 'x1'."""
        return self._x1

    @x1.setter
    def x1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x1 = value

    @builtins.property
    def y1(self):
        """Message field 'y1'."""
        return self._y1

    @y1.setter
    def y1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y1 = value

    @builtins.property
    def x2(self):
        """Message field 'x2'."""
        return self._x2

    @x2.setter
    def x2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x2 = value

    @builtins.property
    def y2(self):
        """Message field 'y2'."""
        return self._y2

    @y2.setter
    def y2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y2 = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value