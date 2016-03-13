#ifndef ARRAYLIST_H
#define ARRAYLIST_H


class ArrayList
{
public:
    ArrayList(int newSize);
    void add(int newValue);
    void remove(int index);
    void print();
    bool isEmpty();
    int search(int searchedValue);
    void clear();
    ~ArrayList();
private:
    int *array;
    int size;
};

#endif // ARRAYLIST_H
