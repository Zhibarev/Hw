#pragma once

#include <QTcpServer>
#include <QLineEdit>
#include <QLabel>
#include "Game/localgame.h"

/**
 * @brief widget that represent server and describe connection with client
 * Server's tank always right
 */
class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    /**
     * @brief hide server widget and start game
     */
    void connected();
    /**
     * @brief end game and start server widget
     * @param win
     */
    void end(bool win);

private:
    LocalGame *game = nullptr;
    QTcpServer *server = nullptr;
    QLabel *dialog = nullptr;
};
