#pragma once

#include "avltree.h"

template <typename T>
/**
 * @brief template class Set based on AVLTree
 * Has overloaded operators +(union) and *(intersection)
 */
class Set
{
public:
    Set();
    ~Set();
    /**
     * @brief add value to set
     * throw AlreadyInclude if value if alredy include to set
     * @param value
     */
    void add(const T &value);
    /**
     * @brief remove value from set
     * throw NothingToRemove if set doesn't contain value
     * @param value
     */
    void remove(const T &value);
    bool search(const T &value) const;
    int size() const;
    /**
     * @brief union of Sets
     * Use conversetion to vector
     * @param Set
     * @return union
     */
    Set<T> operator+(const Set<T> &set) const;
    /**
     * @brief interseption of Sets
     * Use conversetion to vector
     * @param Set
     * @return interseption
     */
    Set<T> operator*(const Set<T> &set) const;
private:
    AVLTree<T> *tree = nullptr;
};

template<typename T>
Set<T>::Set()
{
    tree = new AVLTree<T>();
}

template<typename T>
Set<T>::~Set()
{
    delete tree;
}

template<typename T>
void Set<T>::add(const T &value)
{
    tree->add(value);
}

template<typename T>
void Set<T>::remove(const T &value)
{
    tree->remove(value);
}

template<typename T>
bool Set<T>::search(const T &value) const
{
    return tree->search(value);
}

template<typename T>
Set<T> Set<T>::operator+(const Set<T> &set) const
{
    Set unionSet;
    QVector<T> firstVector = tree->toVector();
    QVector<T> secondVector = set.tree->toVector();
    int firstSize = firstVector.size();
    for (int i = 0; i < firstSize; i++)
        unionSet.add(firstVector[i]);
    int secondSize = secondVector.size();
    for (int i = 0; i < secondSize; i++)
        if (!unionSet.search(secondVector[i]))
            unionSet.add(secondVector[i]);
    return unionSet;
}

template<typename T>
Set<T> Set<T>::operator*(const Set<T> &set) const
{
    Set interseptionSet;
    QVector<T> vector = set.tree->toVector();
    int size = vector.size();
    for (int i = 0; i < size; i++)
        if (tree->search(vector[i]))
            interseptionSet.add(vector[i]);
    return interseptionSet;
}

template<typename T>
int Set<T>::size() const
{
    return tree->length();
}
