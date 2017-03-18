#include "Shot/simpleshot.h"
#include <Tank/tank.h>
#include <QPainter>

SimpleShot::SimpleShot(QPointF position, QPointF speed):
    Shot(position, speed)
{
}

QRectF SimpleShot::boundingRect() const
{
    return QRectF(-radius, -radius, 2 * radius, 2 * radius);
}

void SimpleShot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    emit redraw(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawEllipse(0, 0, radius, radius);
}

QPainterPath SimpleShot::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void SimpleShot::setRadius(int radius)
{
    this->radius = radius;
}
