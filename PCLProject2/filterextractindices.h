#ifndef FILTEREXTRACTINDICES_H
#define FILTEREXTRACTINDICES_H

#include <QMainWindow>

namespace Ui {
class FilterExtractIndices;
}

class FilterExtractIndices : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterExtractIndices(QWidget *parent = 0);
    ~FilterExtractIndices();
 Ui::FilterExtractIndices *ui;
private:

};

#endif // FILTEREXTRACTINDICES_H
