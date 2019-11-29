/********************************************************************************
** Form generated from reading UI file 'filterpassthrough.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERPASSTHROUGH_H
#define UI_FILTERPASSTHROUGH_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterPassThrough
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QDoubleSpinBox *ULBox;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *LLBox;
    QRadioButton *radioButton;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterPassThrough)
    {
        if (FilterPassThrough->objectName().isEmpty())
            FilterPassThrough->setObjectName(QStringLiteral("FilterPassThrough"));
        FilterPassThrough->resize(240, 950);
        centralwidget = new QWidget(FilterPassThrough);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 60, 201, 301));
        ULBox = new QDoubleSpinBox(groupBox_4);
        ULBox->setObjectName(QStringLiteral("ULBox"));
        ULBox->setGeometry(QRect(30, 130, 111, 21));
        ULBox->setMaximum(9999.99);
        ULBox->setSingleStep(0.01);
        ULBox->setValue(8);
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 100, 131, 16));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 30, 121, 16));
        LLBox = new QDoubleSpinBox(groupBox_4);
        LLBox->setObjectName(QStringLiteral("LLBox"));
        LLBox->setGeometry(QRect(30, 60, 111, 21));
        LLBox->setMaximum(1e+6);
        LLBox->setSingleStep(0.1);
        LLBox->setValue(0);
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 180, 101, 19));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 400, 201, 471));
        FilterPassThrough->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterPassThrough);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterPassThrough->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterPassThrough);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterPassThrough->setStatusBar(statusbar);

        retranslateUi(FilterPassThrough);

        QMetaObject::connectSlotsByName(FilterPassThrough);
    } // setupUi

    void retranslateUi(QMainWindow *FilterPassThrough)
    {
        FilterPassThrough->setWindowTitle(QApplication::translate("FilterPassThrough", "MainWindow", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("FilterPassThrough", "\347\233\264\351\200\232\346\273\244\346\263\242", Q_NULLPTR));
        label_20->setText(QApplication::translate("FilterPassThrough", "Upper Limit", Q_NULLPTR));
        label_21->setText(QApplication::translate("FilterPassThrough", "Lower Limit", Q_NULLPTR));
        radioButton->setText(QApplication::translate("FilterPassThrough", "\350\277\207\346\273\244\350\214\203\345\233\264\345\206\205", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterPassThrough", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterPassThrough: public Ui_FilterPassThrough {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERPASSTHROUGH_H
