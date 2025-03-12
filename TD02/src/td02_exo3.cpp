#include "td02_exo3.hpp"

int operator_precedence(Operator const op)
{
    if (op == Operator::ADD || op == Operator::SUB)
    {
        return 0;
    }
    else if (op == Operator::MUL || op == Operator::DIV)
    {
        return 1;
    }
    else if (op == Operator::POW)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}