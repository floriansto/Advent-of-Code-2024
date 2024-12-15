#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

enum class Trend {
  invalid,
  increasing,
  decreasing
};

/**
 * Check if the level sequence of a report is valid.
 * A report is valid, if all levels in it are strictly incresing or decreasing.
 * Steps larger than 3 between two levels are also invalid.
 *
 * @param report Report consisting of multiple levels (integer numbers)
 * @param dampening Flag to allow to remove one invalid level from the report
 *
 * @return true if the report is valid, false otherwise
 */
bool checkReport(const std::vector<int>& report, const bool dampening);

/**
 * Count the valid reports. Reads a file from the filesystem, where every
 * line is a report consisting of multiple levels.
 *
 * @param filename Path to the file to read
 * @param dampening Flag to allow to remove one invalid level from each report
 *
 * @return The number of valid reports
 *
 * @warning There is no check for valid inputs. It is assumed that the levels
 *          are always integer numbers separated by at least one space
 */
int countReports(const std::filesystem::path& filename, bool dampening);