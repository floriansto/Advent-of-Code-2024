#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "day1.h"

TEST(day1, TestMinimalDistance) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day1.txt";
  std::array<std::vector<int>, 2> input = readInput(filename);

  ASSERT_EQ(input[0].size(), input[1].size());
  ASSERT_EQ(11, calculateDistance(input[0], input[1]));
}

TEST(day1, TestMinimalSimilarity) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day1.txt";
  std::array<std::vector<int>, 2> input = readInput(filename);

  ASSERT_EQ(input[0].size(), input[1].size());
  ASSERT_EQ(31, calculateSimilarity(input[0], input[1]));
}
