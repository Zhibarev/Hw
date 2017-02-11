#pragma once

#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Shot : public QGraphicsObject
{
    Q_OBJECT

private slots:
    void update();

signals:
    void redraw(QGraphicsObject *shot);

protected:
    Shot(QPointF position, QPointF speed, QGraphicsObject *parrent = nullptr);

    QPointF speed;
    const float g = 30;
    const int fps = 60;
    const float second = 1000;

    QTimer redrawTimer;
};
