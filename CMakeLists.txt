cmake_minimum_required(VERSION 3.21)
project(lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_4 main.cpp Landscape.cpp Landscape.h fields/Field.h other/Enemy.h other/Enemy.cpp  tower/Tower.h tower/SimpleTower.cpp tower/SimpleTower.h tower/MagickTower.cpp tower/MagickTower.h tower/MagickTrap.cpp tower/MagickTrap.h fields/Forest.h fields/Road.h other/Lair.cpp other/Lair.h fields/Land.h other/Castle.cpp other/Castle.h other/Object.h)
