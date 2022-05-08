project(pancake-files)

set(HEADER_FILES
        include/Headers.h
        include/Sort2Approximation.h
        include/Sort3Approximation.h
        include/SortExhaustive.h
        include/SortPancakes.h
        )

set(SOURCE_FILES
        src/Sort2Approximation.cpp
        src/Sort3Approximation.cpp
        src/SortExhaustive.cpp
        src/SortPancakes.cpp
        )

add_library(pancake-files STATIC ${SOURCE_FILES} ${HEADER_FILES})