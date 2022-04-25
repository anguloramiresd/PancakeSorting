cmake_minimum_required(VERSION 3.20)
project(PancakeSorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(PancakeSorting main.cpp Headers.h SortPancakes.cpp SortPancakes.h SortExhaustive.cpp SortExhaustive.h Sort3Approximation.cpp Sort3Approximation.h Sort2Approximation.cpp Sort2Approximation.h)
