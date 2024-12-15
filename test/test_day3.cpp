
#include <gtest/gtest.h>

#include "day3.h"

TEST(day3, TestMultiplySum) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day3.txt";

  ASSERT_EQ(161, sumOfMultiplications(filename, false));
}

TEST(day3, TestMultiplySumConditionals) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day3.txt";

  ASSERT_EQ(48, sumOfMultiplications(filename, true));
}

TEST(day3, TestMultiplySumMain) {
  const std::filesystem::path filename = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day3.txt";

  ASSERT_EQ(159892596, sumOfMultiplications(filename, false));
}

TEST(day3, TestMultiplySumMainConditionals) {
  const std::filesystem::path filename = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day3.txt";

  ASSERT_EQ(92626942, sumOfMultiplications(filename, true));
}