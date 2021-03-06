#include "hashtable.h"
#include <iostream>
#include <cmath>

HashTable::HashTable(const HashFunction *function, unsigned long int newSize)
{
    newSize += (newSize + 1) % 2;
    while (!isPrime(newSize))
        newSize += 2;
    size = newSize;
    table = new QList<std::string>[size];
    for (int i = 0; i < size; i++)
        table[i] = QList<std::string>();
    hash = function;
}

void HashTable::add(const std::string &str)
{
    if (loadFactor() >= 3)
    {
        unsigned long int newSize = size * 2 + 1;
        while (!isPrime(newSize))
            newSize += 2;
        rebuild(newSize);
    }
    numberOfElements++;
    table[hash->hash(str, size)].append(str);
}

void HashTable::remove(const std::string &str)
{
    if (search(str))
        table[hash->hash(str, size)].removeOne(str);
    else
        throw NothingToRemove();
}

bool HashTable::search(const std::string &str) const
{
    return (table[hash->hash(str, size)].indexOf(str) != -1);
}

void HashTable::changeHash(const HashFunction *function)
{
    hash = function;
    rebuild(size);
}

double HashTable::loadFactor() const
{
    return (double) numberOfElements / (double) size;
}

unsigned long int HashTable::countOfElements() const
{
    return numberOfElements;
}

int HashTable::lengthOfMaxColumn() const
{
    QList<std::string> maxColumn = table[0];
    for (long int i = 1; i < size; i++)
        if (maxColumn.size() < table[i].size())
            maxColumn = table[i];
    return maxColumn.size();
}

void HashTable::printMaxColumn() const
{
    QList<std::string> maxColumn = table[0];
    for (unsigned long int i = 1; i < size; i++)
        if (maxColumn.size() < table[i].size())
            maxColumn = table[i];
    int length = maxColumn.size();
    for (int i = 0; i < length; i++)
        std::cout << maxColumn[i] << " ";
}

unsigned long int HashTable::countOfEmptyColumns() const
{
    unsigned long int count = 0;
    for (unsigned long int i = 0; i < size; i++)
        if(table[i].length() == 0)
            count++;
    return count;
}

bool HashTable::isPrime(unsigned long int number) const
{
    long int root = sqrt(number);
    for (long int i = 2; i <= root; i++)
        if (number % i == 0)
            return false;
    return true;
}

void HashTable::rebuild(unsigned long int newSize)
{
    QList<std::string> *newTable = new QList<std::string> [newSize];
    for (unsigned long int i = 0; i < size; i++)
        newTable[i] = QList<std::string>();
    std::string str = "";
    for (unsigned long int i = 0; i < size; i++)
    {
        while (!table[i].isEmpty())
        {
            str = table[i][0];
            table[i].removeFirst();
            newTable[hash->hash(str, newSize)].append(str);
        }
    }
    size = newSize;
    delete []table;
    table = newTable;
}

unsigned long int HashTable::countOfColumns() const
{
    return size;
}

HashTable::~HashTable()
{
    delete []table;
}

