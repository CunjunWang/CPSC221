cmake_minimum_required(VERSION 3.5)
project(Assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES linkedlist.cpp linkedlist.h ccqueue.cpp ccqueue.h Makefile a2simpledriver.cpp ticket.cpp ticket.h linkedlistprivate.h)
add_executable(Assignment2 ${SOURCE_FILES})