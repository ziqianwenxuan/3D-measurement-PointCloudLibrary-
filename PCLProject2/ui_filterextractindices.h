/********************************************************************************
** Form generated from reading UI file 'filterextractindices.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTEREXTRACTINDICES_H
#define UI_FILTEREXTRACTINDICES_H

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

class Ui_FilterExtractIndices
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_3;
    QLabel *label_12;
    QDoubleSpinBox *DTBox;
    QLabel *label_13;
    QDoubleSpinBox *MIBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterExtractIndices)
    {
        if (FilterExtractIndices->objectName().isEmpty())
            FilterExtractIndices->setObjectName(QStringLiteral("FilterExtractIndices"));
        FilterExtractIndices->resize(240, 950);
        centralwidget = new QWidget(FilterExtractIndices);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 80, 201, 301));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 160, 111, 21));
        DTBox = new QDoubleSpinBox(groupBox_3);
        DTBox->setObjectName(QStringLiteral("DTBox"));
        DTBox->setGeometry(QRect(40, 200, 111, 21));
        DTBox->setMaximum(9999.99);
        DTBox->setSingleStep(0.01);
        DTBox->setValue(0.01);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 40, 131, 21));
        MIBox = new QDoubleSpinBox(groupBox_3);
        MIBox->setObjectName(QStringLiteral("MIBox"));
        MIBox->setGeometry(QRect(30, 70, 111, 21));
        MIBox->setMaximum(1e+6);
        MIBox->setValue(1000);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 400, 201, 471));
        FilterExtractIndices->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterExtractIndices);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterExtractIndices->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterExtractIndices);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterExtractIndices->setStatusBar(statusbar);

        retranslateUi(FilterExtractIndices);

        QMetaObject::connectSlotsByName(FilterExtractIndices);
    } // setupUi

    void retranslateUi(QMainWindow *FilterExtractIndices)
    {
        FilterExtractIndices->setWindowTitle(QApplication::translate("FilterExtractIndices", "MainWindow", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FilterExtractIndices", "\345\237\272\344\272\216\351\232\217\346\234\272\344\270\200\350\207\264\346\200\247\345\210\206\345\211\262\347\256\227\346\263\225", Q_NULLPTR));
        label_12->setText(QApplication::translate("FilterExtractIndices", "DistanceThreshold", Q_NULLPTR));
        label_13->setText(QApplication::translate("FilterExtractIndices", "MaxIterations", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterExtractIndices", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterExtractIndices: public Ui_FilterExtractIndices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTEREXTRACTINDICES_H
