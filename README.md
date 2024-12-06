# Advent of Code 2024

This repository contains my solutions to the [Advent of Code 2024](https://adventofcode.com/) in C++.

The idea is to build a library with all the algorithms.
The solution to each problem can link against this library.

The libray source files are located in `src`, the headers are in `include`.

The main files for each day are located in `main`.

The tests for the project are realized using GTest and are found in `tests`. The input of the tests are the given examples for each problem.

## Requirements

The project requires

* CMake 3.31.1
* C++23
* GTest framework

I ran this thing on my Arch Linux machine

## Building

First clone the repo

```
https://github.com/floriansto/Advent-of-Code-2024.git
```

then create the build directory and run cmake

```
$ mkdir build && cd build
$ cmake ..
```

## Running

From within the `build` directory run the solutions for each day with the respective input

```
./main/day1 ../main/input/day1.txt
```

For the tests, run the executable

```
./test/aoc2024_Test
```
