
#include "ged.h"
#include "ui_ged.h"


ged::ged(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ged)
{
    ui->setupUi(this);
    eventcounter = 0;
    currentrow = 0;
}

ged::~ged()
{
    delete ui;
}


void ged::checkchange()
{
    eventcounter++;
    ui->statusBar->showMessage(QString::number(eventcounter, 10), 500);

    currentrow = ui->listWidget->currentRow();

    char filename[300];

    sprintf(filename, "%s/file", ui->listWidget->item(currentrow)->text().toAscii().data());

    QFile file(filename);

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        stream.flush();
        file.close();
    }
    else
        printf("error\n");


    char command2[256];

    sprintf(command2, "cd %s && git commit -a -m \"message %i\"", ui->listWidget->item(currentrow)->text().toAscii().data(), eventcounter);

    system (command2);
}


void ged::createnew()
{
    srand(time(0));

    int dirprefix = rand()*100;

    char dirname[200];

    sprintf(dirname, "%s/test%i",QDir::currentPath().toAscii().data(), dirprefix);

    char command1[400];

    sprintf(command1, "mkdir %s && cd %s && touch file && git init && git add .", dirname, dirname);

    system(command1);

    ui->listWidget->addItem(QString(dirname));

    currentrow = ui->listWidget->currentRow();
}

void ged::deletecurrent()
{
;
}

void ged::checkout()
{
    currentrow = ui->listWidget->currentRow();

     ui->statusBar->showMessage(QString::number(currentrow, 10), 500);
}
