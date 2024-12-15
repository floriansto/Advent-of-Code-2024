#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

/**
 * Read a file of random text and execute multiplications whenever
 * mul(NUMBER1,NUMBER2) occurs. Sum up the result of all multiplicaitons and
 * return the sum.
 *
 * @param filename Path of the file to read
 *
 * @return Sum of all multiplications
 */
int sumOfMultiplications(const std::filesystem::path& filename);

/**
 * Possible tokens for the scanner
 */
enum class TokenType {
  LEFT_PAREN,
  RIGHT_PAREN,
  COMMA,
  NUMBER,
  MUL,
  INVALID
};

/**
 * Class for each token
 * Each token consists of a type and its corresponding string (lexeme)
 */
class Token {
 public:
  Token(TokenType type, std::string lexeme);
  std::ostream& operator<<(std::ostream& os);
  TokenType getType() const;
  std::string getLexeme() const;

 private:
  TokenType type;
  std::string lexeme;
};
