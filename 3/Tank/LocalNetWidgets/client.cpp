#include "client.h"
#include <QTcpSocket>
#include <QPushButton>

Client::Client(QWidget *parent):
    QWidget(parent)
{
    socket = new QTcpSocket;

    setFixedSize(200, 130);
    setAttribute(Qt::WA_DeleteOnClose);

    QGridLayout *layout = new QGridLayout;
    setLayout(layout);

    QPushButton *connectButton = new QPushButton;
    connectButton->setText("Connect");
    layout->addWidget(connectButton, 3, 0);
    connect(connectButton, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));

    port = new QLineEdit;
    layout->addWidget(port, 2, 0);

    dialog = new QLabel;
    QFont font;
    font.setPointSize(12);
    dialog->setFont(font);
    dialog->setText("Enter port and\npush connect button");
    layout->addWidget(dialog, 0, 0);
}

Client::~Client()
{
    delete socket;
    deleteLater();
}

void Client::connectToServer()
{
    socket->abort();
    socket->connectToHost("localhost", port->text().toInt());
}

void Client::connected()
{
    game = new LocalGame(true);
    game->setSocket(socket);
    connect(game, SIGNAL(end(bool)), this, SLOT(end(bool)));
    game->show();
    this->hide();
}

void Client::end(bool win)
{
    game->deleteLater();
    game = nullptr;
    socket->disconnectFromHost();
    dialog->setText("You lose");
    if (win)
        dialog->setText("You win");
    this->show();
}
