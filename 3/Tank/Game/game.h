#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include "LandScape/landscape.h"
#include "Tank/simpletank.h"

enum Command {moveLeft, moveRight, gunUp, gunDown, shoot, heavyShot, simpleShot};

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Game(bool isLeftTankUser, QWidget *parent = nullptr);

public slots:
    void enemyDoSmth(Command command);

private slots:
    void collisions(QGraphicsObject *object);

signals:
    void userDoSmth(Command command);
    /**
     * @brief emit this signal what explosion or shot collose with tank
     * @param win
     */
    void end(bool win);

private:
    QGraphicsScene *scene = nullptr;
    SimpleTank *userTank = nullptr;
    SimpleTank *enemyTank = nullptr;
    /**
     * @brief realization of delay between shoots
     */
    QTimer timer;
    QVector<QPointF> lines;
    Landscape *landscape = nullptr;
    const int fps = 60;
    /**
     * @brief delta time between two moving
     */
    const float deltaTime = 0.5;
    /**
     * @brief delta changes of tank's gun angle
     */
    const float deltaAngle = qDegreesToRadians(5.0);
    /**
     * @brief current line where is user tank
     */
    int userLine = 0;
    /**
     * @brief current line where is enemy tank
     */
    int enemyLine = 0;

    void keyPressEvent(QKeyEvent *pressed);
    /**
     * @brief check is tank change line of landscape or not, if yes adjust his position and moving angle
     * @param direction
     * @param tank
     */
    void changeLine(Direction direction, Tank *tank);
    void tankActions(Command command, SimpleTank *tank);
};
