#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <Tank/simpletank.h>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <landscape.h>

enum WhatHappen {moveLeft, moveRight, gunUp, gunDown, shoot, heavyShot, simpleShot, win, lose};

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Game(bool isLeftTankUser, QWidget *parent = nullptr);

public slots:
    void enemyDoSmth(WhatHappen whatHappen);

private slots:
    void collisions(QGraphicsObject *object);

signals:
    void userDoSmth(WhatHappen whatHappen);

private:
    QGraphicsScene *scene;
    SimpleTank *userTank;
    SimpleTank *enemyTank;
    QTimer timer;
    QVector<QPointF> lines;
    Landscape *landscape;
    const int fps = 60;
    const float deltaTime = 0.5;
    const float deltaAngle = qDegreesToRadians(5.0);
    int currentLine = 0;

    void keyPressEvent(QKeyEvent *pressed);
    void changeLine(Direction direction, Tank *tank);
    void tankActions(WhatHappen command, SimpleTank *tank);
};
