#include "explosion.h"
#include <iostream>
#include <QPainter>

Explosion::Explosion(QPointF position, QGraphicsObject *parent):
    QGraphicsObject(parent)
{
    setPos(position);
    connect(&redrawTimer, SIGNAL(timeout()), this, SLOT(updateRadius()));
    redrawTimer.start(second / fps);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    emit redraw(this);
    painter->setPen(Qt::black);
    painter->drawEllipse(boundingRect());
}

QRectF Explosion::boundingRect() const
{
    return QRectF(-currentRadius, -currentRadius, 2 * currentRadius, 2 * currentRadius);
}

QPainterPath Explosion::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;

}

void Explosion::updateRadius()
{
    if (currentRadius < maxRadius)
    {
        prepareGeometryChange();
        currentRadius += speed / fps;
        redrawTimer.start(second / fps);
        update();
    }
    else
        delete this;
}
