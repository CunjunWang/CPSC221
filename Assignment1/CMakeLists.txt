cmake_minimum_required(VERSION 3.5)
project(Assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Largest.cpp)
add_executable(Assignment ${SOURCE_FILES})