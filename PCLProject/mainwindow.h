#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<filter.h>
#include<pclsegmentation.h>
#include<registation.h>
#include<transform.h>
#include<feature.h>
#include<flow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_actionFilter_triggered();

    void on_actionSegmentation_triggered();

    void on_actionRegistation_triggered();

    void on_actionTransform_triggered();

    void on_actionFeature_triggered();
    void on_actionFlow_triggered();

private:
    Ui::MainWindow *ui;

//    Filter f;
//    PCLSegmentation s;
//    Registation r;
//    Transform t;
//    Feature fe;
    Filter *f;
    PCLSegmentation *s;
    Registation *r;
    Transform *t;
    Feature *fe;
    Flow   *fl;
};

#endif // MAINWINDOW_H
