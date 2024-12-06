/**
 * Advent of Code 2024 - Day 2
 */

#include "day2.h"

int countSafeReports(const std::filesystem::path& filename) {
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

    while (std::getline(row, level, ' ')) {
      report.push_back(std::stoi(level));
    }

    bool increasing{true};
    bool valid{true};

    if (report.size() < 2) {
      continue;
    }

    if (report[1] < report[0]) {
      increasing = false;
    }

    for (int i = 0; i < report.size() - 1; ++i) {
      if (increasing && report[i + 1] > report[i] &&
          report[i + 1] - report[i] < 4) {
        continue;
      }
      if (!increasing && report[i + 1] < report[i] &&
          report[i] - report[i + 1] < 4) {
        continue;
      }
      valid = false;
      break;
    }
    if (valid) {
      ++safeReports;
    }
  }
  return safeReports;
}