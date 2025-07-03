#include "day4.h"

int main(int argc, char** argv) {
  MATRIX matrix;

  if (argc == 1) {
    std::cout << "Please provide a filepath to the input file!\n";
    return 1;
  }

  matrix = readInputDay4(argv[1]);

  std::cout << "The word XMAS occurs " << countWord(matrix, "XMAS", 4)
            << " times\n";
  freeMatrix(matrix.data, matrix.nrows);
  return 0;
}