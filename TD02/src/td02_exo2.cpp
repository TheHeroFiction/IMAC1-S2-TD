#include "td02_exo2.hpp"

Token make_token(float value)
{
    Token new_token {.type = TokenType::OPERAND, .value = value};
    return new_token;
}

Token make_token(Operator op)
{
    Token new_token {.type = TokenType::OPERATOR, .op = op};
    return new_token;
}

Operator detect_type(std::string const& s)
{
    if (s == "-")
    {
        return Operator::SUB;
    }
    else if (s == "*")
    {
        return Operator::MUL;
    }
    else if (s == "/")
    {
        return Operator::DIV;
    }
    else{
        return Operator::ADD;
    }
}

std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> result {};
    for (int i {0}; i < words.size(); i++)
    {
        if (is_floating(words[i]) || is_integer(words[i]))
        {
            result.push_back(make_token(std::stof(words[i])));
        }
        else
        {
            result.push_back(make_token(detect_type(words[i])));
        }
        
    }
    return result;
}

float npi_evaluate(std::vector<Token> const& tokens)
{
    std::stack<float> pile {};
    float left_nmb {};
    float right_nmb {};
    for (int i {0}; i < tokens.size(); i++)
    {
        if (tokens[i].type == TokenType::OPERAND)
        {
            pile.push(tokens[i].value);
        }
        else 
        {
            right_nmb = pile.top();
            pile.pop();
            left_nmb = pile.top();
            pile.pop();
            if(tokens[i].op == Operator::SUB)
            {
                pile.push(left_nmb - right_nmb);
            }
            else if(tokens[i].op == Operator::MUL)
            {
                pile.push(left_nmb * right_nmb);
            }
            else if(tokens[i].op == Operator::DIV)
            {
                pile.push(left_nmb/right_nmb);
            }
            else
            {
                pile.push(left_nmb + right_nmb);
            }
        }
    }
    return pile.top();
}
