#pragma once

#include "treeexeptions.h"
#include <QVector>
#include <iostream>

/**
 * @brief template AVL tree
 * AVL tree - https://docs.google.com/document/d/1hNYn9yU-RRZSp8HSfJn0D_Kjw7eKgOhrSePhqgM_NPo/edit
 */
template <typename T>
class AVLTree
{
public:
    ~AVLTree();

    /**
     * @brief add value to tree
     * throw object of AlreadyInclude if value if already include
     * @param value
     */
    void add(const T &value);
    /**
     * @brief remove value from tree
     * throw object of NothingToRemove if tree doesn't contain value
     * @param value
     */
    void remove(const T &value);
    bool search(const T &value) const;
    int length() const;
    /**
     * @brief delete all nodes
     */
    void clear();
    /**
     * @brief print tree in form - value (Tree Tree), use recursive function printTree
     */
    void print() const;
    QVector<T> toVector() const;

private:
    class TreeNode
    {
    public:
        TreeNode(const T &newValue);
        ~TreeNode();

        int height = 1;
        T value;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        void updateHeight();
        /**
         * @brief wrapper of field height, which return 0 if node is nullptr
         * @param node
         * @return height of node
         */
        int getHeight(TreeNode *node) const;
        int balanceFactor() const;
        /**
         * @brief change part of tree if |balanceFactor| = 2 and return new top vertex
         * Use left and right rotation, look link in class's description
         * @return new top of part of tree
         */
        TreeNode* rebalance();
        TreeNode* rotateLeft();
        TreeNode* rotateRight();
    };

    TreeNode *root = nullptr;
    int size = 0;

    /**
     * @brief recursive function, node print himself and his childs, before node isn't nullptr
     * @param node
     */
    void printTree(TreeNode *node) const;
    bool search(const T &value, TreeNode *node) const;
    TreeNode *remove(const T &value, TreeNode *node);
    TreeNode *add(const T &value, TreeNode *node);
    void toVector(QVector<T> &vector, TreeNode *node, int &position) const;
};

template<typename T>
void AVLTree<T>::add(const T &value)
{
    size++;
    root = add(value, root);
}

template<typename T>
void AVLTree<T>::remove(const T &value)
{
    size--;
    root = remove(value, root);
}

template<typename T>
bool AVLTree<T>::search(const T &value) const
{
    return search(value, root);
}

template<typename T>
void AVLTree<T>::clear()
{
    if (root != nullptr)
        delete root;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    clear();
}

template<typename T>
AVLTree<T>::TreeNode::TreeNode(const T &newValue)
{
    value = newValue;
}

template<typename T>
int AVLTree<T>::TreeNode::getHeight(TreeNode *node) const
{
    return !node ? 0 : node->height;
}

template<typename T>
void AVLTree<T>::TreeNode::updateHeight()
{
    height = getHeight(left) > getHeight(right) ?  getHeight(left) + 1 : getHeight(right) + 1;
}

template<typename T>
int AVLTree<T>::TreeNode::balanceFactor() const
{
    return getHeight(right) - getHeight(left);
}

template<typename T>
bool AVLTree<T>::search(const T &value, TreeNode *node) const
{
    if (!node)
        return false;
    if (node->value == value)
        return true;
    if (node->value < value)
        return search(value, node->right);
    return search(value, node->left);
}

template<typename T>
typename AVLTree<T>::TreeNode* AVLTree<T>::add(const T &value, TreeNode *node)
{
    if (!node)
        return (new TreeNode(value));
    if (value == node->value)
    {
        size--;
        throw AlreadyInclude();
    }
    if (value > node->value)
        node->right = add(value, node->right);
    else
        node->left = add(value, node->left);
    return node->rebalance();
}

template<typename T>
typename AVLTree<T>::TreeNode* AVLTree<T>::TreeNode::rotateRight()
{
    TreeNode* node = left;
    left = node->right;
    node->right = this;
    updateHeight();
    node->updateHeight();
    return node;
}

template<typename T>
typename AVLTree<T>::TreeNode* AVLTree<T>::TreeNode::rotateLeft()
{
    TreeNode* node = right;
    right = node->left;
    node->left = this;
    updateHeight();
    node->updateHeight();
    return node;
}

template<typename T>
typename AVLTree<T>::TreeNode* AVLTree<T>::TreeNode::rebalance()
{
    updateHeight();
    if (balanceFactor() == 2)
    {
        if (right->balanceFactor() < 0)
            right = right->rotateRight();
        return rotateLeft();
    }
    if (balanceFactor() == -2)
    {
        if (left->balanceFactor() > 0)
            left = left->rotateLeft();
        return rotateRight();
    }
    return this;
}

template<typename T>
AVLTree<T>::TreeNode::~TreeNode()
{
    if (right)
        delete right;
    if (left)
        delete left;
}

template<typename T>
typename AVLTree<T>::TreeNode* AVLTree<T>::remove(const T &value, TreeNode *node)
{
    if (!node)
    {
        size++;
        throw NothingToRemove();
    }
    if (value > node->value)
        node->right = remove(value, node->right);
    if (value < node ->value)
        node->left = remove(value, node->left);
    if (value == node->value)
    {
        if (!node->right)
        {
            TreeNode *left = node->left;
            node->left = nullptr;
            delete node;
            return left;
        }
        if (!node->left)
        {
            TreeNode *right = node->right;
            node->right = nullptr;
            delete node;
            return right;
        }
        TreeNode *minNode = node->right;
        while (minNode->left)
            minNode = minNode->left;
        node->value = minNode->value;
        minNode->value = value;
        node->right = remove(value, node->right);
    }
    return node->rebalance();
}

template<typename T>
void AVLTree<T>::print() const
{
    printTree(root);
}

template<typename T>
void AVLTree<T>::printTree(TreeNode *node) const
{
    if (node == nullptr)
        std::cout << "nullptr";
    else
    {
        std::cout << node->value << "( ";
        printTree(node->left);
        std::cout << " ";
        printTree(node->right);
        std::cout << " )";
     }
}

template<typename T>
QVector<T> AVLTree<T>::toVector() const
{
    QVector<T> vector(size);
    int position = 0;
    toVector(vector, root, position);
    return vector;
}

template<typename T>
void AVLTree<T>::toVector(QVector<T> &vector, TreeNode *node, int &position) const
{
    if (node)
    {
        vector[position] = node->value;
        position++;
        toVector(vector, node->right, position);
        toVector(vector, node->left, position);
    }
}

template<typename T>
int AVLTree<T>::length() const
{
    return size;
}


























