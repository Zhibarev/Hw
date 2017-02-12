#pragma once

#include <QPair>
#include <QColor>
#include "shot.h"


/**
 * @brief realization of circular shot
 */
class SimpleShot : public Shot
{

public:
    SimpleShot(QPointF position, QPointF speed);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

protected:
    void setRadius(int radius);

private:
    int radius = 5;
};
