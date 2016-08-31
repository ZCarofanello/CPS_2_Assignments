cmake_minimum_required(VERSION 3.6)
project(Assignment_2_Fractions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Fractions.cpp)
add_executable(Assignment_2_Fractions ${SOURCE_FILES})