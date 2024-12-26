cmake_minimum_required(VERSION 3.10)
project(stack)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_library(stack stack.c)

add_executable(main main.c)

target_link_libraries(main stack)
add_executable(tests tests.c stack.c)
target_link_libraries(tests stack gcov)
add_executable(benchmark benchmark.c stack.c)
target_link_libraries(benchmark stack gcov)
