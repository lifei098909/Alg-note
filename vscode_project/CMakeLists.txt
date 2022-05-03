cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main.c src/list.c src/array.c src/dynamic_programming.c src/common.c src/string_type.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
