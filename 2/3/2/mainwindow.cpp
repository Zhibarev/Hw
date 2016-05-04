#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->firstNumber, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainWindow::calculate);
    connect(ui->secondNumber, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainWindow::calculate);
    connect(ui->action, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    enum {plus, minus, multiply, division};
    int firstNumber = ui->firstNumber->value();
    int secondNumber = ui->secondNumber->value();
    int action = ui->action->currentIndex();
    int result = 2;
    bool fail = false;
    switch (action)
    {
        case plus:
            result = firstNumber + secondNumber;
            break;
        case minus:
            result = firstNumber - secondNumber;
            break;
        case multiply:
            result = firstNumber * secondNumber;
            break;
        case division:
            if (secondNumber == 0)
                fail = true;
            else
                result = firstNumber / secondNumber;
            break;
    }
    if (!fail)
        ui->result->setText(QString::number(result));
    else
        ui->result->setText("Division on zero");
}
