#pragma once

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    /**
     * @brief close game window and open server widget
     */
    void generateServer();
    /**
     * @brief close game window and open client widget
     */
    void generateClient();

private:
    Ui::GameWindow *ui;
};
