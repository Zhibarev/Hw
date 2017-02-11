#include "socket.h"

Socket::Socket()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(read()));
    connect(IP, SIGNAL(userDoSmth(Command)), this, SLOT(send(Command)));
}

void Socket::read()
{
    WhatHappen whatHappen = static_cast<WhatHappen>(socket->readAll().toInt());
    if (whatHappen == win || whatHappen == lose)

    game->enemyDoSmth(static_cast<Command>(this->readAll().toInt()));
}

void Socket::send(Command command)
{
    write(QString(static_cast<int>(command)).toLocal8Bit());
}

void Socket::startGame(bool isLeftPlayer)
{
    socket->children().clear();
    game = new Game(isLeftPlayer);
}


