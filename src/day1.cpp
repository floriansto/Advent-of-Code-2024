/**
 * Advent of Code 2024 - Day 1
 * Reading and comparing lists
 */

#include "day1.h"

int calculateDistance(std::vector<int>& first, std::vector<int>& second) {
  int distance{0};

  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());

  for (std::tuple<int&, int&> elem : std::views::zip(first, second)) {
    distance += std::abs(std::get<0>(elem) - std::get<1>(elem));
  }

  return distance;
}

int calculateSimilarity(std::vector<int>& first, std::vector<int>& second) {
  int similarity{0};
  int start{0};
  int amount{0};
  int previous{0};

  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());

  for (int i : first) {
    if (previous == i) {
      similarity += i * amount;
      continue;
    }
    amount = 0;
    for (int j = start; j < second.size(); ++j) {
      if (second[j] < i) {
        continue;
      }
      if (second[j] > i) {
        start = j;
        break;
      }
      ++amount;
    }
    similarity += i * amount;
    previous = i;
  }
  return similarity;
}

std::array<std::vector<int>, 2> readInput(
    const std::filesystem::path& filename) {
  std::string line;
  std::string first;
  std::string second;
  std::string delimiter{"   "};
  std::ifstream input{filename};
  std::array<std::vector<int>, 2> result;

  if (!input.is_open()) {
    std::cout << "Unable to open file!\n";
    return result;
  }

  while (std::getline(input, line)) {
    first = line.substr(0, line.find(delimiter));
    second =
        line.substr(line.find(delimiter) + delimiter.length(), line.length());

    result[0].push_back(std::stoi(first));
    result[1].push_back(std::stoi(second));
  }
  input.close();
  return result;
}
