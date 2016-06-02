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
        quote = quotes.takeFirst();
        while (quote.findFirst("div[class=text]").toPlainText().isEmpty())
            quote = quotes.takeFirst();
        ui->rating->setText(quote.findFirst("span[class=rating-o]").toPlainText());
        ui->quote->setPlainText(quote.findFirst("div[class=text]").toPlainText());
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
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quote.findFirst("a[class=up]").attribute("href"))));
    ui->rating->setText(QString::number(ui->rating->text().toInt() + 1));
    disableRate();
}


void Bash::rateDown()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quote.findFirst("a[class=down]").attribute("href"))));
    ui->rating->setText(QString::number(ui->rating->text().toInt() - 1));
    disableRate();
}


void Bash::bayan()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + quote.findFirst("a[class=bayan]").attribute("href"))));
    disableRate();
}

Bash::~Bash()
{
    delete page;
    delete ui;
}
