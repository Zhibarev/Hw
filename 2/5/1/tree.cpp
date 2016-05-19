#include "tree.h"
#include "TreeNode.h"

Tree::Tree(const std::string &expression)
{
    int i = 0;
    head = new TreeNode(expression, i);
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
