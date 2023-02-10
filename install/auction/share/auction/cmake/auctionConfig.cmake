# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_auction_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED auction_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(auction_FOUND FALSE)
  elseif(NOT auction_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(auction_FOUND FALSE)
  endif()
  return()
endif()
set(_auction_CONFIG_INCLUDED TRUE)

# output package information
if(NOT auction_FIND_QUIETLY)
  message(STATUS "Found auction: 0.0.0 (${auction_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'auction' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${auction_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(auction_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${auction_DIR}/${_extra}")
endforeach()
