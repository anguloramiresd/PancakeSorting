cmake_minimum_required(VERSION 3.20)
project(PancakeSorting)

add_subdirectory(pancake-tests)

include_directories(pancake-files)
add_subdirectory(pancake-files)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExhaustiveMeasure measure.cpp)
add_executable(MeasureApproximations measure_2_3.cpp)
add_executable(Run user.cpp)
add_executable(Run_GUI user_GUI.cpp)

target_link_libraries(Run pancake-files)
target_link_libraries(Run_GUI pancake-files)
target_link_libraries(ExhaustiveMeasure pancake-files)
target_link_libraries(MeasureApproximations pancake-files)