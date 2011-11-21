#include "ged.h"
#include "ui_ged.h"

ged::ged(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ged)
{
    ui->setupUi(this);
}

ged::~ged()
{
    delete ui;
}
