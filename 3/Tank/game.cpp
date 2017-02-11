#include "game.h"
#include "Shot/simpleshot.h"
#include "Shot/heavyshot.h"
#include "explosion.h"
#include <QtMath>

Game::Game(bool isLeftTankUser, QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    lines << QPointF(0, 350) << QPointF(150, 350) << QPointF(330, 150) << QPointF(400, 200)
          << QPointF(600, 350) << QPointF(620, 120) << QPointF(700, 350) << QPointF(800, 350);
    landscape = new Landscape(lines);
    scene->addItem(landscape);
    if (isLeftTankUser)
    {
        userTank = new SimpleTank(lines[0], landscape->angle(0), 0);
        enemyTank = new SimpleTank(lines[lines.size() - 1], landscape->angle(lines.size() - 2), M_PI);
        currentLine = 0;
    }
    else
    {
        enemyTank = new SimpleTank(lines[0], landscape->angle(0), 0);
        userTank = new SimpleTank(lines[lines.size() - 1], landscape->angle(lines.size() - 2), M_PI);
        currentLine = lines.size() - 2;
    }
    scene->addItem(userTank);
    scene->addItem(enemyTank);
    this->setFixedSize(800, 400);
    scene->setSceneRect(this->geometry());
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(&timer, QTimer::timeout, &timer, QTimer::stop);
}

void Game::enemyDoSmth(WhatHappen whatHappen)
{
    tankActions(whatHappen, enemyTank);
}

void Game::collisions(QGraphicsObject *object)
{
    if (object->collidesWithItem(userTank))
        emit userDoSmth(lose);
    if (object->collidesWithItem(enemyTank))
        emit userDoSmth(win);
    if (dynamic_cast<Shot *>(object))
    {
        if (object->collidesWithItem(landscape))
        {
            HeavyShot *heavyShot = dynamic_cast<HeavyShot *>(object);
            if (heavyShot)
            {
                Explosion *explosion = heavyShot->explose();
                connect(explosion, SIGNAL(redraw(QGraphicsObject *)), this, SLOT(collisions(QGraphicsObject *)));
                scene->addItem(explosion);
            }
            delete object;
        }
        else
            if ((object->x() < lines[0].x() || object->x() > lines[lines.size() - 1].x()))
                    delete object;
    }
}

void Game::tankActions(WhatHappen command, SimpleTank *tank)
{
    switch(command)
    {
    case simpleShot:
        tank->setShot(simple);
        break;
    case heavyShot:
        tank->setShot(heavy);
        break;
    case gunUp:
        tank->changeGunAngle(deltaAngle);
        break;
    case gunDown:
        tank->changeGunAngle(-deltaAngle);
        break;
    case moveRight:
        tank->move(deltaTime, rightDirection);
        changeLine(rightDirection, tank);
        break;
    case moveLeft:
        tank->move(deltaTime, leftDirection);
        changeLine(leftDirection, tank);
        break;
    case shoot:
        if (!timer.isActive())
        {
            timer.start(1000);
            Shot *shot = tank->shoot();
            scene->addItem(shot);
            connect(shot, SIGNAL(redraw(QGraphicsObject *)), this, SLOT(collisions(QGraphicsObject *)));
        }
        break;
    }
}

void Game::keyPressEvent(QKeyEvent *pressed)
{
    switch(pressed->key())
    {
    case Qt::Key_1:
        tankActions(simpleShot, userTank);
        emit userDoSmth(simpleShot);
        break;
    case Qt::Key_2:
        tankActions(heavyShot, userTank);
        emit userDoSmth(heavyShot);
        break;
    case Qt::Key_Up:
        tankActions(gunUp, userTank);
        emit userDoSmth(gunUp);
        break;
    case Qt::Key_Down:
        tankActions(gunDown, userTank);
        emit userDoSmth(gunDown);
        break;
    case Qt::Key_Right:
        tankActions(moveRight, userTank);
        emit userDoSmth(moveRight);
        break;
    case Qt::Key_Left:
        tankActions(moveLeft, userTank);
        emit userDoSmth(moveLeft);
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        tankActions(shoot, userTank);
        emit userDoSmth(shoot);
        break;
    }
}

void Game::changeLine(Direction direction, Tank *tank)
{
    int border = currentLine + (direction * direction + direction) / 2;
    if (tank->x() * direction >= lines[border].x() * direction)
    {
        tank->setPos(lines[border]);
        if (border != lines.size() - 1 && border != 0)
        {
            tank->setMovingAngle((landscape->angle(currentLine + direction)));
            currentLine += direction;
        }
    }
}
