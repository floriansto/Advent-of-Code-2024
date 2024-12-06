cmake_minimum_required(VERSION 3.31.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(aoc2024 VERSION 0.1.0)

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
            src/day1.cpp
            src/day2.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(test)
add_subdirectory(main)
