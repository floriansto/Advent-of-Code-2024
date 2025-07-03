#include <gtest/gtest.h>

#include "day4.h"

TEST(day4, testReadInput) {
  const std::filesystem::path testfile =
      std::filesystem::path(TEST_DATA) / "day4.txt";

  MATRIX matrix = readInputDay4(testfile);
  ASSERT_EQ(10, matrix.nrows);
  ASSERT_EQ(10, matrix.ncols);

  freeMatrix(matrix.data, matrix.nrows);
}

TEST(day4, testXmasCount) {
  const std::filesystem::path testfile =
      std::filesystem::path(TEST_DATA) / "day4.txt";

  MATRIX matrix = readInputDay4(testfile);
  ASSERT_EQ(18, countWord(matrix, "XMAS", 4));

  freeMatrix(matrix.data, matrix.nrows);
}

TEST(day4, testXmasCountMain) {
  const std::filesystem::path testfile = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day4.txt";

  MATRIX matrix = readInputDay4(testfile);
  ASSERT_EQ(2378, countWord(matrix, "XMAS", 4));

  freeMatrix(matrix.data, matrix.nrows);
}