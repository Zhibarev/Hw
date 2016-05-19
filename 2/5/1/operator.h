#pragma once

#include "treenode.h"

/**
 * @brief class extended from TreeNode
 * Field value store action
 * Fields left, right point on another TreeNodes : Operator | Operand
 */
class Operator: public TreeNode
{
public:
    /**
     * @brief Operator's constructor, that set value and two class's children
     * @param expression
     * @param current position in expression, expression[i] = '('
     */
    Operator(const std::string &expression, int &i);
    void print(std::ofstream &out) const;
    int calculate() const;
    ~Operator();

private:
    /**
     * @brief choose class for right/left child and create it
     * @param expression
     * @param current position in expression
     * @return Operator* | Operand*
     */
    TreeNode *getChild(const std::string &expression, int &i);
};
