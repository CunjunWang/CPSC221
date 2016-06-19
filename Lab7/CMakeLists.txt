cmake_minimum_required(VERSION 3.5)
project(Lab7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hashtable.cpp hashtable.h lab7driver.cpp Makefile)
add_executable(Lab7 ${SOURCE_FILES})