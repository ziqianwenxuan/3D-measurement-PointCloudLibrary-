#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<filter.h>
#include<pclsegmentation.h>
#include<registation.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f = new Filter(this);
    s = new PCLSegmentation(this);
    r = new Registation(this);
    t = new Transform(this);
    fe = new Feature(this);
    fl = new Flow (this);

    ui->stackedWidget->addWidget(f);
    ui->stackedWidget->addWidget(s);
    ui->stackedWidget->addWidget(r);
    ui->stackedWidget->addWidget(t);
    ui->stackedWidget->addWidget(fe);
    ui->stackedWidget->addWidget(fl);

}

MainWindow::~MainWindow()
{
    delete ui;
}
// 以下是直接弹出窗口
//……………………………………………………………………………………………………………………………………………………………………
void MainWindow::on_actionFilter_triggered()
{
//        Filter f;
//        this->f.show();
   ui->stackedWidget->setCurrentWidget(f);
}

void MainWindow::on_actionSegmentation_triggered()
{
//      PCLSegmentation s;
//      this->s.show();
    ui->stackedWidget->setCurrentWidget(s);
}
void MainWindow:: on_actionRegistation_triggered()
{
//      Registation r;
//      this->r.show();
    ui->stackedWidget->setCurrentWidget(r);
}

void MainWindow:: on_actionTransform_triggered()
      {
//            Transform t;
//            this->t.show();
    ui->stackedWidget->setCurrentWidget(t);
      }

 void MainWindow:: on_actionFeature_triggered()
       {
//              Feature fe;
//             this->fe.show();
     ui->stackedWidget->setCurrentWidget(fe);
       }


 void MainWindow:: on_actionFlow_triggered()
       {

     ui->stackedWidget->setCurrentWidget(fl);
       }
//……………………………………………………………………………………………………………………………………………………………………











