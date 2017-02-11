#pragma once

#include <QPointF>
#include <QVector>
#include <QGraphicsItem>

class Landscape : public QGraphicsItem
{
public:
    Landscape(QVector<QPointF> landscape);
    QVector<QPointF> toVector();
    /**
     * @brief angle
     * @param i
     * @return angle of i's line (numerate from 0)
     */
    float angle(int i) const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;
private:
    QVector<QPointF> landscape;
};
