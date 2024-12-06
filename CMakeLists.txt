cmake_minimum_required(VERSION 3.31.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("Advent-of-Code")

enable_testing()

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

add_subdirectory(day-1)
