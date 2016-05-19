#include "operand.h"

Operand::Operand(const std::string &expression, int &i)
{
    while (expression[i] <= '9' && expression[i] >= '0')
    {
        value = value * 10 + expression[i] - '0';
        i++;
    }
    i++;
}

int Operand::calculate() const
{
    return value;
}

void Operand::print(std::ofstream &out) const
{
    out << value;
}
