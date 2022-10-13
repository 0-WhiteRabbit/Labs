cmake_minimum_required(VERSION 3.21)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)
ADD_LIBRARY( train STATIC train.cpp train.h)

add_executable(lab_3 main.cpp)

TARGET_LINK_LIBRARIES(lab_3 train)