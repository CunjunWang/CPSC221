cmake_minimum_required(VERSION 3.5)
project(Lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES insertion.cpp insertion.h Makefile q4.cpp)
add_executable(Lab2 ${SOURCE_FILES})