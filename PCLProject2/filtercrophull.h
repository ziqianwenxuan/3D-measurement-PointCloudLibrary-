#ifndef FILTERCROPHULL_H
#define FILTERCROPHULL_H

#include <QMainWindow>

namespace Ui {
class FilterCropHull;
}

class FilterCropHull : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterCropHull(QWidget *parent = 0);
    ~FilterCropHull();
   Ui::FilterCropHull *ui;
private:

};

#endif // FILTERCROPHULL_H
