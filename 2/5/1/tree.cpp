#include "tree.h"
#include "operand.h"
#include "operator.h"

Tree::Tree(const std::string &expression)
{
    int i = 0;
    if (expression[i] >= '0' && expression[i] <= '9')
        head = new Operand(expression, i);
    else
        head = new Operator(expression, i);
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
