#include "day3.h"

Token::Token(TokenType type, std::string lexeme) : type{type}, lexeme{lexeme} {
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
  os << token.getLexeme();
  return os;
}

TokenType Token::getType() const {
  return this->type;
}

std::string Token::getLexeme() const {
  return this->lexeme;
}

bool isMul(std::ifstream& fstream) {
  if (fstream.peek() != 'm') {
    return false;
  }
  fstream.get();
  if (fstream.peek() != 'u') {
    return false;
  }
  fstream.get();
  if (fstream.peek() != 'l') {
    return false;
  }
  fstream.get();
  return true;
}

Token getDoDont(std::ifstream& fstream) {
  char c;
  char dont[3]{'n', '\'', 't'};
  for (int i = 0; i < 3; ++i) {
    fstream.get(c);
    if (c != dont[i]) {
      return Token(TokenType::DO, "do");
    }
  }
  return Token(TokenType::DONT, "don't");
}

bool isDo(std::ifstream& fstream) {
  if (fstream.peek() != 'd') {
    return false;
  }
  fstream.get();
  if (fstream.peek() != 'o') {
    return false;
  }
  fstream.get();
  return true;
}

bool isDigit(const char c) {
  return c >= '0' && c <= '9';
}

Token getNumber(std::ifstream& fstream) {
  std::string number{"0"};
  char c;

  while (isDigit(fstream.peek())) {
    fstream.get(c);
    number += c;
  }

  if (fstream.peek() == '.') {
    fstream.get(c);
    number += c;
  } else {
    return Token(TokenType::NUMBER, number);
  }
  while (isDigit(fstream.peek())) {
    fstream.get(c);
    number += c;
  }
  return Token(TokenType::NUMBER, number);
}

std::vector<Token> scanInput(std::ifstream& fstream) {
  std::istreambuf_iterator<char> eos;
  std::vector<Token> tokenList;
  char c;
  while (fstream.get(c)) {
    switch (c) {
      case '(':
        tokenList.push_back(Token(TokenType::LEFT_PAREN, "("));
        break;
      case ')':
        tokenList.push_back(Token(TokenType::RIGHT_PAREN, ")"));
        break;
      case ',':
        tokenList.push_back(Token(TokenType::COMMA, ","));
        break;
      default:
        fstream.unget();
        if (isDigit(fstream.peek())) {
          tokenList.push_back(getNumber(fstream));
        } else if (isMul(fstream)) {
          tokenList.push_back(Token(TokenType::MUL, "mul"));
        } else if (isDo(fstream)) {
          tokenList.push_back(getDoDont(fstream));
        } else {
          fstream.get();
          tokenList.push_back(Token(TokenType::INVALID, ""));
        }
        break;
    }
  }
  return tokenList;
}

int calculateResult(const std::vector<Token>& tokenList, bool conditionals) {
  bool doActive{true};
  TokenType nextToken = TokenType::MUL;
  int index{0};
  double result{0.0};
  double numbers[2]{0.0, 0.0};
  for (auto it = begin(tokenList); it != end(tokenList); ++it) {
    if (!doActive && conditionals) {
      if (it->getType() == TokenType::DO) {
        doActive = true;
        nextToken = TokenType::MUL;
      }
      continue;
    }
    if (it->getType() == TokenType::DONT) {
      doActive = false;
      nextToken = TokenType::MUL;
      continue;
    }
    if (it->getType() != nextToken) {
      nextToken = TokenType::MUL;
      continue;
    }
    switch (it->getType()) {
      case TokenType::RIGHT_PAREN:
        result += numbers[0] * numbers[1];
        nextToken = TokenType::MUL;
        continue;
      case TokenType::NUMBER:
        numbers[index] = std::atof(it->getLexeme().c_str());
        if (index == 0) {
          nextToken = TokenType::COMMA;
        } else {
          nextToken = TokenType::RIGHT_PAREN;
        }
        continue;
      case TokenType::COMMA:
        nextToken = TokenType::NUMBER;
        index = 1;
        continue;
      case TokenType::LEFT_PAREN:
        nextToken = TokenType::NUMBER;
        index = 0;
        continue;
      case TokenType::MUL:
        nextToken = TokenType::LEFT_PAREN;
        continue;
      default:
        nextToken = TokenType::MUL;
    }
  }
  return result;
}

int sumOfMultiplications(const std::filesystem::path& filename,
                         bool conditionals) {
  std::ifstream input{filename};
  std::string line;
  std::vector<Token> tokenList;

  if (!input.is_open()) {
    std::cerr << "Unable to open file\n";
    return -1;
  }

  tokenList = scanInput(input);
  input.close();
  return calculateResult(tokenList, conditionals);
}