cmake_minimum_required(VERSION 3.21)
project(lab_3_external)

set(CMAKE_CXX_STANDARD 14)

ADD_LIBRARY(plat STATIC lib/pcb.hpp lib/pcb.cpp)

add_executable(lab_3_external main.cpp)

TARGET_LINK_LIBRARIES(lab_3_external plat)