#include "mainwindow.h"
#include <QApplication>
#include<filter.h>
#include<pclsegmentation.h>
#include<registation.h>
#include<transform.h>
#include<feature.h>
#include<flow.h>

#include "vtkoutputwindow.h"


int main(int argc, char *argv[])
{

    vtkOutputWindow::SetGlobalWarningDisplay(0);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Filter f;
//    f.show();

//    PCLSegmentation s;
//    s.show();

//    Registation r;
//    r.show();

//    Transform t;
//    t.show();

//    Feature f;
//    f.show();

//    Flow fl;
//    fl.show();

    return a.exec();
}




