#pragma once

#include <QString>

class AlreadyInclude
{
    QString what()
    {
        return "Value already include to tree";
    }
};

class NothingToRemove
{
    QString what()
    {
        return "Value didn't exist in tree";
    }
};
