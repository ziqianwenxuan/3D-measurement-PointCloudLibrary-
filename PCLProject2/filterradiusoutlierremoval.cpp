#include "filterradiusoutlierremoval.h"
#include "ui_filterradiusoutlierremoval.h"

FilterRadiusOutlierRemoval::FilterRadiusOutlierRemoval(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterRadiusOutlierRemoval)
{
    ui->setupUi(this);
}

FilterRadiusOutlierRemoval::~FilterRadiusOutlierRemoval()
{
    delete ui;
}
