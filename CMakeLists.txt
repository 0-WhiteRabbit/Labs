cmake_minimum_required(VERSION 3.21)
project(lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_4 main.cpp Landscape.cpp Landscape.h fields/Field.cpp fields/Field.h Enemie.cpp Enemie.h tower/Tower.cpp tower/Tower.h tower/SimpleTower.cpp tower/SimpleTower.h tower/MagickTower.cpp tower/MagickTower.h tower/MagickTrap.cpp tower/MagickTrap.h fields/Forest.h fields/Road.h fields/Lair.cpp fields/Lair.h fields/Land.h fields/Castle.cpp fields/Castle.h)
