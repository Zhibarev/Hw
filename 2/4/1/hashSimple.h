#pragma once

#include <string>
#include "hashfunction.h"

///@brief string[i]*i hash function
class HashSimple: public HashFunction
{
public:
    HashSimple(){}
    long int hash(const std::string &str, long int key) const;
    ~HashSimple(){}
};
