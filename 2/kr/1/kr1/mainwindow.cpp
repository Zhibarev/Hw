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
        toOpen->setMapping(button, button->objectName());
    }

    connect(toOpen, SIGNAL(mapped(const QString &)), this, SLOT(open(const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getNumber(const QString &buttonName)
{
    int length = buttonName.length();
    int buttonNumber = 0;
    if (buttonName[length - 2] <=  '9' && buttonName[length - 2] >= '0')
        buttonNumber = (buttonName.toLatin1().data()[length - 2] - '0') * 10 + (buttonName.toLatin1().data()[length - 1] - '0');
    else
        buttonNumber = buttonName.toLatin1().data()[length - 1] - '0';
    return field[buttonNumber % size][(buttonNumber) / size];
}

void MainWindow::open(const QString &buttonName)
{
    QPushButton *button = this->findChild<QPushButton*>(buttonName);
    button->setText(QString::number(getNumber(buttonName)));
    if (pressed == nullptr)
    {
        pressed = button;
        pressed->setEnabled(false);
    }
    else
    {
        if (getNumber(buttonName) == getNumber(pressed->objectName()))
        {
            button->setEnabled(false);
            pressed->setEnabled(false);
        }
        else
        {
            button->setText("");
            pressed->setText("");
            pressed->setEnabled(true);
        }
        pressed = nullptr;
    }
}

void MainWindow::createField()
{
    field = new int*[size];
    for (int i = 0; i < size; i++)
    {
        field[i] = new int[size];
        for (int j = 0; j < size; j++)
            field[i][j] = -1;
    }
    srand(time(0));
    int freeCells = size * size;
    int cell = 0;
    int currentNumber = 0;
    srand(time(0));
    while (freeCells != 0)
    {
        currentNumber = rand() % 2;
        cell = chooseCell(freeCells);
        field[cell % size][cell / size] = currentNumber;
        freeCells--;
        cell = chooseCell(freeCells);
        field[cell % size][cell / size] = currentNumber;
        freeCells--;
    }
}

int MainWindow::chooseCell(int freeCells)
{
    int number = rand() % freeCells;
    int i = -1;
    int cell = -1;
    while (i != number)
    {
        cell++;
        if (field[cell % size][cell / size] == -1)
            i++;
    }
    return cell;
}
