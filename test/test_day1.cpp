#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "day1.h"

TEST(day1, TestMinimalDistance) {
  std::vector<int> first{3, 4, 2, 1, 3, 3};
  std::vector<int> second{4, 3, 5, 3, 9, 3};

  ASSERT_EQ(first.size(), second.size());
  ASSERT_EQ(11, calculateDistance(first, second));
}

TEST(day1, TestMinimalSimilarity) {
  std::vector<int> first{3, 4, 2, 1, 3, 3};
  std::vector<int> second{4, 3, 5, 3, 9, 3};

  ASSERT_EQ(first.size(), second.size());
  ASSERT_EQ(31, calculateSimilarity(first, second));
}
