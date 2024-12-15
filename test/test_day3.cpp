
#include <gtest/gtest.h>

#include "day3.h"

TEST(day3, TestMultiplySum) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day3.txt";

  ASSERT_EQ(161, sumOfMultiplications(filename));
}

TEST(day3, TestMultiplySumMain) {
  const std::filesystem::path filename = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day3.txt";

  ASSERT_EQ(159892596, sumOfMultiplications(filename));
}