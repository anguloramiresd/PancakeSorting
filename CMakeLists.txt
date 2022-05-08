cmake_minimum_required(VERSION 3.20)
project(PancakeSorting)

add_subdirectory(pancake-tests)

include_directories(pancake-files)
add_subdirectory(pancake-files)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExhaustiveMeasure measure.cpp)
add_executable(Run user.cpp)

target_link_libraries(Run pancake-files)
target_link_libraries(ExhaustiveMeasure pancake-files)