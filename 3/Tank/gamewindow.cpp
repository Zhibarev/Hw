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
}

GameWindow::~GameWindow()
{
    delete ui;
}
