#pragma once

#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include "Game/localgame.h"

/**
 * @brief widget that represent client and describe connection with server
 * Client's tank always left
 */
class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void connectToServer();
    /**
     * @brief hide client widget and start game
     */
    void connected();
    /**
     * @brief end game and show client widget
     * @param win
     */
    void end(bool win);

private:
    LocalGame *game = nullptr;
    QTcpSocket *socket = nullptr;
    QLineEdit *port = nullptr;
    QLabel *dialog = nullptr;
};
