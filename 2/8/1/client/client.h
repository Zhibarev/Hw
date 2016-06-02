#pragma once

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class Client;
}
\
/**
 * @brief Class for realize client in local chat
 * Look Fortune Client Example
 */
class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void connectToServer();
    void read();
    void send();
    void connected();
    void disconnectFromServer();

private:
    Ui::Client *ui;
    QTcpSocket *socket = new QTcpSocket;
};
