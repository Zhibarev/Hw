#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stackcalculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach(QPushButton *button, this->findChildren<QPushButton *>())
    {
        if (button->text() != "=" && button->text() != "C")
        {
            connect(button, SIGNAL(clicked()), toAppend, SLOT(map()));
            toAppend->setMapping(button, button->text());
        }
    }
    connect(toAppend, SIGNAL(mapped(const QString &)), this, SLOT(append(const QString &)));
    connect(ui->equality, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clear()));
}

void MainWindow::append(const QString &symbol)
{
    ui->expression->setText(ui->expression->displayText() + symbol);
}

void MainWindow::calculate()
{
    StackCalculator calc;
    ui->expression->setText(QString::number(calc.calculator(ui->expression->displayText().toStdString().c_str())));
}

void MainWindow::clear()
{
    ui->expression->setText("");
}

MainWindow::~MainWindow()
{
    delete toAppend;
    delete ui;
}
