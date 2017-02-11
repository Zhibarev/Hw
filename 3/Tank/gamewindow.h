#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <Tank/simpletank.h>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <landscape.h>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

    void mousePressEvent(QMouseEvent *event);
};
