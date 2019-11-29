#ifndef FILTERVOXELGRID_H
#define FILTERVOXELGRID_H

#include <QMainWindow>

namespace Ui {
class filtervoxelgrid;
}

class filtervoxelgrid : public QMainWindow
{
    Q_OBJECT

public:
    explicit filtervoxelgrid(QWidget *parent = 0);
    ~filtervoxelgrid();
Ui::filtervoxelgrid *ui;

private:

};

#endif // FILTERVOXELGRID_H
