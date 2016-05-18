#pragma once

#include <string>
#include <QList>
#include "hashfunction.h"


///@brief int hash table
class HashTable
{
public:
    HashTable(HashFunction *function, int newSize);
    void add(const std::string &str);
    void remove(const std::string &str);
    bool search(const std::string &str) const;
    void changeHash(HashFunction *function);
    double loadFactor() const;
    long int countOfElements() const;
    long int countOfColumns() const;
    int lengthOfMaxColumn() const;
    void printMaxColumn() const;
    long int countOfEmptyColumns() const;
    ~HashTable();

private:
    long int size = 0;
    long int numberOfElements = 0;
    QList<std::string> *table = nullptr;
    HashFunction *hash = nullptr;
    void rebuild(long int newSize);
    bool isPrime(long int number) const;
};
