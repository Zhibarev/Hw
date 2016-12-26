#pragma once

#include "Computer/computer.h"
#include <QString>
#include <QVector>
#include <QStack>


class LocalNet
{
public:
    /**
     * @brief LocalNet
     * @param computers
     * @param net describe computer's links as adjacency matrix
     */
    LocalNet(QVector<Computer*> computers, QVector<QVector<bool>> net);
    ~LocalNet();

    void step();
    QVector<Computer*> state() const;
    int getCountOfInfected() const;

private:
    int size = 0;

    QVector<Computer*> computers;
    QStack<int> infectComputers;
    QVector<QVector<bool>> net;
};
