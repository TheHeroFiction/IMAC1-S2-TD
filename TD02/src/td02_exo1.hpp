#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <stack>
#include <cctype>

#pragma once

std::string getExpression();
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s); // exo1 q3
bool is_integer(std::string const& s);
float calculate_power(float const& left_nmb, float const& right_nmb);
float calculate(std::string const& s, float const& left_nmb, float const& right_nmb);
float npi_evaluate(std::vector<std::string> const& tokens); // exo1 q4