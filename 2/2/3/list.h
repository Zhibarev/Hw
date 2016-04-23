#pragma once

using namespace std;

///@brief interface for int List
class List
{
public:
    virtual void add(int newValue, int position) = 0;
    /**
     * @brief remove value from specified positon
     * @param position
     * @return value or 0 if position > size
     */
    virtual int remove(int position) = 0;
    /**
     * @brief return value from specified positon
     * @param position
     * @return value
     */
    virtual int extract(int position) const = 0;
    virtual void print() const = 0;
    virtual bool empty() const = 0;
    virtual int length() const = 0;
    /**
     * @brief search element which equal to this value
     * @param value
     * @return position of element or 0 if list doesn't contain element with this value
     */
    virtual int search(int value) const = 0;
    virtual ~List(){}
};
