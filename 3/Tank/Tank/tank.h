#pragma once

#include <QGraphicsItem>
#include "Shot/shot.h"

enum Direction {right = 1, left = -1};

class Tank : public QGraphicsItem
{
public:
    virtual void changeGunAngle(float delta) = 0;
    virtual void setMovingAngle(float angle) = 0;
    virtual Shot *shoot() const = 0;

    void move(float time, Direction direction);

protected:
    Tank(QPointF position, float speed, float movingAngle, float gunAngle);

    float speed = 0;
    float movingAngle = 0;
    float gunAngle = 0;
};
