#include "simpletank.h"
#include "Shot/heavyshot.h"
#include "Shot/simpleshot.h"
#include <QtMath>
#include <QPainter>

SimpleTank::SimpleTank(QPointF position, float movingAngle, float gunAngle):
    Tank(position, 5, movingAngle, gunAngle)
{
}

void SimpleTank::setMovingAngle(float angle)
{
    movingAngle = angle;
}

void SimpleTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawPolygon(triangle());
    drawGun(painter);
}

QPainterPath SimpleTank::shape() const
{
    QPainterPath path;
    path.addPolygon(triangle());
    return path;
}

float SimpleTank::gunX() const
{
    return gunLength * qCos(gunAngle);
}

float SimpleTank::gunY() const
{
    return gunLength * qSin(gunAngle);
}

QRectF SimpleTank::boundingRect() const
{
    return QRectF(- qMax(length, gunLength), - 2 * length - gunLength,
                  2 * qMax(length, gunLength), 2 * length + gunLength);
}

void SimpleTank::changeGunAngle(float delta)
{
    gunAngle = gunAngle + delta;
    if (gunAngle > M_PI)
        gunAngle = M_PI;
    if (gunAngle < 0)
        gunAngle = 0;
    update();
}

void SimpleTank::setShot(ShotType shot)
{
    this->shot = shot;
}

void SimpleTank::drawGun(QPainter *painter) const
{
    painter->setPen(Qt::black);
    painter->drawLine(0, -length * 2, gunX(), -length * 2 - gunY());
}

QPolygon SimpleTank::triangle() const
{
    QPolygon polygon;
    polygon << QPoint(0, -length * 2) << QPoint(length, 0) << QPoint(-length, 0);
    return polygon;
}

Shot *SimpleTank::shoot() const
{
    if (shot == simple)
        return new SimpleShot(QPointF(x() + gunX(), y() - 2 * length - gunY()),
                              QPointF(shotSpeed * qCos(gunAngle), shotSpeed * qSin(gunAngle)));
    float heavySpeed = shotSpeed * 2 / 3;
    return new HeavyShot(QPointF(x() + gunX(), y() - 2 * length - gunY()),
                         QPointF(heavySpeed * qCos(gunAngle), heavySpeed * qSin(gunAngle)));
}
