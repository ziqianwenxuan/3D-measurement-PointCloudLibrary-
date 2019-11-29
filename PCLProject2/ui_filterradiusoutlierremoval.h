/********************************************************************************
** Form generated from reading UI file 'filterradiusoutlierremoval.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERRADIUSOUTLIERREMOVAL_H
#define UI_FILTERRADIUSOUTLIERREMOVAL_H

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

class Ui_FilterRadiusOutlierRemoval
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_6;
    QDoubleSpinBox *LJBox;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *BJBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterRadiusOutlierRemoval)
    {
        if (FilterRadiusOutlierRemoval->objectName().isEmpty())
            FilterRadiusOutlierRemoval->setObjectName(QStringLiteral("FilterRadiusOutlierRemoval"));
        FilterRadiusOutlierRemoval->resize(240, 950);
        centralwidget = new QWidget(FilterRadiusOutlierRemoval);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 70, 201, 301));
        LJBox = new QDoubleSpinBox(groupBox_6);
        LJBox->setObjectName(QStringLiteral("LJBox"));
        LJBox->setGeometry(QRect(30, 180, 111, 21));
        LJBox->setMaximum(9999.99);
        LJBox->setSingleStep(1);
        LJBox->setValue(100);
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 120, 131, 16));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 30, 121, 16));
        BJBox = new QDoubleSpinBox(groupBox_6);
        BJBox->setObjectName(QStringLiteral("BJBox"));
        BJBox->setGeometry(QRect(30, 70, 111, 21));
        BJBox->setMaximum(1e+6);
        BJBox->setSingleStep(0.1);
        BJBox->setValue(0.9);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 400, 201, 471));
        FilterRadiusOutlierRemoval->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterRadiusOutlierRemoval);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterRadiusOutlierRemoval->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterRadiusOutlierRemoval);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterRadiusOutlierRemoval->setStatusBar(statusbar);

        retranslateUi(FilterRadiusOutlierRemoval);

        QMetaObject::connectSlotsByName(FilterRadiusOutlierRemoval);
    } // setupUi

    void retranslateUi(QMainWindow *FilterRadiusOutlierRemoval)
    {
        FilterRadiusOutlierRemoval->setWindowTitle(QApplication::translate("FilterRadiusOutlierRemoval", "MainWindow", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("FilterRadiusOutlierRemoval", "\345\257\206\345\272\246\346\273\244\351\231\244", Q_NULLPTR));
        label_16->setText(QApplication::translate("FilterRadiusOutlierRemoval", "\351\202\273\350\277\221\347\202\271\351\233\206\346\225\260", Q_NULLPTR));
        label_17->setText(QApplication::translate("FilterRadiusOutlierRemoval", "\345\215\212\345\276\204\350\214\203\345\233\264", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterRadiusOutlierRemoval", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterRadiusOutlierRemoval: public Ui_FilterRadiusOutlierRemoval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERRADIUSOUTLIERREMOVAL_H
