#include "shot.h"

Shot::Shot(QPointF position, QPointF speed, QGraphicsObject *parrent):
    QGraphicsObject(parrent)
{
    setPos(position);
    this->speed = speed;
    connect(&redrawTimer, SIGNAL(timeout()), this, SLOT(update()));
    redrawTimer.start(second / fps);
}

void Shot::update()
{
    setPos(x() + speed.x() / fps, y() - speed.y() / fps);
    speed.setY(speed.y() -  g / fps);
    redrawTimer.start(second / fps);
}
