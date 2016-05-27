#pragma once

#include "treenode.h"
#include <string>

/**
 * @brief class extended from TreeNode
 * Field value store number
 * Fields left, right point on nullptr
 */
class Number: public TreeNode
{
public:
    /**
     * @brief Number's constructor, set value, and change current position in expression
     * @param expression
     * @param current position in expression, expression[i] - number
     */
    Number(const std::string &expression, int &i);
    void print(std::ofstream &out) const;
    int calculate() const;
};
