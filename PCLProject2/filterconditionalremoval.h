#ifndef FILTERCONDITIONALREMOVAL_H
#define FILTERCONDITIONALREMOVAL_H

#include <QMainWindow>

namespace Ui {
class FilterConditionalRemoval;
}

class FilterConditionalRemoval : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterConditionalRemoval(QWidget *parent = 0);
    ~FilterConditionalRemoval();
Ui::FilterConditionalRemoval *ui;
private:

};

#endif // FILTERCONDITIONALREMOVAL_H
