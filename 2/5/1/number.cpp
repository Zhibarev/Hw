#include "number.h"

Number::Number(const std::string &expression, int &i)
{
    while (expression[i] <= '9' && expression[i] >= '0')
    {
        value = value * 10 + expression[i] - '0';
        i++;
    }
    i++;
}

int Number::calculate() const
{
    return value;
}

void Number::print(std::ofstream &out) const
{
    out << value;
}
