#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    connect(ui->setConnection, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(ui->send, SIGNAL(clicked(bool)), this, SLOT(send()));
}

void Client::connected()
{
    disconnect(ui->setConnection, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(ui->setConnection, SIGNAL(clicked(bool)), this, SLOT(disconnectFromServer()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectFromServer()));
    ui->send->setEnabled(true);
    ui->setConnection->setText("Disconnect");
    ui->dialog->setText("Connected\n" + ui->dialog->toPlainText());
}

void Client::connectToServer()
{
    socket->connectToHost("localhost", ui->port->toPlainText().toInt());
}

void Client::disconnectFromServer()
{
    disconnect(socket, SIGNAL(disconnected()), this, SLOT(disconnectFromServer()));
    socket->disconnectFromHost();
    disconnect(ui->setConnection, SIGNAL(clicked(bool)), this, SLOT(disconnectFromServer()));
    connect(ui->setConnection, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    ui->setConnection->setText("Connect");
    ui->dialog->setText("Disconnected\n" + ui->dialog->toPlainText());
}

void Client::read()
{
    ui->dialog->setText("He: " + QString(socket->readLine()) + "\n" + ui->dialog->toPlainText());
}

void Client::send()
{
    socket->write(QByteArray(ui->toSend->toPlainText().toLatin1()));
    ui->dialog->setText("You: " + ui->toSend->toPlainText() + "\n" + ui->dialog->toPlainText());
    ui->toSend->clear();
}

Client::~Client()
{
    socket->disconnectFromHost();
    delete socket;
    delete ui;
}
