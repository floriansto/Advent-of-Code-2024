#include <gtest/gtest.h>

#include "day2.h"

TEST(day2, TestSafeReports) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day2.txt";

  ASSERT_EQ(2, countReports(filename, false));
}

TEST(day2, TestSafeReportsMain) {
  const std::filesystem::path filename = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day2.txt";

  ASSERT_EQ(383, countReports(filename, false));
}

TEST(day2, TestDampenedSafeReports) {
  const std::filesystem::path filename =
      std::filesystem::path(TEST_DATA) / "day2.txt";
  ASSERT_EQ(4, countReports(filename, true));
}

TEST(day2, TestDampenedSafeReportsMain) {
  const std::filesystem::path filename = std::filesystem::path(TEST_DATA) /
                                         ".." / ".." / "main" / "input" /
                                         "day2.txt";

  ASSERT_EQ(436, countReports(filename, true));
}

TEST(day2, TestDampenedSafeReportsCustomData1) {
  std::vector<int> report{0, 0};
  ASSERT_FALSE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData2) {
  std::vector<int> report{7, 1, 2};
  ASSERT_TRUE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData3) {
  std::vector<int> report{0, 0, 0};
  ASSERT_FALSE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData4) {
  std::vector<int> report{1, 2, 7};
  ASSERT_TRUE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData5) {
  std::vector<int> report{1, 7, 6};
  ASSERT_TRUE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData6) {
  std::vector<int> report{9, 7, 1};
  ASSERT_TRUE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData7) {
  std::vector<int> report{1, 5, 4, 5};
  ASSERT_TRUE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData8) {
  std::vector<int> report{9, 7, 1, 0};
  ASSERT_FALSE(checkReport(report, true));
}

TEST(day2, TestDampenedSafeReportsCustomData9) {
  std::vector<int> report{9, 7, 7, 5};
  ASSERT_FALSE(checkReport(report, false));
}

TEST(day2, TestDampenedSafeReportsCustomData10) {
  std::vector<int> report{6, 7, 7, 8};
  ASSERT_FALSE(checkReport(report, false));
}

TEST(day2, TestDampenedSafeReportsCustomData11) {
  std::vector<int> report{6, 7, 5, 4};
  ASSERT_FALSE(checkReport(report, false));
}

TEST(day2, TestDampenedSafeReportsCustomData12) {
  std::vector<int> report{6, 5, 7, 4};
  ASSERT_FALSE(checkReport(report, false));
}