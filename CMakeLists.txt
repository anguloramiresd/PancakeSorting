cmake_minimum_required(VERSION 3.20)
project(PancakeSorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(PancakeSorting main.cpp PancakePile.cpp PancakePile.h Headers.h)
