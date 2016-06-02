#pragma once

#include <string>

///@brief base class for classes which realize hash function
class HashFunction
{
public:
    /**
     * @brief abstract function for hashing
     * @param string
     * @param key
     * @return hash value in interval from 0 to key - 1
     */
    virtual unsigned long int hashRealize(const std::string &str, unsigned long int key) const = 0;
    /**
     * @brief wrapper of hashRealize(str, key), guarantee that returned value from hash is in right interval.
     * if it is, return the same value, else return value % key
     * @param str
     * @param key
     * @return hashRealize(str, key) % key
     */
    unsigned long int hash(const std::string &str, unsigned long int key) const
    {
        return hashRealize(str, key) % key;
    }
    virtual ~HashFunction(){}
};
