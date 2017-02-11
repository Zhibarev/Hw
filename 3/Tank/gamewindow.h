#pragma once

#include <QMainWindow>
#include "TcpConnection/socket.h"
#include "TcpConnection/server.h"

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
};
