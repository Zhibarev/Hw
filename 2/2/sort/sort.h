#pragma once

///@brief Interface to sort array
class Sort
{
public:
    /**
     * @brief sort array from first element to last
     * @param array
     * @param index of first element
     * @param index of last index
     */
    virtual void sort(int *array, int first, int last) = 0;
};
