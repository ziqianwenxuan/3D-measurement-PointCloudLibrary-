/********************************************************************************
** Form generated from reading UI file 'filterstatiscaloutlier.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSTATISCALOUTLIER_H
#define UI_FILTERSTATISCALOUTLIER_H

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

class Ui_FilterStatiscalOutlier
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_11;
    QDoubleSpinBox *SMTBox;
    QLabel *label_10;
    QDoubleSpinBox *MKBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterStatiscalOutlier)
    {
        if (FilterStatiscalOutlier->objectName().isEmpty())
            FilterStatiscalOutlier->setObjectName(QStringLiteral("FilterStatiscalOutlier"));
        FilterStatiscalOutlier->resize(240, 950);
        centralwidget = new QWidget(FilterStatiscalOutlier);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 90, 191, 261));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 110, 111, 21));
        SMTBox = new QDoubleSpinBox(groupBox);
        SMTBox->setObjectName(QStringLiteral("SMTBox"));
        SMTBox->setGeometry(QRect(30, 150, 111, 21));
        SMTBox->setMaximum(9999.99);
        SMTBox->setSingleStep(0.1);
        SMTBox->setValue(1);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 40, 111, 21));
        MKBox = new QDoubleSpinBox(groupBox);
        MKBox->setObjectName(QStringLiteral("MKBox"));
        MKBox->setGeometry(QRect(30, 70, 111, 21));
        MKBox->setMaximum(9999.99);
        MKBox->setValue(50);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 390, 201, 471));
        FilterStatiscalOutlier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterStatiscalOutlier);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterStatiscalOutlier->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterStatiscalOutlier);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterStatiscalOutlier->setStatusBar(statusbar);

        retranslateUi(FilterStatiscalOutlier);

        QMetaObject::connectSlotsByName(FilterStatiscalOutlier);
    } // setupUi

    void retranslateUi(QMainWindow *FilterStatiscalOutlier)
    {
        FilterStatiscalOutlier->setWindowTitle(QApplication::translate("FilterStatiscalOutlier", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FilterStatiscalOutlier", "\347\273\237\350\256\241\345\210\206\346\236\220", Q_NULLPTR));
        label_11->setText(QApplication::translate("FilterStatiscalOutlier", "StddevMulThresh", Q_NULLPTR));
        label_10->setText(QApplication::translate("FilterStatiscalOutlier", "MeanK", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterStatiscalOutlier", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterStatiscalOutlier: public Ui_FilterStatiscalOutlier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSTATISCALOUTLIER_H
