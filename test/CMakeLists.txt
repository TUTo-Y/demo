# 指定库的头文件
target_include_directories(demo PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

# 创建可执行文件目标
add_executable(main test.c)

# 链接库到可执行文件
target_link_libraries(main PRIVATE demo)