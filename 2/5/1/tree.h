#pragma once
#include "treenode.h"
#include <fstream>
#include <string>

/**
 * @brief Realizing of arithmetic binary tree
 * Work with expressions in polish notation
 */
class Tree
{
public:
    /**
     * @brief Tree's constructor, set head, which set all tree
     * @param expression in polish notation
     */
    Tree(const std::string &expression);
    /**
     * @brief print tree in file in form (action (tree tree)) | number
     * @param stream connected with file for printing
     */
    void print(std::ofstream &out) const;
    int calculate() const;
    ~Tree();

private:
    TreeNode *head = nullptr;
};
