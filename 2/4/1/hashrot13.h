#pragma once

#include <string>
#include "hashfunction.h"

///@brief ROT13 hash function, taked from https://habrahabr.ru/post/219139/
class HashROT13: public HashFunction
{
public:
    HashROT13(){}
    long int hash(const std::string &str, long int key) const;
    ~HashROT13(){}
};
