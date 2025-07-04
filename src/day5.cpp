#include "day5.h"

bool day5::checkCorrectOrder(
    const std::unordered_map<uint16_t, std::vector<uint16_t>> &map,
    const std::vector<uint16_t> &reference) {
  uint16_t startIdx;

  startIdx = 0;
  for (uint16_t i : reference) {
    // Make sure the current number is accessible
    auto key = map.find(i);
    if (key == map.end()) {
      return false;
    }

    ++startIdx;
    for (auto it = reference.begin() + startIdx; it != reference.end(); ++it) {
      // Check if the following numbers in the reference are ordered correctly
      if (std::find(key->second.begin(), key->second.end(), *it) ==
          key->second.end()) {
        return false;
      }
    }
  }
  return true;
}

uint16_t day5::calcMiddlePagenumberSum(const std::filesystem::path &path) {
  std::ifstream input{path};
  std::string line;
  std::string pageNumber;
  std::unordered_map<uint16_t, std::vector<uint16_t>> printOrderRules;
  std::vector<uint16_t> updatePages;
  uint16_t key;
  uint16_t middlePageCount{0};
  uint16_t index;
  bool parseOrderRules{true};

  if (!input.is_open()) {
    std::cout << "Error opening the file " << path << "\n";
    return 0;
  }

  while (std::getline(input, line)) {
    // Switch input parsing style on a newline
    if (line == "") {
      parseOrderRules = false;
      continue;
    }

    // Parse page ordering into a hashmap
    // Key is the leading page, the value is a vector of page numbers that must
    // occur after the key
    if (parseOrderRules) {
      std::stringstream lineStream{line};
      key = 0;
      while (std::getline(lineStream, pageNumber, '|')) {
        if (key == 0) {
          key = stoi(pageNumber);
          continue;
        }
        printOrderRules[key].push_back(stoi(pageNumber));
      }
      continue;
    }

    // Parse sequence of pages
    updatePages.clear();
    std::stringstream lineStream{line};
    while (std::getline(lineStream, pageNumber, ',')) {
      updatePages.push_back(stoi(pageNumber));
    }

    // Check if they are correctly ordered
    if (!checkCorrectOrder(printOrderRules, updatePages)) {
      continue;
    }

    // Add the middle page number to the sum
    index = (updatePages.size() - 1) / 2;
    middlePageCount += updatePages[index];
  }

  input.close();
  return middlePageCount;
}