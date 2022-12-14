#
# Copyright (c) 2018 Mateusz Loskot <mateusz at loskot dot net>
# Copyright (c) 2021 Pranam Lashkari <plashkari628@gmail.com>
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#
foreach(_name
  algorithm_channel_arithmetic
  algorithm_channel_convert
  algorithm_channel_invert
  algorithm_channel_multiply
  algorithm_channel_relation
  channel_traits
  concepts
  is_channel_integral
  packed_channel_value
  scoped_channel_value
  test_fixture
  channel_numeric_operations)
  set(_test t_core_channel_${_name})
  set(_target test_core_channel_${_name})

  add_executable(${_target} "")
  target_sources(${_target} PRIVATE ${_name}.cpp)
  target_link_libraries(${_target}
    PRIVATE
      gil_compile_options
      gil_include_directories
      gil_dependencies)
  target_compile_definitions(${_target} PRIVATE BOOST_GIL_USE_CONCEPT_CHECK)
  add_test(NAME ${_test} COMMAND ${_target})

  unset(_name)
  unset(_target)
endforeach()
