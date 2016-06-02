#pragma once

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class Server;
}

/**
 * @brief Class for realize server in local chat
 * Look Fortune Server Example
 */
class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
    void disconnect();
    void connected();
    void send();
    void read();

private:
    Ui::Server *ui;
    QTcpServer *server = nullptr;
    QTcpSocket *socket = nullptr;
};
