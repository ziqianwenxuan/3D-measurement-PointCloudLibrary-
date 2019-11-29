/********************************************************************************
** Form generated from reading UI file 'filterconditionalremoval.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCONDITIONALREMOVAL_H
#define UI_FILTERCONDITIONALREMOVAL_H

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

class Ui_FilterConditionalRemoval
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_5;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *LTBox;
    QDoubleSpinBox *GTBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterConditionalRemoval)
    {
        if (FilterConditionalRemoval->objectName().isEmpty())
            FilterConditionalRemoval->setObjectName(QStringLiteral("FilterConditionalRemoval"));
        FilterConditionalRemoval->resize(240, 950);
        centralwidget = new QWidget(FilterConditionalRemoval);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 90, 201, 301));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 30, 121, 16));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 140, 131, 16));
        LTBox = new QDoubleSpinBox(groupBox_5);
        LTBox->setObjectName(QStringLiteral("LTBox"));
        LTBox->setGeometry(QRect(40, 190, 111, 21));
        LTBox->setMaximum(9999.99);
        LTBox->setSingleStep(0.01);
        LTBox->setValue(0.8);
        GTBox = new QDoubleSpinBox(groupBox_5);
        GTBox->setObjectName(QStringLiteral("GTBox"));
        GTBox->setGeometry(QRect(40, 70, 111, 21));
        GTBox->setMaximum(1e+6);
        GTBox->setSingleStep(0.1);
        GTBox->setValue(0);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 410, 201, 471));
        FilterConditionalRemoval->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterConditionalRemoval);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterConditionalRemoval->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterConditionalRemoval);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterConditionalRemoval->setStatusBar(statusbar);

        retranslateUi(FilterConditionalRemoval);

        QMetaObject::connectSlotsByName(FilterConditionalRemoval);
    } // setupUi

    void retranslateUi(QMainWindow *FilterConditionalRemoval)
    {
        FilterConditionalRemoval->setWindowTitle(QApplication::translate("FilterConditionalRemoval", "MainWindow", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("FilterConditionalRemoval", "\350\207\252\345\256\232\344\271\211\346\235\241\344\273\266\346\273\244\351\231\244", Q_NULLPTR));
        label_14->setText(QApplication::translate("FilterConditionalRemoval", "Z\346\226\271\345\220\221 GT", Q_NULLPTR));
        label_15->setText(QApplication::translate("FilterConditionalRemoval", "Z\346\226\271\345\220\221 LT", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterConditionalRemoval", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterConditionalRemoval: public Ui_FilterConditionalRemoval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCONDITIONALREMOVAL_H
