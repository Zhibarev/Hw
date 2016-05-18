#pragma once

#include <string>

///@brief abstract Hash Function class
class HashFunction
{
public:
    /**
     * @brief hash function
     * @param string
     * @param key
     * @return hash value in interval from 0 to key - 1
     */
    virtual long int hash(const std::string &str, long int key) const = 0;
    virtual ~HashFunction(){}
};
