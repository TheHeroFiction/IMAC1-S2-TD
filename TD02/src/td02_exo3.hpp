#include <vector>
#include "td02_exo2.hpp"

#pragma once

int operator_precedence(Operator const op);
std::vector<Token> infix_to_npi_tokens(std::string const& expression);