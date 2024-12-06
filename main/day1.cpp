/**
 * Advent of Code 2024 - Day 1
 * Reading and comparing lists
 */

#include "day1.h"

/**
 * Read a file with two columns of integers separated by three spaces.
 * Then sort the two colums, subtract them from each other and caluclate the sum
 * of the result.
 * @return 0 in case of success, 1 if no input file was found or the input file
 * was faulty
 */
int main(int argc, char** argv) {
  std::array<std::vector<int>, 2> input;
  int distance;
  int similarity;

  if (argc == 1) {
    std::cerr << "Provide the path to the input file!\n";
    return 1;
  }

  const std::filesystem::path filename{argv[1]};

  if (!std::filesystem::exists(filename)) {
    std::cerr << "File " << filename << "does not exist!\n";
    return 1;
  }

  input = readInput(filename);

  if (input[0].size() == 0 || input[1].size() == 0) {
    std::cerr << "No input read from file!\n";
    return 1;
  }

  distance = calculateDistance(input[0], input[1]);
  similarity = calculateSimilarity(input[0], input[1]);

  std::cout << "Minimal distance: " << distance << "\n";
  std::cout << "Similarity: " << similarity << "\n";

  return 0;
}