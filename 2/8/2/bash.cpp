#include "bash.h"
#include "ui_bash.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QtNetwork>

Bash::Bash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bash)
{
    ui->setupUi(this);

    connect(ui->load, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(page, SIGNAL(loadFinished(bool)), this, SLOT(setQuotes()));
    connect(ui->bayan, SIGNAL(clicked(bool)), this, SLOT(bayan()));
    connect(ui->rateUp, SIGNAL(clicked(bool)), this, SLOT(rateUp()));
    connect(ui->rateDown, SIGNAL(clicked(bool)), this, SLOT(rateDown()));
    connect(ui->next, SIGNAL(clicked(bool)), this, SLOT(next()));
}

void Bash::load()
{
    page->mainFrame()->load(QUrl("http://bash.im/"));
}

void Bash::setQuotes()
{
    quotes.clear();
    quotes = page->mainFrame()->findAllElements("div[class=quote]").toList();
    ui->next->setEnabled(true);
    next();
}

void Bash::next()
{
    if (!quotes.isEmpty())
    {
        QString quote = quotes.takeFirst().findFirst("div[class=text]").toPlainText();
        while (quote.isEmpty())
            quote = quotes.takeFirst().findFirst("div[class=text]").toPlainText();
        ui->rating->setText(quotes[0].findFirst("span[class=rating-o]").toPlainText());
        ui->quote->setPlainText(quote);
        ui->bayan->setEnabled(true);
        ui->rateUp->setEnabled(true);
        ui->rateDown->setEnabled(true);
    }
    else
        load();
}

void Bash::disableRate()
{
    ui->bayan->setEnabled(false);
    ui->rateDown->setEnabled(false);
    ui->rateUp->setEnabled(false);
}


void Bash::rateUp()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quotes.takeFirst().findFirst("a[class=up]").attribute("href"))));
    ui->rating->setText(QString::number(ui->rating->text().toInt() + 1));
    disableRate();
}


void Bash::rateDown()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quotes.takeFirst().findFirst("a[class=down]").attribute("href"))));
    ui->rating->setText(QString::number(ui->rating->text().toInt() - 1));
    disableRate();
}


void Bash::bayan()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quotes.takeFirst().findFirst("a[class=bayan]").attribute("href"))));
    disableRate();
}

Bash::~Bash()
{
    delete page;
    delete ui;
}
