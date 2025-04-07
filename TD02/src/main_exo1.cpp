#include "td02_exo1.hpp"

int main()
{
    //exo 1 q1
    //std::string expr {getExpression()};
    //std::cout << expr;

    // exo 1 q2
    //std::vector<std::string> cut {split_string(expr)};

    
    std::string expr_1 {"3 4 +"};
    std::string expr_2 {"2 12 + 5 +"};
    std::string expr_3 {"3 4 11 5 + / +"};
    std::string expr_4 {"4 5 2 * +"};
    std::string expr_5 {"3 4 2 ^ 1 5 - 6 ^ / +"};

    std::vector<std::string> cut_1 {split_string(expr_1)};
    std::vector<std::string> cut_2 {split_string(expr_2)};
    std::vector<std::string> cut_3 {split_string(expr_3)};
    std::vector<std::string> cut_4 {split_string(expr_4)};
    std::vector<std::string> cut_5 {split_string(expr_5)};
    
    //TEST exo 1 q5 
    
    std::cout << "L'expression " << expr_1 << " donne " << npi_evaluate(cut_1) << std::endl;
    std::cout << "L'expression " << expr_2 << " donne " << npi_evaluate(cut_2) << std::endl;
    std::cout << "L'expression " << expr_3 << " donne " << npi_evaluate(cut_3) << std::endl;
    std::cout << "L'expression " << expr_4 << " donne " << npi_evaluate(cut_4) << std::endl;
    std::cout << "L'expression " << expr_5 << " donne " << npi_evaluate(cut_5) << std::endl;
    
    return 0;
}