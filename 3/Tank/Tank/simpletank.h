#pragma once

#include "tank.h"
#include "Shot/shot.h"

enum ShotType{simple, heavy};

class SimpleTank : public Tank
{
public:
    SimpleTank(QPointF position, float movingAngle, float gunAngle);

    void setMovingAngle(float angle);
    void changeGunAngle(float delta);
    void setShot(ShotType shot);
    Shot *shoot() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

private:
    const float length = 30;
    const float gunLength = 23;
    const float shotSpeed = 140;
    ShotType shot;

    float gunX() const;
    float gunY() const;
    void drawGun(QPainter *painter) const;
    QPolygon triangle() const;
};
