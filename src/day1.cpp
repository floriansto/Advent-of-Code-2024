/**
 * Advent of Code 2024 - Day 1
 * Reading and comparing lists
 */

#include "day1.h"

/**
 * Bubblesort algorithm to sort a vector.
 * Just done for educational purposes.
 * Of cource std::sort can be used.
 * @param vec Vector to sort
 */
void bubbleSort(std::vector<int>& vec) {
  for (int i = vec.size(); i > 1; --i) {
    for (int j = 0; j < i - 1; ++j) {
      if (vec[j] > vec[j + 1]) {
        std::swap(vec[j], vec[j + 1]);
      }
    }
  }
}

/**
 * Increase the size of a given vector. If the size of the vector is larger than
 * what is needed, nothing is done.
 * @param vec Reference to the vector
 * @param neededSize Minimum needed size
 * @param additionalSize Size to add to the existing vector
 */
void resizeVector(std::vector<int>& vec, int neededSize, int additionalSize) {
  if (neededSize >= vec.size()) {
    vec.resize(vec.size() + additionalSize);
  }
}

/**
 * Calculate the absolute distance between two vectors by
 * 1. Subtracting element wise
 * 2. Sum up the absolute values of the subtractions
 * @return The sum of the elementwise absolute differences
 */
int calculateDistance(std::vector<int>& first, std::vector<int>& second) {
  int distance{0};

  for (std::tuple<int&, int&> elem : std::views::zip(first, second)) {
    distance += std::abs(std::get<0>(elem) - std::get<1>(elem));
  }

  return distance;
}

/**
 * Calculate the similarity between two sorted vectors by
 * 1. Count how often each element of the first vector occurs in the second
 * vector
 * 2. Multiply the element with the amount of occurences
 * 3. Sum up the results for each element of the first vector
 * @param first First vector
 * @param second Second vector
 * @return Return the calculated similarity score
 */
int calculateSimilarity(std::vector<int>& first, std::vector<int>& second) {
  int similarity{0};
  int start{0};
  int amount{0};
  int previous{0};
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

/**
 * Read two integer columns from a file.
 * The two colums must be separated by three spaces
 * @param filename Path of the file to read
 * @return Array of two int vectors, each vector contains the content of one
 * column of the file
 */
std::array<std::vector<int>, 2> readInput(const char* filename) {
  int elements{0};
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

    resizeVector(result[0], elements, 100);
    resizeVector(result[1], elements, 100);

    result[0][elements] = std::stoi(first);
    result[1][elements] = std::stoi(second);
    ++elements;
  }
  input.close();
  return result;
}

/**
 * Read a file with two columns of integers separated by three spaces.
 * Then sort the two colums, subtract them from each other and caluclate the sum
 * of the result.
 * @return 0 in case of success, 1 if no input file was found or the input file
 * was faulty
 */
int day1(int argc, char** argv) {
  std::array<std::vector<int>, 2> input;
  int distance;
  int similarity;

  if (argc == 1) {
    std::cerr << "Provide the path to the input file!\n";
    return 1;
  }

  input = readInput(argv[1]);

  if (input[0].size() == 0 || input[1].size() == 0) {
    std::cerr << "No input read from file!\n";
    return 1;
  }

  if (input[0].size() != input[1].size()) {
    std::cerr << "Inconsistent column length in the input file!\n";
    return 1;
  }

  bubbleSort(input[0]);
  bubbleSort(input[1]);

  distance = calculateDistance(input[0], input[1]);
  similarity = calculateSimilarity(input[0], input[1]);

  std::cout << "Minimal distance: " << distance << "\n";
  std::cout << "Similarity: " << similarity << "\n";

  return 0;
}
