#include "socket.h"

Socket::Socket()
{
    socket = new QTcpSocket;
    connect(this, SIGNAL(readyRead()), this, SLOT(read()));
    connect(IP, SIGNAL(userDoSmth(Command)), this, SLOT(send(Command)));
}

Socket::~Socket()
{
    delete socket;
    if (game)
        delete game;
}

void Socket::start(bool isLeftPlayer)
{

}

void Socket::read()
{
    WhatHappen whatHappen = static_cast<WhatHappen>(socket->readAll().toInt());
    if (whatHappen == win || whatHappen == lose)
        end(whatHappen);
    game->enemyDoSmth(static_cast<Command>(this->readAll().toInt()));
}

void Socket::send(Command command)
{
    write(QString(static_cast<int>(command)).toLocal8Bit());
}

void Socket::start(bool isLeftPlayer)
{
    removeWidget(startGame);
    removeWidget(ip);
    addWidget(game) = new Game(isLeftPlayer);
    game->show();
}

void Socket::end(bool win)
{
    delete game;

}

void Socket::newGame()
{
    addWidget(ip, 0, 0);
    addWidget(startGame, 1, 0);
    startGame->setText("Connect");
    connect(startGame, SIGNAL(pressed()), this, SLOT(connect()));
}


