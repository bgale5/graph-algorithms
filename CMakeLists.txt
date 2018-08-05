cmake_minimum_required(VERSION 3.12)
project(graphing_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_library(graphing_algorithms graphing.cpp graphing.h)
add_executable(test test.cpp)
target_link_libraries(test graphing_algorithms)
