#include "hashsimple.h"

long int HashSimple::hash(const std::string &str, long int key) const
{
    unsigned long int hash = 0;
    int length = str.length();
    for (int i = 1; i <= length; i++)
        hash = hash + str[i - 1] * i;
    return hash % key;
}

