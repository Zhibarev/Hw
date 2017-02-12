#include "localgame.h"

LocalGame::LocalGame(bool isLeftTankUser, QWidget *parent):
    Game(isLeftTankUser, parent)
{
}

void LocalGame::setSocket(QTcpSocket *socket)
{
    this->socket = socket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(this, SIGNAL(userDoSmth(Command)), this, SLOT(send(Command)));
}

void LocalGame::read()
{
    enemyDoSmth(static_cast<Command>(socket->readAll().toInt()));
}

void LocalGame::send(Command command)
{
    socket->write(QString::number(static_cast<int>(command)).toLocal8Bit());
}
