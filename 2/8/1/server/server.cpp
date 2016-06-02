#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    server = new QTcpServer;
    server->listen();

    ui->port->setPlainText(tr("%1").arg(server->serverPort()));

    connect(server, SIGNAL(newConnection()), this, SLOT(connected()));
    connect(ui->disconnect, SIGNAL(clicked(bool)), this, SLOT(disconnect()));
    connect(ui->send, SIGNAL(clicked(bool)), this, SLOT(send()));
}

Server::~Server()
{
    if (socket != nullptr)
        disconnect();
    delete server;
    delete ui;
}

void Server::disconnect()
{
    socket->disconnectFromHost();
    socket = nullptr;
    ui->disconnect->setEnabled(false);
    ui->send->setEnabled(false);
    ui->dialog->setText("Connect...\nDisconnected\n" + ui->dialog->toPlainText());
}

void Server::connected()
{
    socket = server->nextPendingConnection();
    ui->dialog->setText("Connected\n" + ui->dialog->toPlainText());
    ui->send->setEnabled(true);
    ui->disconnect->setEnabled(true);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
}

void Server::send()
{
    socket->write(QByteArray(ui->toSend->toPlainText().toLatin1()));
    ui->dialog->setText("You: " + ui->toSend->toPlainText() + "\n" + ui->dialog->toPlainText());
    ui->toSend->clear();
}

void Server::read()
{
    ui->dialog->setText("He: " + QString(socket->readLine()) + "\n" + ui->dialog->toPlainText());
}
