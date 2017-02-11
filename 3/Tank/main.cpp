#include "game.h"
#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w(true);
    w.show();
    GameWindow window;
    window.show();
    return a.exec();
}
