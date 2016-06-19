cmake_minimum_required(VERSION 3.5)
project(Lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES qsortcount.cpp)
add_executable(Lab6 ${SOURCE_FILES})