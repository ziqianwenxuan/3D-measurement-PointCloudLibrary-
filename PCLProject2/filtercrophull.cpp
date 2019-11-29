#include "filtercrophull.h"
#include "ui_filtercrophull.h"

FilterCropHull::FilterCropHull(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterCropHull)
{
    ui->setupUi(this);
}

FilterCropHull::~FilterCropHull()
{
    delete ui;
}
