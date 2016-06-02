#pragma once

#include <string>
#include "hashfunction.h"

/** @brief Class extend from abstract class HashFunction.
 * Use ROT13 hash function.
 * Took from https://habrahabr.ru/post/219139/
 */
class HashROT13: public HashFunction
{
public:
    HashROT13(){}
    unsigned long int hashRealize(const std::string &str, unsigned long int key) const;
    ~HashROT13(){}
};
