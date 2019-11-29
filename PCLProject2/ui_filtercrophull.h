/********************************************************************************
** Form generated from reading UI file 'filtercrophull.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCROPHULL_H
#define UI_FILTERCROPHULL_H

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

class Ui_FilterCropHull
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_8;
    QDoubleSpinBox *aBox;
    QLabel *label_18;
    QDoubleSpinBox *bBox;
    QLabel *label_19;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterCropHull)
    {
        if (FilterCropHull->objectName().isEmpty())
            FilterCropHull->setObjectName(QStringLiteral("FilterCropHull"));
        FilterCropHull->resize(240, 950);
        centralwidget = new QWidget(FilterCropHull);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 110, 201, 281));
        aBox = new QDoubleSpinBox(groupBox_8);
        aBox->setObjectName(QStringLiteral("aBox"));
        aBox->setGeometry(QRect(40, 70, 111, 21));
        aBox->setMaximum(1e+6);
        aBox->setSingleStep(0.1);
        aBox->setValue(2);
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 120, 131, 16));
        bBox = new QDoubleSpinBox(groupBox_8);
        bBox->setObjectName(QStringLiteral("bBox"));
        bBox->setGeometry(QRect(40, 170, 111, 21));
        bBox->setMaximum(9999.99);
        bBox->setSingleStep(1);
        bBox->setValue(2);
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 30, 121, 16));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 420, 201, 471));
        FilterCropHull->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterCropHull);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 26));
        FilterCropHull->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterCropHull);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterCropHull->setStatusBar(statusbar);

        retranslateUi(FilterCropHull);

        QMetaObject::connectSlotsByName(FilterCropHull);
    } // setupUi

    void retranslateUi(QMainWindow *FilterCropHull)
    {
        FilterCropHull->setWindowTitle(QApplication::translate("FilterCropHull", "MainWindow", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("FilterCropHull", "\345\244\232\350\276\271\345\275\242\345\206\205\351\203\250\347\202\271\344\272\221\346\217\220\345\217\226", Q_NULLPTR));
        label_18->setText(QApplication::translate("FilterCropHull", "\345\207\275\346\225\260\347\273\264\345\272\246", Q_NULLPTR));
        label_19->setText(QApplication::translate("FilterCropHull", "\345\207\270\345\214\205\347\273\264\345\272\246", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("FilterCropHull", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\231\351\207\214\351\235\242\347\274\226\350\276\221\357\274\214\346\257\217\346\254\241\351\207\215\345\220\257\345\260\261\344\270\215\344\274\232\346\270\205\351\233\266\344\272\206\343\200\202</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterCropHull: public Ui_FilterCropHull {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCROPHULL_H
