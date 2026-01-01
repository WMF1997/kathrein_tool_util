cmake_minimum_required(VERSION 3.10)

project(kathrein_tool_util VERSION 0.1)

# C++11标准
set(CMAKE_CXX_STANDARD 11)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含头文件目录
include_directories(include)

# 定义源文件, 以及相应的头文件的路径
set(SOURCES
    src/kathrein_util.cpp
)

set(HEADERS
    include/kathrein_util.h
)

# 目标信息
add_library(kathrein_util SHARED ${SOURCES})
add_executable(kathrein_util_exec src/main_test.cpp)

# 设置目标包含目录
target_include_directories(kathrein_util PUBLIC include)
target_include_directories(kathrein_util_exec PUBLIC include)

# 链接库
target_link_libraries(kathrein_util_exec kathrein_util) 
