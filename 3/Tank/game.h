#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <Tank/simpletank.h>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <landscape.h>

enum Command {leftMove, rightMove, gunUp, gunDown, shot};

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr, bool isLeftTankUser = true);

private slots:
    void collisions(QGraphicsObject *object);
//    void enemyDoSmth(Command command);

signals:
    void end(bool win);
    void userDoSmth(Command command);

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
};
