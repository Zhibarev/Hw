#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>
#include <LocalNetWidgets/client.h>
#include <LocalNetWidgets/server.h>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    connect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(generateClient()));
    connect(ui->serverButton, SIGNAL(clicked(bool)), this, SLOT(generateServer()));
    connect(ui->serverClient, SIGNAL(clicked(bool)), this, SLOT(generateServer()));
    connect(ui->serverClient, SIGNAL(clicked(bool)), this, SLOT(generateClient()));
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::generateClient()
{
    Client *client = new Client;
    client->show();
    close();
}

void GameWindow::generateServer()
{
    Server *server = new Server;
    server->show();
    close();
}
