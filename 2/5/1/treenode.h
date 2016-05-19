#pragma once

#include <string>
#include <fstream>

/**
 * @brief Class, which describe arithmetic binary tree's node
 */
class TreeNode
{
public:
    /**
     * @brief TreeNode's constructor, create node and his child
     * @param expression
     * @param current index in expression
     */
    TreeNode(const std::string &expression, int &i);
    /**
     * @brief print tree in file in form (action (tree tree)) | number
     * @param stream connected with file for printing
     */
    void print(std::ofstream &out) const;
    int calculate() const;
    ~TreeNode();

private:
    bool isNumber = false;
    int value = 0;
    TreeNode *right = nullptr;
    TreeNode *left = nullptr;
};
