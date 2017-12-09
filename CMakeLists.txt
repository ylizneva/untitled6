cmake_minimum_required(VERSION 3.8)
project(untitled6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
      TestShape.cpp Box.cpp Box.h Coord.h Coord.cpp Shape.cpp Shape.h HorisontalShape.cpp HorisontalShape.h VerticalShape.cpp VerticalShape.h)
add_executable(untitled6 ${SOURCE_FILES})