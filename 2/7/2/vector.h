#pragma once

#include "vectorexpetions.h"

template <typename T, int dimension>
/**
 * @brief Realization of template vector with specified dimension
 */
class Vector
{
public:
    /**
     * @brief fill all vector's cordinates by 0
     */
    Vector();
    /**
     * @brief copy all coordinates of another vector
     * @param vector
     */
    Vector(const Vector<T, dimension> &vector);
    ~Vector();

    T& operator[](int i) const;
    /**
     * @brief standart vector sum
     * @return
     */
    Vector<T, dimension> operator+(const Vector<T, dimension> &vector) const;
    /**
     * @brief standart vector substract
     * @param vector
     * @return
     */
    Vector<T, dimension> operator-(const Vector<T, dimension> &vector) const;
    /**
     * @brief scalar multypli
     * @param vector
     * @return
     */
    T operator*(const Vector<T, dimension> &vector) const;
    bool isZero() const;

private:
    int *vector = new int[dimension];
};

template <typename T, int dimension>
Vector<T, dimension>::Vector()
{
    for (int i = 0; i < dimension; i++)
        vector[i] = 0;
}

template <typename T, int dimension>
Vector<T, dimension>::Vector(const Vector<T, dimension> &toCopy)
{
    for (int i = 0; i < dimension; i++)
        vector[i] = toCopy[i];
}

template <typename T, int dimension>
Vector<T, dimension>::~Vector()
{
    delete []vector;
}

template <typename T, int dimension>
T Vector<T, dimension>::operator*(const Vector<T, dimension> &toMultiply) const
{
    T result = 0;
    for (int i = 0; i < dimension; i++)
        result += vector[i] * toMultiply[i];
    return result;
}

template <typename T, int dimension>
Vector<T, dimension> Vector<T, dimension>::operator+(const Vector<T, dimension> &toSum) const
{
    Vector<T, dimension> result;
    for (int i = 0; i < dimension; i++)
        result[i] = vector[i] + toSum[i];
    return result;
}

template <typename T, int dimension>
Vector<T, dimension> Vector<T, dimension>::operator-(const Vector<T, dimension> &toSubstract) const
{
    Vector<T, dimension> result;
    for (int i = 0; i < dimension; i++)
        result[i] = vector[i] - toSubstract[i];
    return result;
}

template <typename T, int dimension>
T& Vector<T, dimension>::operator[](int i) const
{
    if (i >= dimension || i < 0)
        throw OutOfRange();
    return vector[i];
}

template <typename T, int dimension>
bool Vector<T, dimension>::isZero() const
{
    bool zero = true;
    for (int i = 0; i < dimension; i++)
        if (vector[i] != 0)
            zero = false;
    return zero;
}
