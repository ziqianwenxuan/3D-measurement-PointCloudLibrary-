/********************************************************************************
** Form generated from reading UI file 'flow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOW_H
#define UI_FLOW_H

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

class Ui_Flow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_9;
    QGroupBox *groupBox_7;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *executeButton_1;
    QDoubleSpinBox *minSTSBox;
    QDoubleSpinBox *maxCDSBox;
    QDoubleSpinBox *maxIterationSBox;
    QVTKWidget *widget;
    QGroupBox *groupBox_5;
    QLabel *label_16;
    QDoubleSpinBox *icpmcdBox;
    QDoubleSpinBox *icpIterationsSBox;
    QLabel *label_30;
    QDoubleSpinBox *mcdSBox;
    QLabel *label_31;
    QDoubleSpinBox *efeSBox;
    QLabel *label_32;
    QPushButton *executeButton_2;
    QLabel *label_17;
    QGroupBox *groupBox_6;
    QLabel *label_18;
    QDoubleSpinBox *TemplateNRBox;
    QPushButton *templateComputeBut_2;
    QVTKWidget *widget_1;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *MSBox_2;
    QDoubleSpinBox *SRBox_2;
    QDoubleSpinBox *TBox_2;
    QDoubleSpinBox *NMRBox_2;
    QLabel *label_23;
    QPushButton *templateComputeBut;
    QPushButton *loadTemplateBut;
    QGroupBox *groupBox_8;
    QLabel *label_15;
    QLabel *label_24;
    QLabel *label_25;
    QDoubleSpinBox *MSBox_1;
    QDoubleSpinBox *SRBox_1;
    QDoubleSpinBox *TBox_1;
    QDoubleSpinBox *NMRBox_1;
    QLabel *label_26;
    QPushButton *sceneComputeBut;
    QPushButton *loadSceneBut;
    QGroupBox *groupBox_9;
    QLabel *label_19;
    QDoubleSpinBox *sceneNRBox;
    QPushButton *sceneComputeBut_2;
    QGroupBox *groupBox_10;
    QLabel *label_27;
    QDoubleSpinBox *sceneNRBox_2;
    QPushButton *sceneComputeBut_3;
    QGroupBox *groupBox_11;
    QLabel *label_28;
    QDoubleSpinBox *TemplateNRBox_2;
    QPushButton *templateComputeBut_3;
    QWidget *tab_2;
    QLabel *label_29;
    QLabel *label_10;
    QVTKWidget *widget_2;
    QVTKWidget *widget_3;
    QGroupBox *groupBox_17;
    QPushButton *loadSceneBut_2;
    QPushButton *loadTemplateBut_2;
    QDoubleSpinBox *sceneNRSBox_2;
    QLabel *label_34;
    QLabel *label_36;
    QDoubleSpinBox *sceneNRSBox_4;
    QLabel *label_37;
    QDoubleSpinBox *sceneNRSBox_5;
    QLabel *label_38;
    QDoubleSpinBox *sceneNRSBox_6;
    QGroupBox *groupBox_2;
    QLabel *label_41;
    QDoubleSpinBox *sceneNRSBox_9;
    QLabel *label_42;
    QDoubleSpinBox *sceneNRSBox_10;
    QDoubleSpinBox *sceneNRSBox_3;
    QLabel *label_35;
    QGroupBox *groupBox_3;
    QLabel *label_40;
    QDoubleSpinBox *sceneNRSBox_8;
    QLabel *label_39;
    QDoubleSpinBox *sceneNRSBox_7;
    QGroupBox *groupBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Flow)
    {
        if (Flow->objectName().isEmpty())
            Flow->setObjectName(QStringLiteral("Flow"));
        Flow->resize(1888, 1194);
        centralwidget = new QWidget(Flow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1861, 1141));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1270, 30, 181, 31));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(50, 760, 351, 161));
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 25, 151, 20));
        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 60, 211, 16));
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(40, 90, 151, 21));
        executeButton_1 = new QPushButton(groupBox_7);
        executeButton_1->setObjectName(QStringLiteral("executeButton_1"));
        executeButton_1->setGeometry(QRect(120, 120, 93, 28));
        minSTSBox = new QDoubleSpinBox(groupBox_7);
        minSTSBox->setObjectName(QStringLiteral("minSTSBox"));
        minSTSBox->setGeometry(QRect(270, 20, 70, 22));
        minSTSBox->setSingleStep(0.01);
        minSTSBox->setValue(0.05);
        maxCDSBox = new QDoubleSpinBox(groupBox_7);
        maxCDSBox->setObjectName(QStringLiteral("maxCDSBox"));
        maxCDSBox->setGeometry(QRect(270, 50, 70, 22));
        maxCDSBox->setSingleStep(0.01);
        maxCDSBox->setValue(0.05);
        maxIterationSBox = new QDoubleSpinBox(groupBox_7);
        maxIterationSBox->setObjectName(QStringLiteral("maxIterationSBox"));
        maxIterationSBox->setGeometry(QRect(270, 90, 70, 22));
        maxIterationSBox->setMaximum(100000);
        maxIterationSBox->setValue(500);
        widget = new QVTKWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(950, 70, 841, 621));
        widget->setAutoFillBackground(true);
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(410, 700, 471, 261));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 40, 341, 20));
        icpmcdBox = new QDoubleSpinBox(groupBox_5);
        icpmcdBox->setObjectName(QStringLiteral("icpmcdBox"));
        icpmcdBox->setGeometry(QRect(380, 40, 70, 22));
        icpmcdBox->setMaximum(10000);
        icpmcdBox->setSingleStep(0.01);
        icpmcdBox->setValue(0.04);
        icpIterationsSBox = new QDoubleSpinBox(groupBox_5);
        icpIterationsSBox->setObjectName(QStringLiteral("icpIterationsSBox"));
        icpIterationsSBox->setGeometry(QRect(380, 80, 70, 22));
        icpIterationsSBox->setMaximum(10000);
        icpIterationsSBox->setValue(100);
        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 80, 261, 16));
        mcdSBox = new QDoubleSpinBox(groupBox_5);
        mcdSBox->setObjectName(QStringLiteral("mcdSBox"));
        mcdSBox->setGeometry(QRect(380, 120, 70, 22));
        mcdSBox->setMaximum(10000);
        mcdSBox->setSingleStep(1e-6);
        mcdSBox->setValue(0);
        label_31 = new QLabel(groupBox_5);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(30, 120, 341, 16));
        efeSBox = new QDoubleSpinBox(groupBox_5);
        efeSBox->setObjectName(QStringLiteral("efeSBox"));
        efeSBox->setGeometry(QRect(380, 160, 70, 22));
        efeSBox->setMaximum(10000);
        efeSBox->setSingleStep(0.01);
        efeSBox->setValue(0.02);
        label_32 = new QLabel(groupBox_5);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(30, 160, 311, 16));
        executeButton_2 = new QPushButton(groupBox_5);
        executeButton_2->setObjectName(QStringLiteral("executeButton_2"));
        executeButton_2->setGeometry(QRect(170, 210, 93, 28));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(290, 20, 141, 31));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(1310, 720, 241, 121));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(30, 30, 121, 16));
        TemplateNRBox = new QDoubleSpinBox(groupBox_6);
        TemplateNRBox->setObjectName(QStringLiteral("TemplateNRBox"));
        TemplateNRBox->setGeometry(QRect(150, 30, 70, 22));
        TemplateNRBox->setSingleStep(0.01);
        TemplateNRBox->setValue(0.02);
        templateComputeBut_2 = new QPushButton(groupBox_6);
        templateComputeBut_2->setObjectName(QStringLiteral("templateComputeBut_2"));
        templateComputeBut_2->setGeometry(QRect(60, 80, 141, 28));
        widget_1 = new QVTKWidget(tab);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setGeometry(QRect(60, 70, 811, 391));
        widget_1->setAutoFillBackground(true);
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(950, 710, 351, 271));
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
        NMRBox_2 = new QDoubleSpinBox(groupBox_4);
        NMRBox_2->setObjectName(QStringLiteral("NMRBox_2"));
        NMRBox_2->setGeometry(QRect(270, 100, 70, 22));
        NMRBox_2->setMaximum(100000);
        NMRBox_2->setValue(4);
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(40, 100, 151, 21));
        templateComputeBut = new QPushButton(groupBox_4);
        templateComputeBut->setObjectName(QStringLiteral("templateComputeBut"));
        templateComputeBut->setGeometry(QRect(170, 200, 141, 28));
        loadTemplateBut = new QPushButton(groupBox_4);
        loadTemplateBut->setObjectName(QStringLiteral("loadTemplateBut"));
        loadTemplateBut->setGeometry(QRect(30, 200, 111, 28));
        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(50, 470, 351, 271));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 35, 151, 20));
        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(40, 70, 211, 16));
        label_25 = new QLabel(groupBox_8);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(40, 140, 151, 21));
        MSBox_1 = new QDoubleSpinBox(groupBox_8);
        MSBox_1->setObjectName(QStringLiteral("MSBox_1"));
        MSBox_1->setGeometry(QRect(270, 30, 70, 22));
        MSBox_1->setSingleStep(0.01);
        MSBox_1->setValue(0.01);
        SRBox_1 = new QDoubleSpinBox(groupBox_8);
        SRBox_1->setObjectName(QStringLiteral("SRBox_1"));
        SRBox_1->setGeometry(QRect(270, 60, 70, 22));
        SRBox_1->setSingleStep(0.1);
        SRBox_1->setValue(6);
        TBox_1 = new QDoubleSpinBox(groupBox_8);
        TBox_1->setObjectName(QStringLiteral("TBox_1"));
        TBox_1->setGeometry(QRect(270, 140, 70, 22));
        TBox_1->setMaximum(100000);
        TBox_1->setSingleStep(0.01);
        TBox_1->setValue(0.01);
        NMRBox_1 = new QDoubleSpinBox(groupBox_8);
        NMRBox_1->setObjectName(QStringLiteral("NMRBox_1"));
        NMRBox_1->setGeometry(QRect(270, 100, 70, 22));
        NMRBox_1->setMaximum(100000);
        NMRBox_1->setValue(4);
        label_26 = new QLabel(groupBox_8);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(40, 100, 151, 21));
        sceneComputeBut = new QPushButton(groupBox_8);
        sceneComputeBut->setObjectName(QStringLiteral("sceneComputeBut"));
        sceneComputeBut->setGeometry(QRect(170, 200, 141, 31));
        loadSceneBut = new QPushButton(groupBox_8);
        loadSceneBut->setObjectName(QStringLiteral("loadSceneBut"));
        loadSceneBut->setGeometry(QRect(30, 200, 111, 28));
        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(410, 480, 191, 111));
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 30, 101, 16));
        sceneNRBox = new QDoubleSpinBox(groupBox_9);
        sceneNRBox->setObjectName(QStringLiteral("sceneNRBox"));
        sceneNRBox->setGeometry(QRect(110, 30, 70, 22));
        sceneNRBox->setSingleStep(0.01);
        sceneNRBox->setValue(0.02);
        sceneComputeBut_2 = new QPushButton(groupBox_9);
        sceneComputeBut_2->setObjectName(QStringLiteral("sceneComputeBut_2"));
        sceneComputeBut_2->setGeometry(QRect(30, 70, 141, 31));
        groupBox_10 = new QGroupBox(tab);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(610, 480, 221, 111));
        label_27 = new QLabel(groupBox_10);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 30, 101, 16));
        sceneNRBox_2 = new QDoubleSpinBox(groupBox_10);
        sceneNRBox_2->setObjectName(QStringLiteral("sceneNRBox_2"));
        sceneNRBox_2->setGeometry(QRect(110, 30, 70, 22));
        sceneNRBox_2->setSingleStep(0.01);
        sceneNRBox_2->setValue(0.02);
        sceneComputeBut_3 = new QPushButton(groupBox_10);
        sceneComputeBut_3->setObjectName(QStringLiteral("sceneComputeBut_3"));
        sceneComputeBut_3->setGeometry(QRect(20, 70, 141, 31));
        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(1560, 730, 241, 121));
        label_28 = new QLabel(groupBox_11);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(30, 30, 121, 16));
        TemplateNRBox_2 = new QDoubleSpinBox(groupBox_11);
        TemplateNRBox_2->setObjectName(QStringLiteral("TemplateNRBox_2"));
        TemplateNRBox_2->setGeometry(QRect(150, 30, 70, 22));
        TemplateNRBox_2->setSingleStep(0.01);
        TemplateNRBox_2->setValue(0.02);
        templateComputeBut_3 = new QPushButton(groupBox_11);
        templateComputeBut_3->setObjectName(QStringLiteral("templateComputeBut_3"));
        templateComputeBut_3->setGeometry(QRect(60, 80, 141, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_29 = new QLabel(tab_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(210, 10, 141, 31));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1080, 10, 181, 31));
        widget_2 = new QVTKWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(920, 40, 491, 471));
        widget_2->setAutoFillBackground(true);
        widget_3 = new QVTKWidget(tab_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 40, 891, 1051));
        widget_3->setAutoFillBackground(true);
        groupBox_17 = new QGroupBox(tab_2);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        groupBox_17->setGeometry(QRect(1410, 30, 431, 421));
        loadSceneBut_2 = new QPushButton(groupBox_17);
        loadSceneBut_2->setObjectName(QStringLiteral("loadSceneBut_2"));
        loadSceneBut_2->setGeometry(QRect(40, 390, 111, 28));
        loadTemplateBut_2 = new QPushButton(groupBox_17);
        loadTemplateBut_2->setObjectName(QStringLiteral("loadTemplateBut_2"));
        loadTemplateBut_2->setGeometry(QRect(220, 390, 111, 28));
        sceneNRSBox_2 = new QDoubleSpinBox(groupBox_17);
        sceneNRSBox_2->setObjectName(QStringLiteral("sceneNRSBox_2"));
        sceneNRSBox_2->setGeometry(QRect(330, 130, 70, 22));
        sceneNRSBox_2->setDecimals(3);
        sceneNRSBox_2->setSingleStep(0.01);
        sceneNRSBox_2->setValue(0.05);
        label_34 = new QLabel(groupBox_17);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(40, 140, 231, 16));
        label_36 = new QLabel(groupBox_17);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(40, 170, 331, 16));
        sceneNRSBox_4 = new QDoubleSpinBox(groupBox_17);
        sceneNRSBox_4->setObjectName(QStringLiteral("sceneNRSBox_4"));
        sceneNRSBox_4->setGeometry(QRect(330, 160, 70, 22));
        sceneNRSBox_4->setDecimals(3);
        sceneNRSBox_4->setMaximum(10000);
        sceneNRSBox_4->setSingleStep(0.0001);
        sceneNRSBox_4->setValue(0.05);
        label_37 = new QLabel(groupBox_17);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(40, 200, 331, 16));
        sceneNRSBox_5 = new QDoubleSpinBox(groupBox_17);
        sceneNRSBox_5->setObjectName(QStringLiteral("sceneNRSBox_5"));
        sceneNRSBox_5->setGeometry(QRect(330, 190, 70, 22));
        sceneNRSBox_5->setDecimals(3);
        sceneNRSBox_5->setSingleStep(0.01);
        sceneNRSBox_5->setValue(0.01);
        label_38 = new QLabel(groupBox_17);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(40, 240, 331, 16));
        sceneNRSBox_6 = new QDoubleSpinBox(groupBox_17);
        sceneNRSBox_6->setObjectName(QStringLiteral("sceneNRSBox_6"));
        sceneNRSBox_6->setGeometry(QRect(330, 230, 70, 22));
        sceneNRSBox_6->setSingleStep(0.01);
        sceneNRSBox_6->setValue(5);
        groupBox_2 = new QGroupBox(groupBox_17);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 331, 111));
        label_41 = new QLabel(groupBox_2);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(40, 60, 51, 16));
        sceneNRSBox_9 = new QDoubleSpinBox(groupBox_2);
        sceneNRSBox_9->setObjectName(QStringLiteral("sceneNRSBox_9"));
        sceneNRSBox_9->setGeometry(QRect(240, 80, 70, 22));
        sceneNRSBox_9->setSingleStep(0.01);
        sceneNRSBox_9->setValue(5);
        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(40, 80, 71, 16));
        sceneNRSBox_10 = new QDoubleSpinBox(groupBox_2);
        sceneNRSBox_10->setObjectName(QStringLiteral("sceneNRSBox_10"));
        sceneNRSBox_10->setGeometry(QRect(240, 50, 70, 22));
        sceneNRSBox_10->setSingleStep(0.01);
        sceneNRSBox_10->setValue(10);
        sceneNRSBox_3 = new QDoubleSpinBox(groupBox_2);
        sceneNRSBox_3->setObjectName(QStringLiteral("sceneNRSBox_3"));
        sceneNRSBox_3->setGeometry(QRect(240, 20, 70, 22));
        sceneNRSBox_3->setSingleStep(1);
        sceneNRSBox_3->setValue(10);
        label_35 = new QLabel(groupBox_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(0, 30, 231, 16));
        groupBox_3 = new QGroupBox(groupBox_17);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 30, 401, 91));
        label_40 = new QLabel(groupBox_3);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(20, 60, 271, 16));
        sceneNRSBox_8 = new QDoubleSpinBox(groupBox_3);
        sceneNRSBox_8->setObjectName(QStringLiteral("sceneNRSBox_8"));
        sceneNRSBox_8->setGeometry(QRect(310, 20, 70, 22));
        sceneNRSBox_8->setSingleStep(0.01);
        sceneNRSBox_8->setValue(0.01);
        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(20, 30, 261, 16));
        sceneNRSBox_7 = new QDoubleSpinBox(groupBox_3);
        sceneNRSBox_7->setObjectName(QStringLiteral("sceneNRSBox_7"));
        sceneNRSBox_7->setGeometry(QRect(310, 50, 70, 22));
        sceneNRSBox_7->setSingleStep(0.01);
        sceneNRSBox_7->setValue(0.03);
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1450, 460, 391, 571));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 250, 271, 28));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 160, 271, 28));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 200, 301, 28));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 110, 321, 28));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 241, 28));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(60, 310, 151, 28));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 360, 151, 28));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 400, 151, 28));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(920, 550, 501, 381));
        tabWidget->addTab(tab_2, QString());
        Flow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Flow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1888, 26));
        Flow->setMenuBar(menubar);
        statusbar = new QStatusBar(Flow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Flow->setStatusBar(statusbar);

        retranslateUi(Flow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Flow);
    } // setupUi

    void retranslateUi(QMainWindow *Flow)
    {
        Flow->setWindowTitle(QApplication::translate("Flow", "MainWindow", Q_NULLPTR));
        label_9->setText(QApplication::translate("Flow", "\346\250\241\346\235\277\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Flow", "SAC-IA\351\205\215\345\207\206", Q_NULLPTR));
        label_20->setText(QApplication::translate("Flow", "MinSampleDistance", Q_NULLPTR));
        label_21->setText(QApplication::translate("Flow", "MaxCorrespondenceDistance", Q_NULLPTR));
        label_22->setText(QApplication::translate("Flow", "MaximumIterations", Q_NULLPTR));
        executeButton_1->setText(QApplication::translate("Flow", "\346\211\247\350\241\214\351\205\215\345\207\206", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Flow", "ICP\351\205\215\345\207\206", Q_NULLPTR));
        label_16->setText(QApplication::translate("Flow", "MaxCorrespondenceDistance\346\234\200\345\244\247\345\257\271\345\272\224\347\202\271\350\277\221\351\202\273\350\267\235\347\246\273", Q_NULLPTR));
        label_30->setText(QApplication::translate("Flow", "MaximumIterations\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260", Q_NULLPTR));
        label_31->setText(QApplication::translate("Flow", "TransformationEpsilon\344\270\244\346\254\241\345\217\230\345\214\226\347\237\251\351\230\265\344\271\213\351\227\264\347\232\204\345\267\256\345\200\274", Q_NULLPTR));
        label_32->setText(QApplication::translate("Flow", "EuclideanFitnessEpsilon// \345\235\207\346\226\271\350\257\257\345\267\256", Q_NULLPTR));
        executeButton_2->setText(QApplication::translate("Flow", "\346\211\247\350\241\214\351\205\215\345\207\206", Q_NULLPTR));
        label_17->setText(QApplication::translate("Flow", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Flow", "\346\250\241\346\235\277\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        label_18->setText(QApplication::translate("Flow", "NormalRadius", Q_NULLPTR));
        templateComputeBut_2->setText(QApplication::translate("Flow", "\350\256\241\347\256\227\346\263\225\347\272\277", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Flow", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        label_12->setText(QApplication::translate("Flow", "Min_scale", Q_NULLPTR));
        label_13->setText(QApplication::translate("Flow", "N_octaves \347\251\272\351\227\264\345\261\202\346\225\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("Flow", "Min_contrast", Q_NULLPTR));
        label_23->setText(QApplication::translate("Flow", "N_scales_per_octave", Q_NULLPTR));
        templateComputeBut->setText(QApplication::translate("Flow", "\350\256\241\347\256\227\345\205\263\351\224\256\347\202\271", Q_NULLPTR));
        loadTemplateBut->setText(QApplication::translate("Flow", "\345\212\240\350\275\275\346\250\241\346\235\277\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Flow", "\345\205\263\351\224\256\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        label_15->setText(QApplication::translate("Flow", "Min_scale", Q_NULLPTR));
        label_24->setText(QApplication::translate("Flow", "N_octaves \347\251\272\351\227\264\345\261\202\346\225\260", Q_NULLPTR));
        label_25->setText(QApplication::translate("Flow", "Min_contrast", Q_NULLPTR));
        label_26->setText(QApplication::translate("Flow", "N_scales_per_octave", Q_NULLPTR));
        sceneComputeBut->setText(QApplication::translate("Flow", "\350\256\241\347\256\227\345\205\263\351\224\256\347\202\271", Q_NULLPTR));
        loadSceneBut->setText(QApplication::translate("Flow", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Flow", "\345\234\272\346\231\257\347\202\271\344\272\221\345\244\204\347\220\206", Q_NULLPTR));
        label_19->setText(QApplication::translate("Flow", "NormalRadius", Q_NULLPTR));
        sceneComputeBut_2->setText(QApplication::translate("Flow", "\350\256\241\347\256\227\346\263\225\347\272\277", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("Flow", "FPFH\347\211\271\345\276\201\350\256\241\347\256\227", Q_NULLPTR));
        label_27->setText(QApplication::translate("Flow", "NormalRadius", Q_NULLPTR));
        sceneComputeBut_3->setText(QApplication::translate("Flow", "\350\256\241\347\256\227FPFH\347\211\271\345\276\201", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("Flow", "FPFH\347\211\271\345\276\201\350\256\241\347\256\227", Q_NULLPTR));
        label_28->setText(QApplication::translate("Flow", "NormalRadius", Q_NULLPTR));
        templateComputeBut_3->setText(QApplication::translate("Flow", "\350\256\241\347\256\227FPFH\347\211\271\345\276\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Flow", "Tab 1", Q_NULLPTR));
        label_29->setText(QApplication::translate("Flow", "\345\234\272\346\231\257\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        label_10->setText(QApplication::translate("Flow", "\346\250\241\346\235\277\347\202\271\344\272\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_17->setTitle(QApplication::translate("Flow", "\345\217\202\346\225\260\350\260\203\350\257\225", Q_NULLPTR));
        loadSceneBut_2->setText(QApplication::translate("Flow", "\345\212\240\350\275\275\347\233\256\346\240\207\347\202\271\344\272\221", Q_NULLPTR));
        loadTemplateBut_2->setText(QApplication::translate("Flow", "\345\212\240\350\275\275\346\250\241\346\235\277\347\202\271\344\272\221", Q_NULLPTR));
        label_34->setText(QApplication::translate("Flow", "descr_rad_model\347\211\271\345\276\201\346\217\217\350\277\260\345\255\220\345\215\212\345\276\204", Q_NULLPTR));
        label_36->setText(QApplication::translate("Flow", "rf_RadiusSearch \345\261\200\351\203\250\345\217\202\350\200\203\345\235\220\346\240\207\347\263\273\345\215\212\345\276\204", Q_NULLPTR));
        label_37->setText(QApplication::translate("Flow", "HoughBinSize 3Dhough\345\257\271\345\272\224\347\232\204\347\251\272\351\227\264\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label_38->setText(QApplication::translate("Flow", "HoughThreshold \346\234\200\345\260\221\345\257\271\345\272\224\347\202\271\346\225\260\347\233\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Flow", "\346\263\225\347\272\277\345\261\225\347\244\272", Q_NULLPTR));
        label_41->setText(QApplication::translate("Flow", "level ", Q_NULLPTR));
        label_42->setText(QApplication::translate("Flow", "scale", Q_NULLPTR));
        label_35->setText(QApplication::translate("Flow", "KSearch\346\263\225\347\272\277\344\274\260\350\256\241\347\232\204K\351\202\273\345\237\237\346\220\234\347\264\242\351\230\210\345\200\274", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Flow", "\351\207\207\346\240\267\350\256\276\347\275\256", Q_NULLPTR));
        label_40->setText(QApplication::translate("Flow", "RadiusSearch_scene\345\235\207\345\214\200\351\207\207\346\240\267\347\232\204\346\273\244\346\263\242", Q_NULLPTR));
        label_39->setText(QApplication::translate("Flow", "RadiusSearch_model\345\235\207\345\214\200\351\207\207\346\240\267\347\232\204\346\273\244\346\263\242", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Flow", "\346\265\201\347\250\213", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Flow", "5.hough3D\350\201\232\347\261\273\345\244\204\347\220\206Hough3DGrouping", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Flow", "3.SHOT\347\211\271\345\276\201\346\217\217\350\277\260\345\255\220SHOTEstimationOMP", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Flow", "4.\347\241\256\345\256\232\345\257\271\345\272\224\345\205\263\347\263\273\357\274\214\345\257\273\346\211\276\345\214\271\351\205\215\347\202\271KdTreeFLANN", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Flow", "2.\350\256\241\347\256\227\345\205\263\351\224\256\347\202\271\357\274\210\345\235\207\345\214\200\351\207\207\346\240\267UniformSampling\357\274\211", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Flow", "1.\350\256\241\347\256\227\346\263\225\347\272\277NormalEstimationOMP", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Flow", "6.\347\211\233\345\245\266\347\233\222\345\255\220\346\265\213\350\257\225\346\214\211\351\224\256", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Flow", "7.\350\207\252\350\241\214\350\275\246\346\265\213\350\257\225\346\214\211\351\224\256", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Flow", "8.\345\260\217\351\233\266\344\273\266\346\265\213\350\257\225\346\214\211\351\224\256", Q_NULLPTR));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Flow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Flow: public Ui_Flow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOW_H