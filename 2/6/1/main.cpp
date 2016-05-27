#include "class.h"
#include <iostream>

void function()
{
    throw "error";
}

int main()
{
    try
    {
        Class object;
        function();
    }catch(...)
    {
        std::cout << "Exeption caught\n";
    }
    return 0;
}
