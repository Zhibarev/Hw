#pragma once

#include "Computer/os.h"

class WeakOS : public OS
{
public:
    WeakOS():
        OS(100)
    {}
};
