#ifndef FILTERPASSTHROUGH_H
#define FILTERPASSTHROUGH_H

#include <QMainWindow>
#include "global.h"

namespace Ui {
class FilterPassThrough;
}

class FilterPassThrough : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterPassThrough(QWidget *parent = 0);
    ~FilterPassThrough();

 Ui::FilterPassThrough *ui;

private:

};

#endif // FILTERPASSTHROUGH_H
