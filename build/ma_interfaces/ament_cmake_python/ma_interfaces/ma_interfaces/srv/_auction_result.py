# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ma_interfaces:srv/AuctionResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AuctionResult_Request(type):
    """Metaclass of message 'AuctionResult_Request'."""

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
                'ma_interfaces.srv.AuctionResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__auction_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__auction_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__auction_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__auction_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__auction_result__request

            from ma_interfaces.msg import Bid
            if Bid.__class__._TYPE_SUPPORT is None:
                Bid.__class__.__import_type_support__()

            from ma_interfaces.msg import Task
            if Task.__class__._TYPE_SUPPORT is None:
                Task.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AuctionResult_Request(metaclass=Metaclass_AuctionResult_Request):
    """Message class 'AuctionResult_Request'."""

    __slots__ = [
        '_t',
        '_b',
    ]

    _fields_and_field_types = {
        't': 'ma_interfaces/Task',
        'b': 'ma_interfaces/Bid',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['ma_interfaces', 'msg'], 'Task'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['ma_interfaces', 'msg'], 'Bid'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from ma_interfaces.msg import Task
        self.t = kwargs.get('t', Task())
        from ma_interfaces.msg import Bid
        self.b = kwargs.get('b', Bid())

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
        if self.t != other.t:
            return False
        if self.b != other.b:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def t(self):
        """Message field 't'."""
        return self._t

    @t.setter
    def t(self, value):
        if __debug__:
            from ma_interfaces.msg import Task
            assert \
                isinstance(value, Task), \
                "The 't' field must be a sub message of type 'Task'"
        self._t = value

    @builtins.property
    def b(self):
        """Message field 'b'."""
        return self._b

    @b.setter
    def b(self, value):
        if __debug__:
            from ma_interfaces.msg import Bid
            assert \
                isinstance(value, Bid), \
                "The 'b' field must be a sub message of type 'Bid'"
        self._b = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_AuctionResult_Response(type):
    """Metaclass of message 'AuctionResult_Response'."""

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
                'ma_interfaces.srv.AuctionResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__auction_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__auction_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__auction_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__auction_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__auction_result__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AuctionResult_Response(metaclass=Metaclass_AuctionResult_Response):
    """Message class 'AuctionResult_Response'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


class Metaclass_AuctionResult(type):
    """Metaclass of service 'AuctionResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ma_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ma_interfaces.srv.AuctionResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__auction_result

            from ma_interfaces.srv import _auction_result
            if _auction_result.Metaclass_AuctionResult_Request._TYPE_SUPPORT is None:
                _auction_result.Metaclass_AuctionResult_Request.__import_type_support__()
            if _auction_result.Metaclass_AuctionResult_Response._TYPE_SUPPORT is None:
                _auction_result.Metaclass_AuctionResult_Response.__import_type_support__()


class AuctionResult(metaclass=Metaclass_AuctionResult):
    from ma_interfaces.srv._auction_result import AuctionResult_Request as Request
    from ma_interfaces.srv._auction_result import AuctionResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
