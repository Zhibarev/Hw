#include "hashrot13.h"

unsigned long int HashROT13::hashRealize(const std::string &string, unsigned long int key) const
{
    unsigned long int hash = 0;
    const char *str = string.c_str();
    for(; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash -= (hash << 13) | (hash >> 19);
    }
    return (unsigned long int) hash % key;
}
