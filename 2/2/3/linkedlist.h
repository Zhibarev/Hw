#pragma once
#include "list.h"

///@brief int Linked List, realizate with guardian
class LinkedList : public List
{
public:
    /**
     * @brief add value on specified positon
     * @param value
     * @param position
     */
    void add(int newValue, int position);
    /**
     * @brief remove value from specified position
     * @param position
     * @return value
     */
    int remove(int position);
    /**
     * @brief return value from specified position
     * @param position
     * @return value
     */
    int extract(int position) const;
    /**
     * @brief print list
     */
    void print() const;
    /**
     * @brief check is list empty
     * @return if list is empty return true else return false
     */
    bool empty() const;
    /**
     * @brief return length of list
     * @return length of list
     */
    int length() const;
    /**
     * @brief search value and return his position
     * @param value
     * @return position of this value
     */
    int search(int value) const;
    ///@brief delete all values from list
    void clear();
    ~LinkedList();
private:
    /**
     * @brief class for realizate node of linked list,he have two fields:
     * value
     * point on next node
     */
    class ListNode
    {
    public:
        /**
         * @brief ListNode's constructor
         * @param value
         * @param point on next node
         */
        ListNode(int newValue, ListNode *nextNode);
        int value;
        ListNode *next;
    };
    ///@brief guardian - the first element of list
    ListNode *head = new ListNode(0, nullptr);
    int size = 0;
};
