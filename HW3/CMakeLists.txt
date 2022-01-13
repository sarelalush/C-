cmake_minimum_required(VERSION 3.17)
project(HW3)

set(CMAKE_CXX_STANDARD 98)

add_executable(HW3 main.cpp Disc.h Disc.cpp DiscList.cpp DiscList.h Table.cpp Table.h Vector2D.cpp Vector2D.h Wall.cpp Wall.h WallList.h WallList.cpp ShrinkingDisc.cpp ShrinkingDisc.h ExplodingDisc.cpp ExplodingDisc.h )