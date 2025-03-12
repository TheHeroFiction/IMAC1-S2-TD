#include "td02_exo1.hpp"

std::string getExpression()
{
    std::string expr {};
    std::cout <<  "Entrez l'expression: ";
    std::getline (std::cin,expr);
    return expr;
}

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    for (int i {0}; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            return true;
        }
    }
    return false;
}

bool is_integer(std::string const& s)
{
    for (int i {0}; i < s.size();i++)
    {
        if (!(std::isdigit(s[i])))
        {
            return false;
        }
    }
    return true;
}

float calculate_power(float const& left_nmb, float const& right_nmb)
{
    float total {left_nmb};
    for (int i {1}; i < right_nmb; i++)
    {
        total *= left_nmb;
    }
    return total;
}


float calculate(std::string const& s, float const& left_nmb, float const& right_nmb)
{
    if (s == "-")
    {
        return left_nmb - right_nmb;
    }
    else if (s == "*")
    {
        return left_nmb * right_nmb;
    }
    else if (s == "/")
    {
        return left_nmb / right_nmb;
    }
    else if (s == "^")
    {
        return calculate_power(left_nmb,right_nmb);
    }
    else 
    {
        return left_nmb + right_nmb; 
    }
}

float npi_evaluate(std::vector<std::string> const& tokens)
{
    std::stack<float> pile {};
    int count {0};
    float right_nmb {0.f};
    float left_nmb {0.f};
    while (count < tokens.size())
    {
        if (is_floating(tokens[count]) || is_integer(tokens[count]) )
        {
            pile.push(std::stof(tokens[count]));
        }
        else
        {
            right_nmb = pile.top();
            pile.pop();
            left_nmb = pile.top();
            pile.pop();
            pile.push(calculate(tokens[count],left_nmb,right_nmb));
        }
        count++;
    }
    return pile.top();
}

