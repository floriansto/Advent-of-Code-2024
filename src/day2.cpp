/**
 * Advent of Code 2024 - Day 2
 */

#include "day2.h"

/**
 * Check if levels in a report are valid.
 * If not return the iterator to the invalid level.
 */
auto areLevelsValid(const std::vector<int>& report, const Trend& trend) {
  auto it =
      std::adjacent_find(report.begin(), report.end(), [&trend](int a, int b) {
        if (a == b || std::abs(a - b) > 3) {
          return true;
        };
        if (trend == Trend::increasing && a > b ||
            trend == Trend::decreasing && a < b) {
          return true;
        }
        return false;
      });
  return it;
}

/**
 * Get the general trend of the report:
 * Count increasing and decreasing steps of the vector
 */
Trend getTrend(const std::vector<int>& report) {
  int numIncreasing{0};
  int numDecreasing{0};
  for (int i = 0; i < report.size() - 1; ++i) {
    if (report[i] < report[i + 1]) {
      ++numIncreasing;
    } else {
      ++numDecreasing;
    }
  }
  if (numIncreasing > numDecreasing) {
    return Trend::increasing;
  }
  if (numIncreasing < numDecreasing) {
    return Trend::decreasing;
  }
  return Trend::invalid;
}

bool checkReport(const std::vector<int>& report, const bool dampening) {
  int numIncreasing{0};
  int numDecreasing{0};
  int idx{0};
  int maxErrors = dampening ? 1 : 0;
  bool removedLevel{false};

  if (report.size() < 2) {
    return false;
  }

  Trend trend = getTrend(report);

  // Reports without trend with size of 3 can be fixed
  if (trend == Trend::invalid && report.size() > 3) {
    return false;
  }

  auto invalidLevel = areLevelsValid(report, trend);

  if (invalidLevel == report.end()) {
    return true;
  }

  if (!dampening || report.size() < 3) {
    return false;
  }

  // Get the index of the invalid part
  const int index = std::distance(report.begin(), invalidLevel);

  // Do a simple a/b test
  std::vector<int> first{report};
  std::vector<int> second{report};

  first.erase(first.begin() + index);
  if (areLevelsValid(first, trend) == first.end()) {
    return true;
  }
  if (index + 1 < second.size()) {
    second.erase(second.begin() + index + 1);
    if (areLevelsValid(second, trend) == second.end()) {
      return true;
    }
  }
  return false;
}

int countReports(const std::filesystem::path& filename, bool dampening) {
  std::ifstream input{filename};
  std::string line;
  int safeReports{0};

  if (!input.is_open()) {
    std::cout << "Unable to open file!\n";
    return -1;
  }

  while (std::getline(input, line)) {
    std::istringstream row{line};
    std::string level;
    std::vector<int> report;

    /* Read levels of the report */
    while (std::getline(row, level, ' ')) {
      report.push_back(std::stoi(level));
    }

    if (checkReport(report, dampening)) {
      ++safeReports;
    }
  }
  return safeReports;
}