#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>

/**
 * Read two integer columns from a file.
 * The two colums must be separated by three spaces
 * @param filename Path of the file to read
 * @return Array of two int vectors, each vector contains the content of one
 * column of the file
 */
std::array<std::vector<int>, 2> readInput(const std::filesystem::path&);

/**
 * Calculate the absolute distance between two vectors by
 * 1. Subtracting element wise
 * 2. Sum up the absolute values of the subtractions
 * @return The sum of the elementwise absolute differences
 */
int calculateDistance(std::vector<int>& first, std::vector<int>& second);

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
int calculateSimilarity(std::vector<int>& first, std::vector<int>& second);