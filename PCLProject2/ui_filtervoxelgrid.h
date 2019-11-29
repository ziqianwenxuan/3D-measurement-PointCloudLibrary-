/********************************************************************************
** Form generated from reading UI file 'filtervoxelgrid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERVOXELGRID_H
#define UI_FILTERVOXELGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filtervoxelgrid
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QDoubleSpinBox *leafSizeSBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *filtervoxelgrid)
    {
        if (filtervoxelgrid->objectName().isEmpty())
            filtervoxelgrid->setObjectName(QStringLiteral("filtervoxelgrid"));
        filtervoxelgrid->resize(240, 950);
        centralwidget = new QWidget(filtervoxelgrid);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 150, 201, 231));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 40, 111, 21));
        leafSizeSBox = new QDoubleSpinBox(groupBox_2);
        leafSizeSBox->setObjectName(QStringLiteral("leafSizeSBox"));
        leafSizeSBox->setGeometry(QRect(20, 90, 111, 21));
        leafSizeSBox->setValue(0.1);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 400, 201, 471));
        filtervoxelgrid->setCentralWidget(centralwidget);
        menubar = new QMenuBar(filtervoxelgrid);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        filtervoxelgrid->setMenuBar(menubar);
        statusbar = new QStatusBar(filtervoxelgrid);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        filtervoxelgrid->setStatusBar(statusbar);

        retranslateUi(filtervoxelgrid);

        QMetaObject::connectSlotsByName(filtervoxelgrid);
    } // setupUi

    void retranslateUi(QMainWindow *filtervoxelgrid)
    {
        filtervoxelgrid->setWindowTitle(QApplication::translate("filtervoxelgrid", "MainWindow", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("filtervoxelgrid", "\344\275\223\347\264\240\345\214\226\346\240\205\346\240\274\344\270\213\351\207\207\346\240\267", Q_NULLPTR));
        label_9->setText(QApplication::translate("filtervoxelgrid", "LeafSize", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("filtervoxelgrid", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class filtervoxelgrid: public Ui_filtervoxelgrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERVOXELGRID_H
