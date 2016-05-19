#pragma once

#include <string>
#include <QList>
#include "hashfunction.h"


/**
 * @brief Class to realize <int> hash table based on QList
 * Table use user's hash function, which is represented by HashFunction class
 */
class HashTable
{
public:
    HashTable(const HashFunction *function, unsigned long int newSize);
    void add(const std::string &str);
    void remove(const std::string &str);
    bool search(const std::string &str) const;
    void changeHash(const HashFunction *function);
    double loadFactor() const;
    unsigned long int countOfElements() const;
    unsigned long int countOfColumns() const;
    int lengthOfMaxColumn() const;
    void printMaxColumn() const;
    unsigned long int countOfEmptyColumns() const;
    ~HashTable();

private:
    unsigned long int size = 0;
    unsigned long int numberOfElements = 0;
    QList<std::string> *table = nullptr;
    const HashFunction *hash = nullptr;
    void rebuild(unsigned long int newSize);
    bool isPrime(unsigned long int number) const;
};
