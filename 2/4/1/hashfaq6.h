#pragma once

#include "hashfunction.h"
#include <string>

///@brief FAQ6 hash function, taked from https://habrahabr.ru/post/219139/
class HashFAQ6: public HashFunction
{
public:
    HashFAQ6(){}
    long int hash(const std::string &str, long int key) const;
    ~HashFAQ6(){}
};
