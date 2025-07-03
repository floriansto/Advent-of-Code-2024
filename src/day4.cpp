#include "day4.h"

void freeMatrix(char **matrix, uint16_t nrows) {
  for (uint16_t i = 0; i < nrows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

/**
 * Interpolate a line in 2d space
 *
 * @param start Start of the line
 * @param direction Direction of the line
 * @param increment Interpolation value
 *
 * @return Interpolated point
 */
COORDS calcCoord(const COORDS &start, const COORDS &direction,
                 uint16_t increment) {
  COORDS coord;
  coord.x = start.x + direction.x * increment;
  coord.y = start.y + direction.y * increment;
  return coord;
}

/**
 * Search for a word in a 2d matrix of letters in a given direction from a given
 * starting point
 *
 * @param start Start coordinates for the search
 * @param direction Direction to search (y, x)
 * @param matrix 2d matrix of letters to search the word in
 * @param word Word to search for
 * @param wordLength Length of the word to search for
 *
 * @return 0 if the word is not found or the direction violates the matrix
 * boundaries, 1 if the word was found
 */
uint16_t searchWord(const COORDS &start, const COORDS &direction,
                    const MATRIX &matrix, const char *word,
                    const uint16_t wordLength) {
  COORDS coord;
  // Check if matrix boundaries are violated for the current search direction
  coord = calcCoord(start, direction, wordLength - 1);
  if (coord.x < 0 || coord.x > matrix.ncols - 1 || coord.y < 0 ||
      coord.y > matrix.nrows - 1) {
    return 0;
  }

  // Search for the word
  for (uint16_t i = 0; i < wordLength; i++) {
    coord = calcCoord(start, direction, i);
    if (matrix.data[coord.y][coord.x] != word[i]) {
      return 0;
    }
  }
  return 1;
}

uint16_t countWord(const MATRIX &matrix, const char *word,
                   const uint16_t wordLength) {
  uint16_t occurrences{0};

  // Iterate over every element in the matrix
  // Search in every possible direction
  for (int16_t i = 0; i < matrix.nrows; i++) {
    for (int16_t j = 0; j < matrix.ncols; j++) {
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{1, 0}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{-1, 0}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{0, 1}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{0, -1}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{1, 1}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{-1, 1}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{1, -1}, matrix, word, wordLength);
      occurrences +=
          searchWord(COORDS{i, j}, COORDS{-1, -1}, matrix, word, wordLength);
    }
  }
  return occurrences;
}

MATRIX readInputDay4(const std::filesystem::path &path) {
  char **matrix;
  uint16_t j{0};
  uint16_t row{0};
  uint16_t ncols{0};
  uint16_t nrows{0};
  std::tuple<uint16_t, uint16_t> matrixDimensions{0, 0};
  std::string line;
  std::ifstream input{path};

  if (!input.is_open()) {
    std::cout << "Unable to open file!\n";
    return MATRIX{0, 0, nullptr};
  }

  nrows = std::count(std::istreambuf_iterator<char>(input),
                     std::istreambuf_iterator<char>(), '\n') +
          1;

  matrix = (char **)malloc(sizeof(char *) * nrows);
  if (!matrix) {
    std::cout << +"Allocating memory for the matrix failed!\n";
    return MATRIX{0, 0, nullptr};
  }

  input.seekg(0);
  while (std::getline(input, line)) {
    // Check for uniform length of each column
    if (ncols != 0 && line.length() != ncols) {
      std::cout << "Line length at row " << nrows << " is not uniform!\n";
      input.close();
      return MATRIX{0, 0, nullptr};
    } else if (ncols == 0) {
      ncols = line.length();
    }

    // Add memory for the new row
    matrix[row] = (char *)malloc(sizeof(char) * ncols);
    if (!matrix[row]) {
      std::cout << +"Allocating memory for row " << row << " failed!\n";
      freeMatrix(matrix, row);
      input.close();
      return MATRIX{0, 0, nullptr};
    }

    j = 0;
    // Copy the contents of the read line to the current matrix row
    for (char i : line) {
      matrix[row][j++] = i;
    }
    row++;
  }

  input.close();
  return MATRIX{nrows, ncols, matrix};
}