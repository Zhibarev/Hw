#pragma once

#include "avltree.h"

template <typename T>
/**
 * @brief template class Bag based on AVLTree
 * Has overloaded operators +(union) and *(intersection)
 */
class Bag
{
public:
    Bag();
    ~Bag();
    /**
     * @brief add value to bag
     * throw AlreadyInclude if value if alredy include to bag
     * @param value
     */
    void add(const T &value);
    /**
     * @brief remove value from bag
     * throw NothingToRemove if bag doesn't contain value
     * @param value
     */
    void remove(const T &value);
    bool search(const T &value) const;
    int size() const;
    /**
     * @brief union of Bags
     * Use converBagion to vector
     * @param Bag
     * @return union
     */
    Bag<T> operator+(const Bag<T> &bag) const;
    /**
     * @brief interseption of Bags
     * Use converBagion to vector
     * @param Bag
     * @return interseption
     */
    Bag<T> operator*(const Bag<T> &bag) const;
private:
    AVLTree<T> *tree = nullptr;
};

template<typename T>
Bag<T>::Bag()
{
    tree = new AVLTree<T>();
}

template<typename T>
Bag<T>::~Bag()
{
    delete tree;
}

template<typename T>
void Bag<T>::add(const T &value)
{
    tree->add(value);
}

template<typename T>
void Bag<T>::remove(const T &value)
{
    tree->remove(value);
}

template<typename T>
bool Bag<T>::search(const T &value) const
{
    return tree->search(value);
}

template<typename T>
Bag<T> Bag<T>::operator+(const Bag<T> &bag) const
{
    Bag unionBag;
    QVector<QVector<T>> firstVector = tree->toVector();
    QVector<QVector<T>> secondVector = bag.tree->toVector();
    int firstSize = firstVector[0].size();
    for (int i = 0; i < firstSize; i++)
        unionBag.add(firstVector[0][i]);
    int secondSize = secondVector[0].size();
    for (int i = 0; i < secondSize; i++)
        unionBag.add(secondVector[0][i]);
    return unionBag;
}

template<typename T>
Bag<T> Bag<T>::operator*(const Bag<T> &bag) const
{
    Bag interseptionBag;
    QVector<QVector<T>> firstVector = bag.tree->toVector();
    QVector<QVector<T>> secondVector = tree->toVector();
    int firstSize = firstVector[0].size();
    int secondSize = secondVector[0].size();
    for (int i = 0; i < firstSize; i++)
        if (tree->search(firstVector[0][i]))
        {
            int sameValue = 0;
            for (int j = 0; j < secondSize; j++)
                if(firstVector[0][i] == secondVector[0][j])
                    sameValue = j;
            int min = firstVector[1][i] < secondVector[1][sameValue] ? firstVector[1][i] : secondVector[1][sameValue];
            for (int j = 0; j < min; j++)
                interseptionBag.add(firstVector[0][i]);
        }
    return interseptionBag;
}

template<typename T>
int Bag<T>::size() const
{
    return tree->length();
}
