#include <gtest/gtest.h>

#include "day5.h"

TEST(day5, testSumMiddlePages) {
  std::filesystem::path file = std::filesystem::path(TEST_DATA) / "day5.txt";
  ASSERT_EQ(143, day5::calcMiddlePagenumberSum(file));
}
