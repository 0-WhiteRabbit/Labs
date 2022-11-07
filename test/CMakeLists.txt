cmake_minimum_required(VERSION 3.21)
project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(tests test.cpp ../train_3.cpp ../train_3.h)
target_link_libraries(tests gtest gtest_main)
