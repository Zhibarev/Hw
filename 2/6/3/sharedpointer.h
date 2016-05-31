#pragma once

template <typename T>
/**
 * @brief Realization of shared pointer
 * Has pointer countOfPointers, which store count of pointers on cell of memory
 */
class SharedPointer
{
public:
    SharedPointer(T *cell);
    SharedPointer(const SharedPointer<T> &pointer);
    ~SharedPointer();

    /**
     * @brief function, which return normal pointer
     * @return
     */
    T* get() const;
    /**
     * @brief return pointer's value
     * @return pointer's value
     */
    T& operator*() const;
    /**
     * @brief Copy pointer to object
     * Copy pointer's fields, and increase new countOfPointers by 1
     * If only this object pointed on cell of memory, delete it and countOfPointers, else decreasess countOfPointers by 1
     * @param pointer
     */
    void operator=(SharedPointer<T> &pointer);
    /**
     * @brief function for return count of pointers on cell of memory
     * @return count of pointers on cell of memory
     */
    int count() const;

private:
    T* cell = nullptr;
    int* countOfPointers = nullptr;
};

template <typename T>
SharedPointer<T>::SharedPointer(T *newCell)
{
    cell = newCell;
    countOfPointers = new int;
    *countOfPointers = 1;
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointer)
{
    cell = pointer.cell;
    countOfPointers = pointer.countOfPointers;
    *countOfPointers = *countOfPointers + 1;
}

template <typename T>
T& SharedPointer<T>::operator*() const
{
    return *cell;
}

template <typename T>
T* SharedPointer<T>::get() const
{
    return cell;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    *countOfPointers = *countOfPointers - 1;
    if (countOfPointers && *countOfPointers == 0)
    {
        delete cell;
        delete countOfPointers;
    }
}

template <typename T>
void SharedPointer<T>::operator=(SharedPointer<T> &pointer)
{
    *countOfPointers = *countOfPointers - 1;
    if (*countOfPointers == 0)
    {
        delete cell;
        delete countOfPointers;
    }
    cell = pointer.get();
    countOfPointers = pointer.countOfPointers;
    *countOfPointers = *countOfPointers + 1;
}

template <typename T>
int SharedPointer<T>::count() const
{
    return *countOfPointers;
}
