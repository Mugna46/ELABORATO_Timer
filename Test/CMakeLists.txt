cmake_minimum_required(VERSION 3.17)

add_subdirectory(lib)
set(gtest_SOURCE_DIR, lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES RunAllTest.cpp)

add_executable(Testing ${TEST_SOURCE_FILES})
target_link_libraries(Testing gtest gtest_main core)