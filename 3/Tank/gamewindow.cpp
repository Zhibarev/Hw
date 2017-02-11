#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "Shot/simpleshot.h"
#include <iostream>
#include <QtMath>
#include <game.h>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    Game *game = new Game(this);
    ui->gridLayout->addWidget(game);
    ui->gridLayout->setGeometry(game->geometry());
    this->setFocus();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
}
