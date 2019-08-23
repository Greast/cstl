cmake_minimum_required (VERSION 3.9)
project (cstl VERSION 0.0.1 DESCRIPTION "Standard template library for C.")
include(GNUInstallDirs)

add_library(cstl SHARED
  src/alloc.c
)

set_target_properties(cstl PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER include/cstl.h
)

configure_file(cstl.pc.in cstl.pc @ONLY)
include_directories(.)
include_directories(include)

enable_testing()

add_executable(
  test-list
  tests/tests.c
  tests/tests.h
  tests/list.c
)

# depending on the framework, you need to link to it
target_link_libraries(
  test-list
  libcstl.so
)

target_link_libraries(
  test-list
  libcmocka.so
)
# now register the executable with CTest
add_test(NAME test-list COMMAND test-list )
