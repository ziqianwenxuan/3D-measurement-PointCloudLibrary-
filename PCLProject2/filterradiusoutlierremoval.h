#ifndef FILTERRADIUSOUTLIERREMOVAL_H
#define FILTERRADIUSOUTLIERREMOVAL_H

#include <QMainWindow>

namespace Ui {
class FilterRadiusOutlierRemoval;
}

class FilterRadiusOutlierRemoval : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterRadiusOutlierRemoval(QWidget *parent = 0);
    ~FilterRadiusOutlierRemoval();
   Ui::FilterRadiusOutlierRemoval *ui;
private:

};

#endif // FILTERRADIUSOUTLIERREMOVAL_H
