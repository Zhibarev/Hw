#pragma once

#include <QtNetwork>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include "game.h"

class LocalGame : public Game
{
    Q_OBJECT

public:
    Socket();
    ~Socket();

private slots:
    void connect();
    void connected();
    void start();
    void send(WhatHappen whatHappen);
    void read();
    void end(bool win);

private:
    QTcpSocket *socket = nullptr;
    Game *game = nullptr;
    QPushButton *startGame = nullptr;
    QLineEdit *ip = nullptr;

    virtual void newGame();
};
