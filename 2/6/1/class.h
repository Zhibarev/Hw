#pragma once

#include <iostream>

class Class
{
public:
    Class(){}
    ~Class()
    {
        std::cout << "Destructor called\n";
    }
};
