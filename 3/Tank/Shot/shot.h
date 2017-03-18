#pragma once

#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

/**
 * @brief interface of shot item
 * path shot like the path of body under force of gravity (g set in shot interface)
 */
class Shot : public QGraphicsObject
{
    Q_OBJECT

private slots:
    /**
     * @brief redraw item after 1 / fps seconds
     */
    void update();

signals:
    void redraw(QGraphicsObject *shot);

protected:
    Shot(QPointF position, QPointF speed, QGraphicsObject *parrent = nullptr);

    QPointF speed;
    float g = 30;
    int fps = 60;
    const float second = 1000;

    QTimer redrawTimer;
};
