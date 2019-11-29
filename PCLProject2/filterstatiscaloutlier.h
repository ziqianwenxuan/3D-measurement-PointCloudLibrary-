#ifndef FILTERSTATISCALOUTLIER_H
#define FILTERSTATISCALOUTLIER_H

#include <QMainWindow>

namespace Ui {
class FilterStatiscalOutlier;
}

class FilterStatiscalOutlier : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterStatiscalOutlier(QWidget *parent = 0);
    ~FilterStatiscalOutlier();
Ui::FilterStatiscalOutlier *ui;
private:

};

#endif // FILTERSTATISCALOUTLIER_H
