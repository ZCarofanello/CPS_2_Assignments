cmake_minimum_required(VERSION 3.6)
project(Assignment_7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp LCG.cpp LCG.h)
add_executable(Assignment_7 ${SOURCE_FILES})