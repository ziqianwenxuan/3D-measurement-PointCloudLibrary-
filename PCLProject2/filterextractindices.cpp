#include "filterextractindices.h"
#include "ui_filterextractindices.h"

FilterExtractIndices::FilterExtractIndices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterExtractIndices)
{
    ui->setupUi(this);
}

FilterExtractIndices::~FilterExtractIndices()
{
    delete ui;
}
