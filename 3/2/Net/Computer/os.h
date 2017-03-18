#pragma once

/**
 * @brief interface for OS
 */
class OS
{
public:

    OS(int chance)
    {
        this->chance = chance;
    }

    int infectionChance() const
    {
        return chance;
    }

private:
    /**
     * @brief chance that virus attack will have success
     */
    int chance = 100;
};
