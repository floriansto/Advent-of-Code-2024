#include "day3.h"

int main(int argc, char** argv) {
  if (argc == 1) {
    std::cerr << "Provide the path to the input file!\n";
    return 1;
  }

  const std::filesystem::path filename{argv[1]};

  if (!std::filesystem::exists(filename)) {
    std::cerr << "File " << filename << "does not exist!\n";
    return 1;
  }

  std::cout << "Sum of all multiplications: " << sumOfMultiplications(filename)
            << "\n";

  return 0;
}