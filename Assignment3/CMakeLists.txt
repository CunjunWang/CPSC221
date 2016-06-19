cmake_minimum_required(VERSION 3.5)
project(Assignment3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Makefile rbtree.cpp rbtree.h rbtreepartial.cpp rbtreeprivate.h stockitem.cpp stockitem.h stocksystem.h a3simpledriver.cpp stocksystem.cpp)
add_executable(Assignment3 ${SOURCE_FILES})