cmake_minimum_required(VERSION 3.20)
project(PancakeSorting)

add_subdirectory(pancake-tests)

include_directories(pancake-files)
add_subdirectory(pancake-files)

set(CMAKE_CXX_STANDARD 14)

add_executable(PancakeSorting pancake-files/main.cpp pancake-files/Headers.h pancake-files/SortPancakes.cpp pancake-files/SortPancakes.h pancake-files/SortExhaustive.cpp pancake-files/SortExhaustive.h pancake-files/Sort3Approximation.cpp pancake-files/Sort3Approximation.h pancake-files/Sort2Approximation.cpp pancake-files/Sort2Approximation.h)
