#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createField();
    foreach(QPushButton *button, this->findChildren<QPushButton *>())
    {
        connect(button, SIGNAL(clicked()), toOpen, SLOT(map()));
        toOpen->setMapping(button, button);
    }

    connect(toOpen, SIGNAL(mapped(QPushButton *)), this, SLOT(open(QPushButton *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getNumber(QPushButton *button)
{
    QString buttonName = button->accessibleName();
    int length = buttonName.length();
    int buttonNumber = 0;
    if (buttonName[length - 2] <=  '9' && buttonName[length - 2] >= '0')
        buttonNumber = (buttonName.toLatin1().data()[length - 2] - '0') * 10 + (buttonName.toLatin1().data()[length - 1] - '0');
    else
        buttonNumber = buttonName.toLatin1().data()[length - 1];
    return field[buttonNumber % size][buttonNumber / size];
}

void MainWindow::open(QPushButton *button)
{
    button->setText(QString::number(getNumber(button)));
    if (pressed == nullptr)
        pressed = button;
    else
    {
        if (getNumber(button) == getNumber(pressed))
        {
            button->setEnabled(false);
            pressed->setEnabled(false);
        }
        else
        {
            button->setText("");
            pressed->setText("");
        }
        pressed = nullptr;
    }
    button->setText("123");
}

void MainWindow::createField()
{
    field = new int*[size];
    for (int i = 0; i < size; i++)
        field[i] = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
           field[i][j] = rand()%2;
}
