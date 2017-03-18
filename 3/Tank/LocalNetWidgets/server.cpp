#include "server.h"
#include <QTcpSocket>
#include <QGridLayout>

Server::Server(QWidget *parent):
    QWidget(parent)
{
    server = new QTcpServer;
    server->listen();
    connect(server, SIGNAL(newConnection()), this, SLOT(connected()));

    setFixedSize(200, 130);
    setAttribute(Qt::WA_DeleteOnClose);

    QGridLayout *layout = new QGridLayout;
    setLayout(layout);

    dialog = new QLabel;
    QFont font;
    font.setPointSize(12);
    dialog->setFont(font);
    dialog->setText("Wait connection\n\nPort");
    layout->addWidget(dialog, 0, 0);

    QLineEdit *port = new QLineEdit;
    port->setText(tr("%1").arg(server->serverPort()));
    port->setEnabled(false);
    layout->addWidget(port, 1, 0);
}

Server::~Server()
{
    delete server;
    deleteLater();
}

void Server::connected()
{
    game = new LocalGame(false);
    game->setSocket(server->nextPendingConnection());
    connect(game, SIGNAL(end(bool)), this, SLOT(end(bool)));
    game->show();
    this->hide();
}

void Server::end(bool win)
{
    game->deleteLater();
    game = nullptr;
    dialog->setText("You lose");
    if (win)
        dialog->setText("You win");
    this->show();
}
