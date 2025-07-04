#include "day5.h"

int main(int argc, char** argv) {
  if (argc == 1) {
    std::cout << "Please provide a path to the input file!\n";
    return 1;
  }

  uint16_t number = day5::calcMiddlePagenumberSum(argv[1]);

  std::cout << "The sum of the middle pages of all correctly sorted updates is "
            << number << "\n";
  return 0;
}