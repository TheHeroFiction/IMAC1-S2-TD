#include <vector>
#include <string>
#include "td02_exo1.hpp"

#pragma once

//enum class Operator { ADD, SUB, MUL, DIV}; exo2
enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN}; // exo3
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const& words);
float npi_evaluate(std::vector<Token> const& tokens);