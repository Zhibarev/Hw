#pragma once
#include <iostream>

/**
 * @brief template Set based on AVL tree
 * AVL tree - https://docs.google.com/document/d/1hNYn9yU-RRZSp8HSfJn0D_Kjw7eKgOhrSePhqgM_NPo/edit
 * Has overloaded operators +(union) and *(intersection)
 */
template <typename T>
class Set
{
public:
    Set(){}
    ~Set();

    void add(const T &value);
    void remove(const T &value);
    bool search(const T &value) const;
    /**
     * @brief delete all nodes
     */
    void clear();
    /**
     * @brief print tree in form - value (Tree Tree), use recursive function printTree
     */
    void print() const;
    /**
     * @brief union of sets, use recursive function addToSet
     * @param set
     * @return union
     */
    Set<T>& operator+(const Set<T> &set) const;
    /**
     * @brief interseption of sets, use recursive function addIntersectionToSet
     * @param set
     * @return interseption
     */
    Set<T>& operator*(const Set<T> &set) const;

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

    /**
     * @brief recursive function, node print himself and his childs, before node isn't nullptr
     * @param node
     */
    void printTree(TreeNode *node) const;
    /**
     * @brief recursive function to add all values from node to the end of tree to set
     * Add node in set and his child, before node isn't nullptr
     * @param node
     * @param set
     */
    void addToSet(TreeNode *node, Set<T> *set) const;
    /**
     * @brief recursive function to add all values, which include to toIntersection,
     * from node to the end of tree to set
     * Add node in set and his child, before node isn't nullptr
     * @param node
     * @param toIntersection
     * @param set
     */
    void addIntersectionToSet(TreeNode *node, const Set<T> &toIntersection, Set<T> *set) const;
    bool search(const T &value, TreeNode *node) const;
    TreeNode *remove(const T &value, TreeNode *node);
    TreeNode *add(const T &value, TreeNode *node);
};

template<typename T>
void Set<T>::add(const T &value)
{
    root = add(value, root);
}

template<typename T>
void Set<T>::remove(const T &value)
{
    if (root != nullptr)
        root = remove(value, root);
}

template<typename T>
bool Set<T>::search(const T &value) const
{
    return search(value, root);
}

template<typename T>
void Set<T>::clear()
{
    if (root != nullptr)
        delete root;
}

template <typename T>
Set<T>::~Set()
{
    clear();
}

template<typename T>
Set<T>::TreeNode::TreeNode(const T &newValue)
{
    value = newValue;
}

template<typename T>
int Set<T>::TreeNode::getHeight(TreeNode *node) const
{
    return !node ? 0 : node->height;
}

template<typename T>
void Set<T>::TreeNode::updateHeight()
{
    height = getHeight(left) > getHeight(right) ?  getHeight(left) + 1 : getHeight(right) + 1;
}

template<typename T>
int Set<T>::TreeNode::balanceFactor() const
{
    return getHeight(right) - getHeight(left);
}

template<typename T>
bool Set<T>::search(const T &value, TreeNode *node) const
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
typename Set<T>::TreeNode* Set<T>::add(const T &value, TreeNode *node)
{
    if (!node)
        return (new TreeNode(value));
    if (value == node->value)
        return node;
    if (value > node->value)
        node->right = add(value, node->right);
    else
        node->left = add(value, node->left);
    return node->rebalance();
}

template<typename T>
typename Set<T>::TreeNode* Set<T>::TreeNode::rotateRight()
{
    TreeNode* node = left;
    left = node->right;
    node->right = this;
    updateHeight();
    node->updateHeight();
    return node;
}

template<typename T>
typename Set<T>::TreeNode* Set<T>::TreeNode::rotateLeft()
{
    TreeNode* node = right;
    right = node->left;
    node->left = this;
    updateHeight();
    node->updateHeight();
    return node;
}

template<typename T>
typename Set<T>::TreeNode* Set<T>::TreeNode::rebalance()
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
Set<T>::TreeNode::~TreeNode()
{
    if (right)
        delete right;
    if (left)
        delete left;
}

template<typename T>
typename Set<T>::TreeNode* Set<T>::remove(const T &value, TreeNode *node)
{
    if (!node)
        return nullptr;
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
Set<T>& Set<T>::operator+(const Set<T> &set) const
{
    Set<T> *unitedSet = new Set<T>();
    this->addToSet(root, unitedSet);
    set.addToSet(set.root, unitedSet);
    return *unitedSet;
}

template<typename T>
void Set<T>::addToSet(TreeNode *node, Set<T> *set) const
{
    if (node)
    {
        set->add(node->value);
        addToSet(node->left, set);
        addToSet(node->right, set);
    }
}

template<typename T>
void Set<T>::addIntersectionToSet(TreeNode *node, const Set<T> &toIntersection, Set<T> *set) const
{
    if (node)
    {
        if (toIntersection.search(node->value))
            set->add(node->value);
        addIntersectionToSet(node->left, toIntersection, set);
        addIntersectionToSet(node->right, toIntersection, set);
    }
}

template<typename T>
Set<T>& Set<T>::operator*(const Set<T> &set) const
{
    Set<T> *intersection = new Set<T>();
    addIntersectionToSet(root, set, intersection);
    return *intersection;
}

template<typename T>
void Set<T>::print() const
{
    printTree(root);
}

template<typename T>
void Set<T>::printTree(TreeNode *node) const
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


























