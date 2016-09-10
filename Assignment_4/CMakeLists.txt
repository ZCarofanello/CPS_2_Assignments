cmake_minimum_required(VERSION 3.6)
project(Assignment_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Fractions.h Fractions.cpp Metrics.cpp Metrics.h)
add_executable(Assignment_4 ${SOURCE_FILES})