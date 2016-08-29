cmake_minimum_required(VERSION 3.6)
project(Assignment_1_SwapNumbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Text_File_Encoder.h Text_File_Encoder.cpp)
add_executable(Assignment_1_SwapNumbers ${SOURCE_FILES})