#include "filterstatiscaloutlier.h"
#include "ui_filterstatiscaloutlier.h"

FilterStatiscalOutlier::FilterStatiscalOutlier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterStatiscalOutlier)
{
    ui->setupUi(this);
}

FilterStatiscalOutlier::~FilterStatiscalOutlier()
{
    delete ui;
}
