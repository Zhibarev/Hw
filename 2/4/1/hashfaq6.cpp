#include "hashfaq6.h"

long int HashFAQ6::hash(const std::string &string, long int key) const
{
    unsigned long int hash = 0;
    const char *str = string.c_str();
    for (; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % key;
}
