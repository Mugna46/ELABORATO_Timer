cmake_minimum_required(VERSION 3.17)
project(ELABORATO_Timer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(Test)
set(SOURCE_FILES main.cpp Time.cpp Time.h Date.cpp Date.h Observer.h Subject.h Timer.cpp Timer.h WxWindow.cpp WxWindow.h)
add_executable(ELABORATO_Timer main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ELABORATO_Timer core)
target_link_libraries(ELABORATO_Timer ${wxWidgets_LIBRARIES})