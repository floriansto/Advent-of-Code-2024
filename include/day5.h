#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

namespace day5 {
/**
 * Read in a textfile containing a set of rules for number ordering followed by
 * an empty line and then lists of numbers. From every list that is correctly
 * ordered, the middle number is taken und summed up.
 *
 * Example of the textfile:
 * ```
 * 13|56
 * 32|13
 * 56|33
 *
 * 56,13
 * 32,13,56
 * 13,33,56
 * ```
 * The pair 13|56 indicates, that the number 13 must always come first,
 * before 56. All rules apply, however not all numbers must be used in the list.
 * The list 56,13 violates the first rule and is not correct.
 * The list 13,33,56 violates the last rule and is also not correct.
 * The list 32,13,56,33 is correct, so the sum would be simple 13
 *
 * @param path Path to the textfile to read
 *
 * @return Sum of the middle number of all correctly sored lists
 */
uint16_t calcMiddlePagenumberSum(const std::filesystem::path &path);

/**
 * Check if the numbers of a reference are in an allowed order.
 * The order is specified in the hashmap where the numbers associated with a key
 * always have to be behind the key itself in the list
 *
 * @param map Hasmap of the allowed orders containing a key as number and a
 * vector of numbers as value. The numbers in the vector must be behind the key
 * in the given reference
 * @param reference List of numbers to be checked for correct order
 *
 * @return true, if the reference was ordered correctly, false else
 */
bool checkCorrectOrder(
    const std::unordered_map<uint16_t, std::vector<uint16_t>> &map,
    const std::vector<uint16_t> &reference);
};  // namespace day5