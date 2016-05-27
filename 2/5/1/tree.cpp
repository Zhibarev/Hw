#include "tree.h"
#include "number.h"
#include "action.h"

Tree::Tree(const std::string &expression)
{
    int i = 0;
    if (expression[i] >= '0' && expression[i] <= '9')
        head = new Number(expression, i);
    else
        head = new Action(expression, i);
}

void Tree::print(std::ofstream &out) const
{
    head->print(out);
}

int Tree::calculate() const
{
    return head->calculate();
}

Tree::~Tree()
{
    delete head;
}
