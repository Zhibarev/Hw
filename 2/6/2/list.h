#pragma once

/**
 * @brief Abstract list class
 */
class List
{
public:
    /**
     * @brief add value to specified position in list, list's first position is 1
     * Max position to add - list's length + 1
     * @param value
     * @param position
     */
    virtual void add(int value, int position) = 0;
    /**
     * @brief remove value from specified position, list's first position is 1
     * @param position
     * @return value
     */
    virtual int remove(int position) = 0;
    /**
     * @brief return value form specified position, list's first position is 1
     * @param position
     * @return value
     */
    virtual int extract(int position) = 0;
    /**
     * @brief print list
     */
    virtual void print() = 0;
    virtual bool empty() = 0;
    virtual int length() = 0;
    /**
     * @brief search value in list, and return his position, if it not include return 0
     * @param value
     * @return value's position or 0 if not include
     */
    virtual int search(int value) = 0;
    /**
     * @brief delete all values from list
     */
    virtual void clear() = 0;

    virtual ~List(){}
};
