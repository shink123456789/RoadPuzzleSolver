file(MAKE_DIRECTORY bin)
set(CMAKE_VERBOSE_MAKEFILE 1)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror -std=c++1y")
include_directories( )
link_directories( )
add_executable(bin/rpsolver
     src/main.cpp
     src/PuzzleState.cpp
     src/PuzzlePiece.cpp
     src/Position.cpp
     src/RoadPuzzleSolver.cpp
     src/PuzzleField.cpp
     src/RoadAct.cpp
     src/Position.cpp
)
target_link_libraries( bin/rpsolver )
