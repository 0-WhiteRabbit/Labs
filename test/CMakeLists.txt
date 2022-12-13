cmake_minimum_required(VERSION 3.21)
project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(tests test_landscape.cpp ../Landscape.cpp ../Landscape.h ../fields/Field.h ../other/Enemy.h ../other/Enemy.cpp  ../tower/Tower.h
        ../tower/SimpleTower.cpp ../tower/SimpleTower.h ../tower/MagicTower.cpp ../tower/MagicTower.h ../tower/MagicTrap.cpp ../tower/MagicTrap.h
        ../fields/Forest.h ../fields/Road.h ../other/Lair.cpp ../other/Lair.h ../fields/Land.h ../other/Castle.cpp ../other/Castle.h ../other/Object.h
        ../tower/Tower.cpp ../vector/Vector.h CastleTest.cpp CastleTest.h)
target_link_libraries(tests gtest gtest_main)
