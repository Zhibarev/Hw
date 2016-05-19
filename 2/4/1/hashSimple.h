#pragma once

#include <string>
#include "hashfunction.h"

/** @brief Class extend from abstract class HashFunction
 * Use function like sum(string[i] * i)
 */
class HashSimple: public HashFunction
{
public:
    HashSimple(){}
    /**
     * @return sum(str[i] * (i + 1)) % key, i changes from 0 to str's end
     */
    unsigned long int hashRealize(const std::string &str, unsigned long int key) const;
    ~HashSimple(){}
};
