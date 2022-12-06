cmake_minimum_required(VERSION 3.21)
project(lab_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_4 main.cpp Landscape.cpp Landscape.h fields/Field.h other/Enemy.h other/Enemy.cpp  tower/Tower.h tower/SimpleTower.cpp tower/SimpleTower.h tower/MagicTower.cpp tower/MagicTower.h tower/MagicTrap.cpp tower/MagicTrap.h fields/Forest.h fields/Road.h other/Lair.cpp other/Lair.h fields/Land.h other/Castle.cpp other/Castle.h other/Object.h tower/Tower.cpp vector/Vector.h)
