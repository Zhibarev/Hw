#pragma once

#include "Computer/os.h"

class Computer
{
public:
    Computer(OS *newOS, bool infected);
    ~Computer();

    bool isInfected() const;
    /**
     * @brief attack
     * @return true if system infected after attack false if not
     */
    bool attack();

    void changeInfection(bool infected);

private:
    bool infected = false;
    OS *os;
};
