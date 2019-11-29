/********************************************************************************
** Form generated from reading UI file 'feature.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATURE_H
#define UI_FEATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Feature
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QVTKWidget *widget_1;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *MSBox;
    QDoubleSpinBox *SRBox;
    QDoubleSpinBox *TBox;
    QPushButton *executeButton;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *MNBBox;
    QDoubleSpinBox *NOTBox;
    QDoubleSpinBox *NMRBox;
    QLabel *label_11;
    QGroupBox *groupBox;
    QPushButton *loadSceneBut;
    QWidget *tab_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QPushButton *loadSceneBut_2;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *MSBox_2;
    QDoubleSpinBox *SRBox_2;
    QDoubleSpinBox *TBox_2;
    QPushButton *executeButton_2;
    QDoubleSpinBox *NMRBox_2;
    QLabel *label_17;
    QVTKWidget *widget_2;
    QWidget *tab_3;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QPushButton *loadSceneBut_3;
    QGroupBox *groupBox_6;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QDoubleSpinBox *MSBox_3;
    QDoubleSpinBox *SRBox_3;
    QDoubleSpinBox *TBox_3;
    QPushButton *executeButton_3;
    QLabel *label_21;
    QLabel *label_22;
    QDoubleSpinBox *MNBBox_3;
    QDoubleSpinBox *NOTBox_3;
    QDoubleSpinBox *NMRBox_3;
    QLabel *label_23;
    QVTKWidget *widget_3;
    QWidget *tab_4;
    QLabel *label_5;
    QGroupBox *groupBox_7;
    QPushButton *loadSceneBut_4;
    QGroupBox *groupBox_8;
    QPushButton *executeButton_4;
    QLabel *label_27;
    QLabel *label_28;
    QDoubleSpinBox *MNBBox_4;
    QDoubleSpinBox *NOTBox_4;
    QVTKWidget *widget_4;
    QWidget *tab_5;
    QLabel *label_15;
    QGroupBox *groupBox_9;
    QPushButton *executeButton_5;
    QLabel *label_29;
    QLabel *label_30;
    QDoubleSpinBox *MNBBox_5;
    QDoubleSpinBox *NOTBox_5;
    QLabel *label_31;
    QDoubleSpinBox *NOTBox_6;
    QDoubleSpinBox *MNBBox_6;
    QLabel *label_32;
    QDoubleSpinBox *NOTBox_7;
    QLabel *label_33;
    QGroupBox *groupBox_10;
    QPushButton *loadSceneBut_5;
    QVTKWidget *widget_5;

    void setupUi(QMainWindow *Feature)
    {
        if (Feature->objectName().isEmpty())
            Feature->setObjectName(QStringLiteral("Feature"));
        Feature->resize(1413, 1152);
        centralwidget = new QWidget(Feature);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(80, 20, 891, 1101));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 30, 141, 31));
        widget_1 = new QVTKWidget(tab);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setGeometry(QRect(20, 70, 761, 631));
        widget_1->setAutoFillBackground(true);
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(400, 720, 351, 321));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 35, 151, 20));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 70, 211, 16));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 140, 151, 21));
        MSBox = new QDoubleSpinBox(groupBox_3);
        MSBox->setObjectName(QStringLiteral("MSBox"));
        MSBox->setGeometry(QRect(270, 30, 70, 22));
        MSBox->setSingleStep(0.01);
        MSBox->setValue(0.4);
        SRBox = new QDoubleSpinBox(groupBox_3);
        SRBox->setObjectName(QStringLiteral("SRBox"));
        SRBox->setGeometry(QRect(270, 60, 70, 22));
        SRBox->setSingleStep(0.01);
        SRBox->setValue(2.4);
        TBox = new QDoubleSpinBox(groupBox_3);
        TBox->setObjectName(QStringLiteral("TBox"));
        TBox->setGeometry(QRect(270, 140, 70, 22));
        TBox->setMaximum(100000);
        TBox->setSingleStep(0.1);
        TBox->setValue(0.97);
        executeButton = new QPushButton(groupBox_3);
        executeButton->setObjectName(QStringLiteral("executeButton"));
        executeButton->setGeometry(QRect(100, 250, 93, 28));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 210, 211, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 175, 151, 20));
        MNBBox = new QDoubleSpinBox(groupBox_3);
        MNBBox->setObjectName(QStringLiteral("MNBBox"));
        MNBBox->setGeometry(QRect(270, 170, 70, 22));
        MNBBox->setSingleStep(0.01);
        MNBBox->setValue(5);
        NOTBox = new QDoubleSpinBox(groupBox_3);
        NOTBox->setObjectName(QStringLiteral("NOTBox"));
        NOTBox->setGeometry(QRect(270, 200, 70, 22));
        NOTBox->setSingleStep(0.01);
        NOTBox->setValue(4);
        NMRBox = new QDoubleSpinBox(groupBox_3);
        NMRBox->setObjectName(QStringLiteral("NMRBox"));
        NMRBox->setGeometry(QRect(270, 100, 70, 22));
        NMRBox->setMaximum(100000);
        NMRBox->setValue(1.6);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 100, 151, 21));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 720, 351, 71));
        loadSceneBut = new QPushButton(groupBox);
        loadSceneBut->setObjectName(QStringLiteral("loadSceneBut"));
        loadSceneBut->setGeometry(QRect(80, 30, 111, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 20, 141, 31));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 710, 351, 71));
        loadSceneBut_2 = new QPushButton(groupBox_2);
        loadSceneBut_2->setObjectName(QStringLiteral("loadSceneBut_2"));
        loadSceneBut_2->setGeometry(QRect(80, 30, 111, 28));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(430, 710, 351, 271));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 35, 151, 20));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 70, 211, 16));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 140, 151, 21));
        MSBox_2 = new QDoubleSpinBox(groupBox_4);
        MSBox_2->setObjectName(QStringLiteral("MSBox_2"));
        MSBox_2->setGeometry(QRect(270, 30, 70, 22));
        MSBox_2->setSingleStep(0.01);
        MSBox_2->setValue(0.01);
        SRBox_2 = new QDoubleSpinBox(groupBox_4);
        SRBox_2->setObjectName(QStringLiteral("SRBox_2"));
        SRBox_2->setGeometry(QRect(270, 60, 70, 22));
        SRBox_2->setSingleStep(0.1);
        SRBox_2->setValue(6);
        TBox_2 = new QDoubleSpinBox(groupBox_4);
        TBox_2->setObjectName(QStringLiteral("TBox_2"));
        TBox_2->setGeometry(QRect(270, 140, 70, 22));
        TBox_2->setMaximum(100000);
        TBox_2->setSingleStep(0.01);
        TBox_2->setValue(0.01);
        executeButton_2 = new QPushButton(groupBox_4);
        executeButton_2->setObjectName(QStringLiteral("executeButton_2"));
        executeButton_2->setGeometry(QRect(110, 190, 93, 28));
        NMRBox_2 = new QDoubleSpinBox(groupBox_4);
        NMRBox_2->setObjectName(QStringLiteral("NMRBox_2"));
        NMRBox_2->setGeometry(QRect(270, 100, 70, 22));
        NMRBox_2->setMaximum(100000);
        NMRBox_2->setValue(4);
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(40, 100, 151, 21));
        widget_2 = new QVTKWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(50, 60, 761, 631));
        widget_2->setAutoFillBackground(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 20, 141, 31));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(40, 710, 351, 71));
        loadSceneBut_3 = new QPushButton(groupBox_5);
        loadSceneBut_3->setObjectName(QStringLiteral("loadSceneBut_3"));
        loadSceneBut_3->setGeometry(QRect(80, 30, 111, 28));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(420, 710, 351, 321));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 35, 151, 20));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 70, 211, 16));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 140, 151, 21));
        MSBox_3 = new QDoubleSpinBox(groupBox_6);
        MSBox_3->setObjectName(QStringLiteral("MSBox_3"));
        MSBox_3->setGeometry(QRect(270, 30, 70, 22));
        MSBox_3->setSingleStep(0.01);
        MSBox_3->setValue(0.4);
        SRBox_3 = new QDoubleSpinBox(groupBox_6);
        SRBox_3->setObjectName(QStringLiteral("SRBox_3"));
        SRBox_3->setGeometry(QRect(270, 60, 70, 22));
        SRBox_3->setSingleStep(0.01);
        SRBox_3->setValue(2.4);
        TBox_3 = new QDoubleSpinBox(groupBox_6);
        TBox_3->setObjectName(QStringLiteral("TBox_3"));
        TBox_3->setGeometry(QRect(270, 140, 70, 22));
        TBox_3->setMaximum(100000);
        TBox_3->setSingleStep(0.1);
        TBox_3->setValue(0.97);
        executeButton_3 = new QPushButton(groupBox_6);
        executeButton_3->setObjectName(QStringLiteral("executeButton_3"));
        executeButton_3->setGeometry(QRect(100, 250, 93, 28));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 210, 211, 16));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(40, 175, 151, 20));
        MNBBox_3 = new QDoubleSpinBox(groupBox_6);
        MNBBox_3->setObjectName(QStringLiteral("MNBBox_3"));
        MNBBox_3->setGeometry(QRect(270, 170, 70, 22));
        MNBBox_3->setSingleStep(0.01);
        MNBBox_3->setValue(5);
        NOTBox_3 = new QDoubleSpinBox(groupBox_6);
        NOTBox_3->setObjectName(QStringLiteral("NOTBox_3"));
        NOTBox_3->setGeometry(QRect(270, 200, 70, 22));
        NOTBox_3->setSingleStep(0.01);
        NOTBox_3->setValue(4);
        NMRBox_3 = new QDoubleSpinBox(groupBox_6);
        NMRBox_3->setObjectName(QStringLiteral("NMRBox_3"));
        NMRBox_3->setGeometry(QRect(270, 100, 70, 22));
        NMRBox_3->setMaximum(100000);
        NMRBox_3->setValue(1.6);
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(40, 100, 151, 21));
        widget_3 = new QVTKWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(40, 60, 761, 631));
        widget_3->setAutoFillBackground(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 20, 141, 31));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(40, 710, 351, 71));
        loadSceneBut_4 = new QPushButton(groupBox_7);
        loadSceneBut_4->setObjectName(QStringLiteral("loadSceneBut_4"));
        loadSceneBut_4->setGeometry(QRect(80, 30, 111, 28));
        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(420, 710, 351, 161));
        executeButton_4 = new QPushButton(groupBox_8);
        executeButton_4->setObjectName(QStringLiteral("executeButton_4"));
        executeButton_4->setGeometry(QRect(90, 110, 93, 28));
        label_27 = new QLabel(groupBox_8);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 70, 211, 16));
        label_28 = new QLabel(groupBox_8);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(30, 35, 151, 20));
        MNBBox_4 = new QDoubleSpinBox(groupBox_8);
        MNBBox_4->setObjectName(QStringLiteral("MNBBox_4"));
        MNBBox_4->setGeometry(QRect(260, 30, 70, 22));
        MNBBox_4->setSingleStep(0.01);
        MNBBox_4->setValue(0.1);
        NOTBox_4 = new QDoubleSpinBox(groupBox_8);
        NOTBox_4->setObjectName(QStringLiteral("NOTBox_4"));
        NOTBox_4->setGeometry(QRect(260, 60, 70, 22));
        NOTBox_4->setSingleStep(0.01);
        NOTBox_4->setValue(0.1);
        widget_4 = new QVTKWidget(tab_4);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(40, 60, 761, 631));
        widget_4->setAutoFillBackground(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(270, 40, 141, 31));
        groupBox_9 = new QGroupBox(tab_5);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(280, 730, 491, 301));
        executeButton_5 = new QPushButton(groupBox_9);
        executeButton_5->setObjectName(QStringLiteral("executeButton_5"));
        executeButton_5->setGeometry(QRect(100, 210, 93, 28));
        label_29 = new QLabel(groupBox_9);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(30, 70, 211, 16));
        label_30 = new QLabel(groupBox_9);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 35, 351, 20));
        MNBBox_5 = new QDoubleSpinBox(groupBox_9);
        MNBBox_5->setObjectName(QStringLiteral("MNBBox_5"));
        MNBBox_5->setGeometry(QRect(400, 40, 70, 22));
        MNBBox_5->setSingleStep(0.01);
        MNBBox_5->setValue(0.5);
        NOTBox_5 = new QDoubleSpinBox(groupBox_9);
        NOTBox_5->setObjectName(QStringLiteral("NOTBox_5"));
        NOTBox_5->setGeometry(QRect(400, 70, 70, 22));
        NOTBox_5->setSingleStep(0.01);
        NOTBox_5->setValue(0.2);
        label_31 = new QLabel(groupBox_9);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(30, 95, 151, 20));
        NOTBox_6 = new QDoubleSpinBox(groupBox_9);
        NOTBox_6->setObjectName(QStringLiteral("NOTBox_6"));
        NOTBox_6->setGeometry(QRect(400, 130, 70, 22));
        NOTBox_6->setSingleStep(0.01);
        NOTBox_6->setValue(0);
        MNBBox_6 = new QDoubleSpinBox(groupBox_9);
        MNBBox_6->setObjectName(QStringLiteral("MNBBox_6"));
        MNBBox_6->setGeometry(QRect(400, 100, 70, 22));
        MNBBox_6->setSingleStep(0.01);
        MNBBox_6->setValue(0);
        label_32 = new QLabel(groupBox_9);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(30, 130, 211, 16));
        NOTBox_7 = new QDoubleSpinBox(groupBox_9);
        NOTBox_7->setObjectName(QStringLiteral("NOTBox_7"));
        NOTBox_7->setGeometry(QRect(400, 160, 70, 22));
        NOTBox_7->setSingleStep(0.01);
        NOTBox_7->setValue(1);
        label_33 = new QLabel(groupBox_9);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(30, 160, 211, 16));
        groupBox_10 = new QGroupBox(tab_5);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(40, 730, 191, 71));
        loadSceneBut_5 = new QPushButton(groupBox_10);
        loadSceneBut_5->setObjectName(QStringLiteral("loadSceneBut_5"));
        loadSceneBut_5->setGeometry(QRect(30, 30, 111, 28));
        widget_5 = new QVTKWidget(tab_5);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(40, 80, 761, 631));
        widget_5->setAutoFillBackground(true);
        tabWidget->addTab(tab_5, QString());
        Feature->setCentralWidget(centralwidget);

        retranslateUi(Feature);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Feature);
    } // setupUi

    void retranslateUi(QMainWindow *Feature)
    {
        Feature->setWindowTitle(QApplication::translate("Feature", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("Feature", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Feature", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        label_6->setText(QApplication::translate("Feature", "Model_solution", Q_NULLPTR));
        label_7->setText(QApplication::translate("Feature", "SalientRadius", Q_NULLPTR));
        label_8->setText(QApplication::translate("Feature", "Threshold", Q_NULLPTR));
        executeButton->setText(QApplication::translate("Feature", "\346\211\247\350\241\214\346\217\220\345\217\226", Q_NULLPTR));
        label_9->setText(QApplication::translate("Feature", "NumberOfThreds", Q_NULLPTR));
        label_10->setText(QApplication::translate("Feature", "MinNeighbors", Q_NULLPTR));
        label_11->setText(QApplication::translate("Feature", "NonMaxRadius", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Feature", "\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        loadSceneBut->setText(QApplication::translate("Feature", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Feature", "ISS", Q_NULLPTR));
        label_3->setText(QApplication::translate("Feature", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Feature", "\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        loadSceneBut_2->setText(QApplication::translate("Feature", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Feature", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        label_12->setText(QApplication::translate("Feature", "Min_scale", Q_NULLPTR));
        label_13->setText(QApplication::translate("Feature", "N_octaves \347\251\272\351\227\264\345\261\202\346\225\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("Feature", "Min_contrast", Q_NULLPTR));
        executeButton_2->setText(QApplication::translate("Feature", "\346\211\247\350\241\214\346\217\220\345\217\226", Q_NULLPTR));
        label_17->setText(QApplication::translate("Feature", "N_scales_per_octave", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Feature", "SIFT", Q_NULLPTR));
        label_4->setText(QApplication::translate("Feature", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Feature", "\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        loadSceneBut_3->setText(QApplication::translate("Feature", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Feature", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        label_18->setText(QApplication::translate("Feature", "Model_solution", Q_NULLPTR));
        label_19->setText(QApplication::translate("Feature", "SalientRadius", Q_NULLPTR));
        label_20->setText(QApplication::translate("Feature", "Threshold", Q_NULLPTR));
        executeButton_3->setText(QApplication::translate("Feature", "\346\211\247\350\241\214\346\217\220\345\217\226", Q_NULLPTR));
        label_21->setText(QApplication::translate("Feature", "NumberOfThreds", Q_NULLPTR));
        label_22->setText(QApplication::translate("Feature", "MinNeighbors", Q_NULLPTR));
        label_23->setText(QApplication::translate("Feature", "NonMaxRadius", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Feature", "SHOT", Q_NULLPTR));
        label_5->setText(QApplication::translate("Feature", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Feature", "\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        loadSceneBut_4->setText(QApplication::translate("Feature", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Feature", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        executeButton_4->setText(QApplication::translate("Feature", "\346\211\247\350\241\214\346\217\220\345\217\226", Q_NULLPTR));
        label_27->setText(QApplication::translate("Feature", "R_Keypoint", Q_NULLPTR));
        label_28->setText(QApplication::translate("Feature", "R_Normal", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Feature", "Harris", Q_NULLPTR));
        label_15->setText(QApplication::translate("Feature", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Feature", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        executeButton_5->setText(QApplication::translate("Feature", "\346\211\247\350\241\214\346\217\220\345\217\226", Q_NULLPTR));
        label_29->setText(QApplication::translate("Feature", "Support_Size   \347\202\271\344\272\221\345\244\247\345\260\217\350\256\276\347\275\256", Q_NULLPTR));
        label_30->setText(QApplication::translate("Feature", "Angular_Resolution \346\267\261\345\272\246\344\274\240\346\204\237\345\231\250\350\247\222\345\272\246\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label_31->setText(QApplication::translate("Feature", "Noise_Level", Q_NULLPTR));
        label_32->setText(QApplication::translate("Feature", "Min_Range", Q_NULLPTR));
        label_33->setText(QApplication::translate("Feature", "Border_Size", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("Feature", "\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        loadSceneBut_5->setText(QApplication::translate("Feature", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Feature", "NARF", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Feature: public Ui_Feature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATURE_H
