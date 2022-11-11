cmake_minimum_required(VERSION 3.23)
project(task01)

# 声明位置
LINK_DIRECTORIES(/usr/local/lib)

link_libraries(/usr/local/lib/libntl.a)
#被链接的库相对路径
link_directories(/usr/local/lib /lib)
#被链接库的头文件相对路径
include_directories(/usr/local/include)

set(CMAKE_CXX_STANDARD 14)

add_executable(task01 main.cpp)


target_link_libraries(task01 -lm -lgmp -lntl -lpthread zmq)
