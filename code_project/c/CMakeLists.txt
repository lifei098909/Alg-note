cmake_minimum_required(VERSION 3.1.0)
project(leetcode VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
include(CTest)
enable_testing()

include_directories(./include)

add_subdirectory(src/array)
add_subdirectory(src/list)
add_subdirectory(src/dp)

add_executable(src/string_type.c include/common.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
