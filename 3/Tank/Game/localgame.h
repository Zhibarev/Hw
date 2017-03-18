#pragma once

#include <QTcpSocket>
#include "Game/game.h"

/**
 * @brief add interaction with socket to game
 */
class LocalGame : public Game
{
    Q_OBJECT

public:
    LocalGame(bool isLeftTankUser, QWidget *parent = nullptr);
    void setSocket(QTcpSocket *socket);

private slots:
    /**
     * @brief read from socket
     */
    void read();
    /**
     * @brief send to socket
     * @param command
     */
    void send(Command command);

private:
    QTcpSocket *socket = nullptr;
};
