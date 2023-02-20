# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ma_interfaces:msg/ActionFeedback.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ActionFeedback(type):
    """Metaclass of message 'ActionFeedback'."""

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
                'ma_interfaces.msg.ActionFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__action_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__action_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__action_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__action_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__action_feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ActionFeedback(metaclass=Metaclass_ActionFeedback):
    """Message class 'ActionFeedback'."""

    __slots__ = [
        '_action_id',
        '_agent_id',
        '_name',
        '_action_started',
        '_action_completed',
        '_action_failed',
    ]

    _fields_and_field_types = {
        'action_id': 'string',
        'agent_id': 'string',
        'name': 'string',
        'action_started': 'int32',
        'action_completed': 'int32',
        'action_failed': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.action_id = kwargs.get('action_id', str())
        self.agent_id = kwargs.get('agent_id', str())
        self.name = kwargs.get('name', str())
        self.action_started = kwargs.get('action_started', int())
        self.action_completed = kwargs.get('action_completed', int())
        self.action_failed = kwargs.get('action_failed', int())

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
        if self.action_id != other.action_id:
            return False
        if self.agent_id != other.agent_id:
            return False
        if self.name != other.name:
            return False
        if self.action_started != other.action_started:
            return False
        if self.action_completed != other.action_completed:
            return False
        if self.action_failed != other.action_failed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def action_id(self):
        """Message field 'action_id'."""
        return self._action_id

    @action_id.setter
    def action_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_id' field must be of type 'str'"
        self._action_id = value

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
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def action_started(self):
        """Message field 'action_started'."""
        return self._action_started

    @action_started.setter
    def action_started(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_started' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'action_started' field must be an integer in [-2147483648, 2147483647]"
        self._action_started = value

    @builtins.property
    def action_completed(self):
        """Message field 'action_completed'."""
        return self._action_completed

    @action_completed.setter
    def action_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_completed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'action_completed' field must be an integer in [-2147483648, 2147483647]"
        self._action_completed = value

    @builtins.property
    def action_failed(self):
        """Message field 'action_failed'."""
        return self._action_failed

    @action_failed.setter
    def action_failed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_failed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'action_failed' field must be an integer in [-2147483648, 2147483647]"
        self._action_failed = value
