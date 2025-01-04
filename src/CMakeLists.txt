# 创建库目标
file(GLOB DEMO_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")
add_library(
    demo STATIC
    ${DEMO_SOURCES}
)

# 设置安装前缀为用户的主目录
set(CMAKE_INSTALL_PREFIX "$ENV{HOME}")

# 安装库文件
install(TARGETS demo
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# 安装头文件
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/include/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include)