#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <tuple>

/**
 * Represent 2d coordinates
 *
 * @warning y is the first entry, x the second! Reason is to be in sync with
 * accessing a 2d matrix via indices where the x-direction is a row from left to
 * right and the y-direction is a column from top to bottom.
 */
typedef struct coordinates {
  int16_t y;
  int16_t x;
} COORDS;

/**
 * 2d matrix containing a char matrix and the information about the number of
 * rows and columns
 */
typedef struct matrix {
  uint16_t nrows;
  uint16_t ncols;
  char **data;
} MATRIX;

const uint8_t wordLength{4};

/**
 * Read an input file for the first part of the advent of code 2024 day 4.
 * Stores the file content in a 2d matrix
 *
 * @param path Path of the file to read
 *
 * @return Returns a matrix of chars
 *
 * @warning Don't forget to free the allocated memory of the matrix when it is
 * no more needed
 */
MATRIX readInputDay4(const std::filesystem::path &path);

/**
 * Frees the allocated memory of a 2d matrix
 *
 * @param matrix Pointer to the matrix
 * @param nrows Number of rows in the matrix
 */
void freeMatrix(char **matrix, uint16_t nrows);

/**
 * Count the occurrences of a word in a matrix of letters.
 * The word can occur in any direction (horizontal, vertical, diagonal) and
 * forwards and backwards.
 *
 * @param matrix 2d matrix of letters
 * @param word Word to search for
 * @param wordLength Length of the word
 *
 * @return Number of occurrences of the word
 */
uint16_t countWord(const MATRIX &matrix, const char *word,
                   const uint16_t wordLength);
