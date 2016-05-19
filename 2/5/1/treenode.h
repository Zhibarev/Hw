#pragma once

#include <string>
#include <fstream>

/**
 * @brief Abstract class, which describe arithmetic binary tree's node
 */
class TreeNode
{
public:
    /**
     * @brief print tree in file in form (action (tree tree)) | number
     * @param stream connected with file for printing
     */
    virtual void print(std::ofstream &out) const = 0;
    virtual int calculate() const = 0;
    virtual ~TreeNode(){}

protected:
    int value = 0;
    TreeNode *right = nullptr;
    TreeNode *left = nullptr;
};
