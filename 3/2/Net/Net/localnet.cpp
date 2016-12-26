#include "localnet.h"
#include <QFile>
#include <iterator>

LocalNet::LocalNet(QVector<Computer*> pc, QVector<QVector<bool>> network)
{
    computers = pc;
    net = network;
    size = computers.size();
    for (int i = 0; i < size; i++)
        if (computers[i]->isInfected())
            infectComputers.push(i);
}

LocalNet::~LocalNet()
{
    for (int i = 0; i < size; i++)
        delete computers[i];

}

void LocalNet::step()
{
    QStack<int>::iterator end = infectComputers.end();
    for (QStack<int>::iterator i = infectComputers.begin(); i != end; ++i)
    {
        for (int j = 0 ; j < size; j++)
            if (net[*i][j] && !computers[j]->isInfected() && computers[j]->attack())
                infectComputers.push(j);
    }
}

QVector<Computer*> LocalNet::state() const
{
    return computers;
}

int LocalNet::getCountOfInfected() const
{
    return infectComputers.size();
}
