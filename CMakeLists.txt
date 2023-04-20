cmake_minimum_required(VERSION 3.10)
project(MyGrep)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}-lib STATIC MyGrep.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
add_executable(${PROJECT_NAME}-ut test.cpp)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib Catch2::Catch2WithMain)