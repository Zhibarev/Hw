#include "landscape.h"

#include <QPainter>
#include <QtMath>

Landscape::Landscape(QVector<QPointF> landscape)
{
    this->landscape = landscape;
}

QVector<QPointF> Landscape::toVector()
{
    return landscape;
}

float Landscape::angle(int i) const
{
    return qAtan((landscape[i + 1].y() - landscape[i].y()) / (landscape[i + 1].x() - landscape[i].x()));
}

void Landscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->drawPolyline(landscape);
}

QRectF Landscape::boundingRect() const
{
    float minY = landscape[0].y();
    float maxY = landscape[0].y();
    float minX = landscape[0].x();
    float maxX = landscape[0].x();
    int size = landscape.size();
    for (int i = 1; i < size; i++)
    {
        minY = qMin(minY, (float)landscape[i].y());
        maxY = qMax(maxY, (float)landscape[i].y());
        minX = qMin(minX, (float)landscape[i].x());
        maxX = qMax(maxX, (float)landscape[i].x());
    }
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

QPainterPath Landscape::shape() const
{
    QPainterPath path;
    int dY = 1;
    int size = landscape.size();
    for (int i = 0; i < size - 1; i++)
        if (landscape[i].y() == landscape[i + 1].y())
            path.addRect(landscape[i].x(),
                         landscape[i].y(),
                         landscape[i + 1].x() - landscape[i].x(),
                         landscape[i + 1].y() + dY - landscape[i].y());
        else
        {
            QPolygonF triangle;
            triangle << landscape[i] << landscape[i + 1];
            if (landscape[i].y() > landscape[i + 1].y())
                triangle << QPointF(landscape[i + 1].x(), landscape[i].y());
            else
                triangle << QPointF(landscape[i].x(), landscape[i + 1].y());
            path.addPolygon(triangle);
        }
    return path;
}
