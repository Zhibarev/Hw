#include "computer.h"
#include <cstdlib>
#include <ctime>


Computer::Computer(OS *newOS, bool isinfect)
{
    infected = isinfect;
    os = newOS;
}

bool Computer::isInfected() const
{
    return infected;
}

bool Computer::attack()
{
    infected = (os->infectionChance() > (rand() % 100));
    return infected;
}

void Computer::changeInfection(bool isinfect)
{
    infected = isinfect;
}

Computer::~Computer()
{
    delete os;
}
