#include "mainwindow.h"
#include <QApplication>
#include "vtkoutputwindow.h"


int main(int argc, char *argv[])
{
    vtkOutputWindow::SetGlobalWarningDisplay(0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    FilterPassThrough pt;
//    pt.show();

    return a.exec();
}
