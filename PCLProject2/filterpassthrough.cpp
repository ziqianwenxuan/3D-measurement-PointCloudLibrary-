#include "filterpassthrough.h"
#include "ui_filterpassthrough.h"


FilterPassThrough::FilterPassThrough(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterPassThrough)
{
    ui->setupUi(this);
}

FilterPassThrough::~FilterPassThrough()
{
    delete ui;
}




