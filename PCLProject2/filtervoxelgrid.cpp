#include "filtervoxelgrid.h"
#include "ui_filtervoxelgrid.h"

filtervoxelgrid::filtervoxelgrid(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::filtervoxelgrid)
{
    ui->setupUi(this);
}

filtervoxelgrid::~filtervoxelgrid()
{
    delete ui;
}
