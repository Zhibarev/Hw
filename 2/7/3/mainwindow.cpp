#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rules.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->centralWidget->setMinimumSize(90 * size, 90 * size);
    createField();
}

MainWindow::~MainWindow()
{
    if (field != nullptr)
    {
        for (int i = 1; i <= size; i++)
            delete []field[i];
        delete []field;
        delete signalMapper;
    }
    delete ui;
}

void MainWindow::startNewGame()
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
            delete field[i][j];
        delete []field[i];
    }
    delete signalMapper;
    delete []field;
    field = nullptr;
    isZero = false;
    newGame = new QPushButton;
    newGame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    newGame->setMinimumSize(80, 80);
    newGame->setText("New game");
    ui->gridLayout->addWidget(newGame);
    connect(newGame, SIGNAL(clicked(bool)), this, SLOT(createField()));
}

void MainWindow::createField()
{
    if (newGame != nullptr)
    {
        delete newGame;
        newGame = nullptr;
    }
    signalMapper = new QSignalMapper;
    field = new QPushButton**[size + 1];
    for (int i = 1; i <= size; i++)
        field[i] = new QPushButton*[size + 1];
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
        {
            field[i][j] = new QPushButton;
            field[i][j]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            field[i][j]->setMinimumSize(80, 80);
            ui->gridLayout->addWidget(field[i][j], i, j);
            connect(field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(field[i][j], i*10 + j);
        }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(changeCell(int)));
}



void MainWindow::changeCell(int index)
{
    int i = index / 10;
    int j = index - i * 10;
    if (field[i][j]->text() != "O" && field[i][j]->text() != "X")
    {
        if (isZero)
            field[i][j]->setText("O");
        else
            field[i][j]->setText("X");
        isZero = !isZero;
          if (rules.checkWin(field, i, j, size, lengthToWin))
              startNewGame();
    }
}
