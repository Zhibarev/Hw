#include "operator.h"
#include "operand.h"

Operator::Operator(const std::string &expression, int &i)
{
    value = expression[i + 1];
    i += 3;
    left = getChild(expression, i);
    right = getChild(expression, i);
    i++;
}

TreeNode* Operator::getChild(const std::string &expression, int &i)
{
    if(expression[i] <= '9' && expression[i] >= '0')
        return (new Operand(expression, i));
    else
        return (new Operator(expression, i));
}

int Operator::calculate() const
{
    switch (value)
    {
        case '+':
            return left->calculate() + right->calculate();
        case '-':
            return left->calculate() - right->calculate();
        case '*':
            return left->calculate() * right->calculate();
        case '/':
            return left->calculate() / right->calculate();
    }
}

void Operator::print(std::ofstream &out) const
{
    out << "(" << (char) value << " ";
    left->print(out);
    out << " ";
    right->print(out);
    out << ")";
}

Operator::~Operator()
{
    delete left;
    delete right;
}
