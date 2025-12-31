cmake_minimum_required(VERSION 3.10)

project(kathrein_tool_util VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
# target information

add_library(kathrein_util SHARED kathrein_util.cpp)
add_executable(kathrein_util_exec main_test.cpp)

target_include_directories(kathrein_util PUBLIC .)
target_link_libraries(kathrein_util_exec kathrein_util)

