cmake_minimum_required(VERSION 3.6)
project(Assignment_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main_fraction.cpp fraction.cpp fraction.h)
add_executable(Assignment_3 ${SOURCE_FILES})
