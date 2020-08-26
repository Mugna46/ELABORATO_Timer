cmake_minimum_required(VERSION 3.17)
project(ELABORATO_Timer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_subdirectory(Test)
set(SOURCE_FILES main.cpp Time.cpp Time.h)
add_executable(ELABORATO_Timer main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ELABORATO_Timer core)