#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <stack>

bool is_floating(std::string const& s); // exo1 q3
float npi_evaluate(std::vector<std::string> const& tokens); // exo1 q4

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

float npi_evaluate(std::vector<std::string> const& tokens)
{
    std::stack<float> pile {};
    int count {0};
    while (count < tokens.size() -1)
    {
        if (is_floating(tokens[count]))
        {
            pile.push(std::stof(tokens[count]));
        }
        else 
        {
            
        }
    }
}

int main() 
{
    std::string expr {getExpression()};
    std::cout << expr;

    // exo 1 q2
    std::vector<std::string> cut {split_string(expr)};

    std::cout << std::boolalpha <<std::endl;    
    std::cout << is_floating(cut[0]) <<std::endl;
    std::cout << is_floating(cut[1]) <<std::endl;
    return 0;
}