#include "treenode.h"

TreeNode::TreeNode(const std::string &expression, int &i)
{
    if (expression[i] <= '9' && expression[i] >= '0')
    {
        isNumber = true;
        while (expression[i] <= '9' && expression[i] >= '0')
        {
         value = value * 10 + expression[i] - '0';
          i++;
        }
        i++;
    }
    else
    {
        value = expression[i + 1];
        i += 3;
        left = new TreeNode(expression, i);
        right = new TreeNode(expression, i);
        i++;
    }
}

int TreeNode::calculate() const
{
    if (!isNumber)
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
    else
        return value;
}

void TreeNode::print(std::ofstream &out) const
{
    if (!isNumber)
    {
        out << "(" << (char) value << " ";
        left->print(out);
        out << " ";
        right->print(out);
        out << ")";
    }
    else
        out << value;
}

TreeNode::~TreeNode()
{
    if (!isNumber)
    {
        delete left;
        delete right;
    }
}
