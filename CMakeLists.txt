# 最低版本要求
cmake_minimum_required(VERSION 3.5.0)

# 定义项目名称和版本
project(demo VERSION 1.0)

# 设置C语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)

# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)

# 添加子目录
add_subdirectory(src)
add_subdirectory(test)
