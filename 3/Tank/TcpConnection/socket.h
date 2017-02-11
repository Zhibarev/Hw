#pragma once

#include <QtNetwork>
#include "game.h"

class Socket : public QWidget
{
    Q_OBJECT

public:
    Socket();
    void start(bool isLeftPlayer);
    void connect(int IP);
    void connected();

private slots:
    void send(WhatHappen whatHappen);
    void read();
    void end(bool win);

private:
    QTcpSocket *socket = nullptr;
    Game *game = nullptr;
};
