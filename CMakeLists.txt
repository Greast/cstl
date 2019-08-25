cmake_minimum_required (VERSION 3.9)
project (cstl VERSION 0.0.1 DESCRIPTION "Standard template library for C.")
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(cstl SHARED
  src/alloc.c
)

target_compile_options(cstl PUBLIC -g)

set_target_properties(cstl PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER include/cstl.h
)

configure_file(cstl.pc.in cstl.pc @ONLY)
include_directories(.)
include_directories(include)
link_directories(${CMAKE_BINARY_DIR}/lib)
enable_testing()

add_executable(
  test-list
  tests/tests.c
  tests/tests.h
  tests/list.c
)

target_compile_options(test-list PRIVATE -g)

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
