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

# 查找并且配置pybind11
set(pybind11_DIR /home/wmf1997/python313/lib/python3.13/site-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 REQUIRED)

# 创建pybind11的绑定库
pybind11_add_module(kathrein_util_pybind11 src/kathrein_util_pybind11.cpp) 

# 链接主库到pybind11模块
# 将之前编译完成的相应so文件, 进行链接
target_link_libraries(kathrein_util_pybind11 PRIVATE kathrein_util)

# 设置 pybind11 模块的包含目录
target_include_directories(kathrein_util_pybind11 PUBLIC include)
