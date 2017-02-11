#pragma once

#include <QGraphicsObject>
#include <QTimer>

class Explosion : public QGraphicsObject
{
    Q_OBJECT

public:
    Explosion(QPointF position, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

signals:
    void redraw(QGraphicsObject *explosion);

private slots:
    void updateRadius();

private:
    float currentRadius = 0;
    const int maxRadius = 50;
    const float speed = 80;
    const int fps = 60;
    const float second = 1000;

    QTimer redrawTimer;
};
