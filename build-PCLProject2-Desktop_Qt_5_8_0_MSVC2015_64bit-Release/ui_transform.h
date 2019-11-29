/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QVTKWidget *widget_1;
    QGroupBox *groupBox_9;
    QLabel *label_31;
    QDoubleSpinBox *NOTBox_6;
    QDoubleSpinBox *MNBBox_6;
    QLabel *label_32;
    QDoubleSpinBox *NOTBox_7;
    QLabel *label_33;
    QPushButton *executeButton;
    QPushButton *loadSceneBut;
    QPushButton *pushButton;
    QWidget *tab_2;
    QVTKWidget *widget_2;
    QLabel *label_3;
    QPushButton *loadSceneBut_2;
    QPushButton *executeButton_2;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QVTKWidget *widget_3;
    QLabel *label_17;
    QPushButton *executeButton_3;
    QPushButton *loadSceneBut_3;
    QPushButton *pushButton_3;
    QWidget *tab_5;
    QLabel *label_37;
    QVTKWidget *widget_4;
    QPushButton *executeButton_4;
    QPushButton *loadSceneBut_4;
    QPushButton *pushButton_4;
    QWidget *tab_4;
    QVTKWidget *widget_5;
    QLabel *label_23;
    QPushButton *loadSceneBut_5;
    QPushButton *executeButton_5;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QStringLiteral("Transform"));
        Transform->resize(1101, 1129);
        centralwidget = new QWidget(Transform);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 40, 901, 1001));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 20, 141, 31));
        widget_1 = new QVTKWidget(tab);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setGeometry(QRect(20, 70, 761, 531));
        widget_1->setAutoFillBackground(true);
        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(150, 630, 491, 301));
        label_31 = new QLabel(groupBox_9);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(20, 35, 151, 20));
        NOTBox_6 = new QDoubleSpinBox(groupBox_9);
        NOTBox_6->setObjectName(QStringLiteral("NOTBox_6"));
        NOTBox_6->setGeometry(QRect(390, 70, 70, 22));
        NOTBox_6->setSingleStep(0.01);
        NOTBox_6->setValue(0);
        MNBBox_6 = new QDoubleSpinBox(groupBox_9);
        MNBBox_6->setObjectName(QStringLiteral("MNBBox_6"));
        MNBBox_6->setGeometry(QRect(390, 40, 70, 22));
        MNBBox_6->setSingleStep(0.01);
        MNBBox_6->setValue(0);
        label_32 = new QLabel(groupBox_9);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(20, 70, 211, 16));
        NOTBox_7 = new QDoubleSpinBox(groupBox_9);
        NOTBox_7->setObjectName(QStringLiteral("NOTBox_7"));
        NOTBox_7->setGeometry(QRect(390, 100, 70, 22));
        NOTBox_7->setSingleStep(0.01);
        NOTBox_7->setValue(1);
        label_33 = new QLabel(groupBox_9);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(20, 100, 211, 16));
        executeButton = new QPushButton(groupBox_9);
        executeButton->setObjectName(QStringLiteral("executeButton"));
        executeButton->setGeometry(QRect(270, 180, 101, 31));
        loadSceneBut = new QPushButton(groupBox_9);
        loadSceneBut->setObjectName(QStringLiteral("loadSceneBut"));
        loadSceneBut->setGeometry(QRect(30, 150, 111, 28));
        pushButton = new QPushButton(groupBox_9);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 230, 111, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget_2 = new QVTKWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 50, 761, 631));
        widget_2->setAutoFillBackground(true);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 0, 141, 31));
        loadSceneBut_2 = new QPushButton(tab_2);
        loadSceneBut_2->setObjectName(QStringLiteral("loadSceneBut_2"));
        loadSceneBut_2->setGeometry(QRect(170, 750, 111, 28));
        executeButton_2 = new QPushButton(tab_2);
        executeButton_2->setObjectName(QStringLiteral("executeButton_2"));
        executeButton_2->setGeometry(QRect(390, 760, 93, 28));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 760, 93, 28));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        widget_3 = new QVTKWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(20, 60, 811, 601));
        widget_3->setAutoFillBackground(true);
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(250, 10, 141, 31));
        executeButton_3 = new QPushButton(tab_3);
        executeButton_3->setObjectName(QStringLiteral("executeButton_3"));
        executeButton_3->setGeometry(QRect(270, 730, 93, 28));
        loadSceneBut_3 = new QPushButton(tab_3);
        loadSceneBut_3->setObjectName(QStringLiteral("loadSceneBut_3"));
        loadSceneBut_3->setGeometry(QRect(90, 730, 111, 28));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 730, 93, 28));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_37 = new QLabel(tab_5);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(270, 20, 141, 31));
        widget_4 = new QVTKWidget(tab_5);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(40, 70, 811, 601));
        widget_4->setAutoFillBackground(true);
        executeButton_4 = new QPushButton(tab_5);
        executeButton_4->setObjectName(QStringLiteral("executeButton_4"));
        executeButton_4->setGeometry(QRect(370, 720, 93, 28));
        loadSceneBut_4 = new QPushButton(tab_5);
        loadSceneBut_4->setObjectName(QStringLiteral("loadSceneBut_4"));
        loadSceneBut_4->setGeometry(QRect(170, 720, 111, 28));
        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 720, 93, 28));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        widget_5 = new QVTKWidget(tab_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 50, 761, 631));
        widget_5->setAutoFillBackground(true);
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(240, 10, 141, 31));
        loadSceneBut_5 = new QPushButton(tab_4);
        loadSceneBut_5->setObjectName(QStringLiteral("loadSceneBut_5"));
        loadSceneBut_5->setGeometry(QRect(80, 740, 111, 28));
        executeButton_5 = new QPushButton(tab_4);
        executeButton_5->setObjectName(QStringLiteral("executeButton_5"));
        executeButton_5->setGeometry(QRect(270, 740, 93, 28));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 740, 93, 28));
        tabWidget->addTab(tab_4, QString());
        Transform->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Transform);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1101, 26));
        Transform->setMenuBar(menubar);
        statusbar = new QStatusBar(Transform);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Transform->setStatusBar(statusbar);

        retranslateUi(Transform);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QMainWindow *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "PCL\345\217\257\350\247\206\345\214\226\346\223\215\344\275\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("Transform", "\347\224\261\347\202\271\344\272\221\345\210\233\345\273\272\346\267\261\345\272\246\345\233\276", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Transform", "\346\267\261\345\272\246\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        label_31->setText(QApplication::translate("Transform", "Noise_Level", Q_NULLPTR));
        label_32->setText(QApplication::translate("Transform", "Min_Range", Q_NULLPTR));
        label_33->setText(QApplication::translate("Transform", "Border_Size", Q_NULLPTR));
        executeButton->setText(QApplication::translate("Transform", "\346\267\261\345\272\246\345\233\276\350\275\254\346\215\242", Q_NULLPTR));
        loadSceneBut->setText(QApplication::translate("Transform", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Transform", "\344\277\235\345\255\230\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Transform", " \346\267\261\345\272\246\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("Transform", "Z\345\255\227\346\256\265\346\270\262\346\237\223\345\233\276", Q_NULLPTR));
        loadSceneBut_2->setText(QApplication::translate("Transform", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        executeButton_2->setText(QApplication::translate("Transform", "\346\211\247\350\241\214\350\275\254\346\215\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Transform", "\344\277\235\345\255\230\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Transform", "\345\275\251\350\211\262\345\233\276", Q_NULLPTR));
        label_17->setText(QApplication::translate("Transform", "\351\253\230\345\272\246\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        executeButton_3->setText(QApplication::translate("Transform", "\346\211\247\350\241\214\350\275\254\346\215\242", Q_NULLPTR));
        loadSceneBut_3->setText(QApplication::translate("Transform", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Transform", "\344\277\235\345\255\230\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Transform", "\351\253\230\345\272\246\345\233\276", Q_NULLPTR));
        label_37->setText(QApplication::translate("Transform", "\347\201\260\345\272\246\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        executeButton_4->setText(QApplication::translate("Transform", "\346\211\247\350\241\214\350\275\254\346\215\242", Q_NULLPTR));
        loadSceneBut_4->setText(QApplication::translate("Transform", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Transform", "\344\277\235\345\255\230\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Transform", "\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        label_23->setText(QApplication::translate("Transform", "\344\272\256\345\272\246\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        loadSceneBut_5->setText(QApplication::translate("Transform", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        executeButton_5->setText(QApplication::translate("Transform", "\346\211\247\350\241\214\350\275\254\346\215\242", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Transform", "\344\277\235\345\255\230\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Transform", "\344\272\256\345\272\246\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
