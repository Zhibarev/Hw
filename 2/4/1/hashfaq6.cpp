#include "hashfaq6.h"

unsigned long int HashFAQ6::hashRealize(const std::string &string, unsigned long int key) const
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
