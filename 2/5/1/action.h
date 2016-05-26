#pragma once

#include "treenode.h"

/**
 * @brief class extended from TreeNode
 * Field value store action
 * Fields left, right point on another TreeNodes
 */
class Action: public TreeNode
{
public:
    /**
     * @brief Action's constructor, that set value and two class's children
     * @param expression
     * @param current position in expression, expression[i] = '('
     */
    Action(const std::string &expression, int &i);
    void print(std::ofstream &out) const;
    int calculate() const;
    ~Action();

private:
    /**
     * @brief choose class for right/left child and create it
     * @param expression
     * @param current position in expression
     * @return Action* | Number*
     */
    TreeNode *getChild(const std::string &expression, int &i);
};
