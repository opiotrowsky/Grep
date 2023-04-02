cmake_minimum_required(VERSION 3.10)
project(MyGrep)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}-lib STATIC MyGrep.cpp)

add_executable(${PROJECT_NAME} main.cpp MyGrep.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)