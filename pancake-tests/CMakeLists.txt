project(pancake-tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run 2approx-tests.cpp 3approx-tests.cpp)

target_link_libraries(Google_Tests_run pancake-files)
target_link_libraries(Google_Tests_run gtest gtest_main)
