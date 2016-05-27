#include "action.h"
#include "number.h"

Action::Action(const std::string &expression, int &i)
{
    value = expression[i + 1];
    i += 3;
    left = getChild(expression, i);
    right = getChild(expression, i);
    i++;
}

TreeNode* Action::getChild(const std::string &expression, int &i)
{
    if(expression[i] <= '9' && expression[i] >= '0')
        return (new Number(expression, i));
    else
        return (new Action(expression, i));
}

int Action::calculate() const
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

void Action::print(std::ofstream &out) const
{
    out << "(" << (char) value << " ";
    left->print(out);
    out << " ";
    right->print(out);
    out << ")";
}

Action::~Action()
{
    delete left;
    delete right;
}
