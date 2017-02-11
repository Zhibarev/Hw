#include "tank.h"

#include <QtMath>

Tank::Tank(QPointF position , float speed, float movingAngle, float gunAngle)
{
    setPos(position);
    this->speed = speed;
    this->movingAngle = movingAngle;
    this->gunAngle = gunAngle;
}

void Tank::move(float time, Direction direction)
{
    setPos(speed * qCos(movingAngle) * time * direction + x(), speed * qSin(movingAngle) * time * direction + y());
}
