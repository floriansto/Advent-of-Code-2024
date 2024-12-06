#include <gtest/gtest.h>

#include "day2.h"

TEST(day2, TestSafeReports) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day2.txt";

  ASSERT_EQ(2, countSafeReports(filename));
}
