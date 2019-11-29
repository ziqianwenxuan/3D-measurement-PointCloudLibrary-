#include "filterconditionalremoval.h"
#include "ui_filterconditionalremoval.h"

FilterConditionalRemoval::FilterConditionalRemoval(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterConditionalRemoval)
{
    ui->setupUi(this);
}

FilterConditionalRemoval::~FilterConditionalRemoval()
{
    delete ui;
}
