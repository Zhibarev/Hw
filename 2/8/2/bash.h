#pragma once

#include <QMainWindow>
#include <QWebFrame>
#include <QWebElement>
#include <QList>
#include <QWebPage>

namespace Ui {
class Bash;
}

class Bash : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();

private slots:
    void load();
    void next();
    void rateUp();
    void rateDown();
    void bayan();
    void setQuotes();

private:
    Ui::Bash *ui;
    QWebPage *page = new QWebPage();
    QList<QWebElement> quotes;

    void disableRate();
};
