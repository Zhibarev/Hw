#pragma once

#include "hashfunction.h"
#include <string>

/** @brief Class extend from abstract class HashFunction.
 * Use FAQ6 hash function.
 * Took from https://habrahabr.ru/post/219139/
 */
class HashFAQ6: public HashFunction
{
public:
    HashFAQ6(){}
    unsigned long int hashRealize(const std::string &str, unsigned long int key) const;
    ~HashFAQ6(){}
};
