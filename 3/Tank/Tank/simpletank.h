#pragma once

#include "tank.h"
#include "Shot/shot.h"

enum ShotType{simple, heavy};

/**
 * @brief realization of tank, tank is right triangle,
 * can change types of shots, use simpleShot and heavyShot to shoot
 */
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
    /**
     * @brief half of triangle's side
     */
    const float length = 30;
    const float gunLength = 23;
    const float shotSpeed = 140;
    ShotType shot = simple;

    float gunX() const;
    float gunY() const;
    void drawGun(QPainter *painter) const;
    /**
     * @brief return tank's body
     * @return
     */
    QPolygon triangle() const;
};
