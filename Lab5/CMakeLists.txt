cmake_minimum_required(VERSION 3.5)
project(Lab5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES bst.cpp unit.cpp unit.h Makefile.txt)
add_executable(Lab5 ${SOURCE_FILES})