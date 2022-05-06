project(pancake-files)

set(HEADER_FILES
        Headers.h
        Sort2Approximation.h
        Sort3Approximation.h
        SortExhaustive.h
        SortPancakes.h
        )

set(SOURCE_FILES
        Sort2Approximation.cpp
        Sort3Approximation.cpp
        SortExhaustive.cpp
        SortPancakes.cpp
        )

add_library(pancake-files STATIC ${SOURCE_FILES} ${HEADER_FILES})