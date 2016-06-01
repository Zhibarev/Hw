#pragma once

#include <QMainWindow>
#include <QWebFrame>
#include <QWebElement>
#include <QList>
#include <QWebPage>

namespace Ui {
class Bash;
}

/**
 * @brief Class for show comments from bash.in
 */
class Bash : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();

private slots:
    /**
     * @brief load page from bash.in
     */
    void load();
    /**
     * @brief show next comment
     */
    void next();
    void rateUp();
    void rateDown();
    void bayan();
    /**
     * @brief put page in QList "quotes"
     */
    void setQuotes();

private:
    Ui::Bash *ui;
    QWebPage *page = new QWebPage();
    QList<QWebElement> quotes;

    void disableRate();
};
