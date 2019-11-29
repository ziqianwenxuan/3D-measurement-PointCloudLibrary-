/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Filter
{
public:
    QWidget *centralwidget;
    QVTKWidget *qvtkWidget;
    QVTKWidget *qvtkWidget_2;
    QVTKWidget *qvtkWidget_3;
    QVTKWidget *qvtkWidget_4;
    QVTKWidget *qvtkWidget_5;
    QVTKWidget *qvtkWidget_6;
    QVTKWidget *qvtkWidget_7;
    QVTKWidget *qvtkWidget_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox;
    QLabel *label_11;
    QDoubleSpinBox *SMTBox;
    QPushButton *SODoBUT;
    QPushButton *SOLoadBUT;
    QLabel *label_10;
    QDoubleSpinBox *MKBox;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QPushButton *VGLoadBUT;
    QDoubleSpinBox *leafSizeSBox;
    QPushButton *VGDoBUT;
    QGroupBox *groupBox_3;
    QLabel *label_12;
    QDoubleSpinBox *DTBox;
    QLabel *label_13;
    QDoubleSpinBox *MIBox;
    QPushButton *MCLoadBUT;
    QPushButton *MCDoBUT;
    QGroupBox *groupBox_4;
    QPushButton *PTLoadBUT;
    QPushButton *PTDoBUT;
    QDoubleSpinBox *ULBox;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *LLBox;
    QRadioButton *radioButton;
    QGroupBox *groupBox_5;
    QPushButton *CRLoadBUT;
    QPushButton *CRDoBUT;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *LTBox;
    QDoubleSpinBox *GTBox;
    QGroupBox *groupBox_6;
    QPushButton *RORLoadBUT;
    QPushButton *RORDoBUT;
    QDoubleSpinBox *LJBox;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *BJBox;
    QGroupBox *groupBox_7;
    QPushButton *EIDoBUT;
    QPushButton *EILoadBUT;
    QGroupBox *groupBox_8;
    QPushButton *CHDoBUT;
    QPushButton *CHLoadBUT;
    QDoubleSpinBox *aBox;
    QLabel *label_18;
    QDoubleSpinBox *bBox;
    QLabel *label_19;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Filter)
    {
        if (Filter->objectName().isEmpty())
            Filter->setObjectName(QStringLiteral("Filter"));
        Filter->resize(1910, 1181);
        centralwidget = new QWidget(Filter);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(20, 30, 391, 331));
        qvtkWidget_2 = new QVTKWidget(centralwidget);
        qvtkWidget_2->setObjectName(QStringLiteral("qvtkWidget_2"));
        qvtkWidget_2->setGeometry(QRect(510, 40, 391, 321));
        qvtkWidget_3 = new QVTKWidget(centralwidget);
        qvtkWidget_3->setObjectName(QStringLiteral("qvtkWidget_3"));
        qvtkWidget_3->setGeometry(QRect(980, 40, 391, 331));
        qvtkWidget_4 = new QVTKWidget(centralwidget);
        qvtkWidget_4->setObjectName(QStringLiteral("qvtkWidget_4"));
        qvtkWidget_4->setGeometry(QRect(1410, 40, 391, 331));
        qvtkWidget_5 = new QVTKWidget(centralwidget);
        qvtkWidget_5->setObjectName(QStringLiteral("qvtkWidget_5"));
        qvtkWidget_5->setGeometry(QRect(30, 560, 391, 351));
        qvtkWidget_6 = new QVTKWidget(centralwidget);
        qvtkWidget_6->setObjectName(QStringLiteral("qvtkWidget_6"));
        qvtkWidget_6->setGeometry(QRect(500, 570, 391, 341));
        qvtkWidget_7 = new QVTKWidget(centralwidget);
        qvtkWidget_7->setObjectName(QStringLiteral("qvtkWidget_7"));
        qvtkWidget_7->setGeometry(QRect(970, 600, 391, 311));
        qvtkWidget_8 = new QVTKWidget(centralwidget);
        qvtkWidget_8->setObjectName(QStringLiteral("qvtkWidget_8"));
        qvtkWidget_8->setGeometry(QRect(1420, 600, 391, 311));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 0, 141, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(620, 0, 141, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1110, 0, 141, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 530, 141, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1550, 0, 141, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(610, 550, 141, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1060, 550, 201, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1500, 560, 141, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(990, 390, 371, 161));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 80, 111, 21));
        SMTBox = new QDoubleSpinBox(groupBox);
        SMTBox->setObjectName(QStringLiteral("SMTBox"));
        SMTBox->setGeometry(QRect(230, 80, 111, 21));
        SMTBox->setMaximum(9999.99);
        SMTBox->setSingleStep(0.1);
        SMTBox->setValue(1);
        SODoBUT = new QPushButton(groupBox);
        SODoBUT->setObjectName(QStringLiteral("SODoBUT"));
        SODoBUT->setGeometry(QRect(200, 120, 93, 28));
        SOLoadBUT = new QPushButton(groupBox);
        SOLoadBUT->setObjectName(QStringLiteral("SOLoadBUT"));
        SOLoadBUT->setGeometry(QRect(30, 120, 93, 28));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 40, 111, 21));
        MKBox = new QDoubleSpinBox(groupBox);
        MKBox->setObjectName(QStringLiteral("MKBox"));
        MKBox->setGeometry(QRect(230, 40, 111, 21));
        MKBox->setMaximum(9999.99);
        MKBox->setValue(50);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(510, 380, 381, 161));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 40, 111, 21));
        VGLoadBUT = new QPushButton(groupBox_2);
        VGLoadBUT->setObjectName(QStringLiteral("VGLoadBUT"));
        VGLoadBUT->setGeometry(QRect(40, 110, 93, 28));
        leafSizeSBox = new QDoubleSpinBox(groupBox_2);
        leafSizeSBox->setObjectName(QStringLiteral("leafSizeSBox"));
        leafSizeSBox->setGeometry(QRect(220, 40, 111, 21));
        leafSizeSBox->setValue(0.1);
        VGDoBUT = new QPushButton(groupBox_2);
        VGDoBUT->setObjectName(QStringLiteral("VGDoBUT"));
        VGDoBUT->setGeometry(QRect(210, 110, 93, 28));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1420, 400, 371, 161));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 80, 111, 21));
        DTBox = new QDoubleSpinBox(groupBox_3);
        DTBox->setObjectName(QStringLiteral("DTBox"));
        DTBox->setGeometry(QRect(230, 80, 111, 21));
        DTBox->setMaximum(9999.99);
        DTBox->setSingleStep(0.01);
        DTBox->setValue(0.01);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 40, 131, 21));
        MIBox = new QDoubleSpinBox(groupBox_3);
        MIBox->setObjectName(QStringLiteral("MIBox"));
        MIBox->setGeometry(QRect(230, 40, 111, 21));
        MIBox->setMaximum(1e+6);
        MIBox->setValue(1000);
        MCLoadBUT = new QPushButton(groupBox_3);
        MCLoadBUT->setObjectName(QStringLiteral("MCLoadBUT"));
        MCLoadBUT->setGeometry(QRect(60, 120, 93, 28));
        MCDoBUT = new QPushButton(groupBox_3);
        MCDoBUT->setObjectName(QStringLiteral("MCDoBUT"));
        MCDoBUT->setGeometry(QRect(230, 120, 93, 28));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 370, 371, 161));
        PTLoadBUT = new QPushButton(groupBox_4);
        PTLoadBUT->setObjectName(QStringLiteral("PTLoadBUT"));
        PTLoadBUT->setGeometry(QRect(20, 120, 93, 28));
        PTDoBUT = new QPushButton(groupBox_4);
        PTDoBUT->setObjectName(QStringLiteral("PTDoBUT"));
        PTDoBUT->setGeometry(QRect(210, 120, 93, 28));
        ULBox = new QDoubleSpinBox(groupBox_4);
        ULBox->setObjectName(QStringLiteral("ULBox"));
        ULBox->setGeometry(QRect(220, 60, 111, 21));
        ULBox->setMaximum(9999.99);
        ULBox->setSingleStep(0.01);
        ULBox->setValue(8);
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 60, 131, 16));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 30, 121, 16));
        LLBox = new QDoubleSpinBox(groupBox_4);
        LLBox->setObjectName(QStringLiteral("LLBox"));
        LLBox->setGeometry(QRect(220, 20, 111, 21));
        LLBox->setMaximum(1e+6);
        LLBox->setSingleStep(0.1);
        LLBox->setValue(0);
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(90, 90, 115, 19));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(490, 930, 361, 131));
        CRLoadBUT = new QPushButton(groupBox_5);
        CRLoadBUT->setObjectName(QStringLiteral("CRLoadBUT"));
        CRLoadBUT->setGeometry(QRect(30, 90, 93, 28));
        CRDoBUT = new QPushButton(groupBox_5);
        CRDoBUT->setObjectName(QStringLiteral("CRDoBUT"));
        CRDoBUT->setGeometry(QRect(220, 90, 93, 28));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 30, 121, 16));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 60, 131, 16));
        LTBox = new QDoubleSpinBox(groupBox_5);
        LTBox->setObjectName(QStringLiteral("LTBox"));
        LTBox->setGeometry(QRect(220, 60, 111, 21));
        LTBox->setMaximum(9999.99);
        LTBox->setSingleStep(0.01);
        LTBox->setValue(0.8);
        GTBox = new QDoubleSpinBox(groupBox_5);
        GTBox->setObjectName(QStringLiteral("GTBox"));
        GTBox->setGeometry(QRect(220, 30, 111, 21));
        GTBox->setMaximum(1e+6);
        GTBox->setSingleStep(0.1);
        GTBox->setValue(0);
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(950, 930, 361, 131));
        RORLoadBUT = new QPushButton(groupBox_6);
        RORLoadBUT->setObjectName(QStringLiteral("RORLoadBUT"));
        RORLoadBUT->setGeometry(QRect(30, 90, 93, 28));
        RORDoBUT = new QPushButton(groupBox_6);
        RORDoBUT->setObjectName(QStringLiteral("RORDoBUT"));
        RORDoBUT->setGeometry(QRect(200, 90, 93, 28));
        LJBox = new QDoubleSpinBox(groupBox_6);
        LJBox->setObjectName(QStringLiteral("LJBox"));
        LJBox->setGeometry(QRect(210, 60, 111, 21));
        LJBox->setMaximum(9999.99);
        LJBox->setSingleStep(1);
        LJBox->setValue(100);
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 60, 131, 16));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 30, 121, 16));
        BJBox = new QDoubleSpinBox(groupBox_6);
        BJBox->setObjectName(QStringLiteral("BJBox"));
        BJBox->setGeometry(QRect(210, 30, 111, 21));
        BJBox->setMaximum(1e+6);
        BJBox->setSingleStep(0.1);
        BJBox->setValue(0.9);
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 930, 381, 121));
        EIDoBUT = new QPushButton(groupBox_7);
        EIDoBUT->setObjectName(QStringLiteral("EIDoBUT"));
        EIDoBUT->setGeometry(QRect(220, 80, 93, 28));
        EILoadBUT = new QPushButton(groupBox_7);
        EILoadBUT->setObjectName(QStringLiteral("EILoadBUT"));
        EILoadBUT->setGeometry(QRect(50, 80, 93, 28));
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(1410, 940, 371, 131));
        CHDoBUT = new QPushButton(groupBox_8);
        CHDoBUT->setObjectName(QStringLiteral("CHDoBUT"));
        CHDoBUT->setGeometry(QRect(190, 90, 93, 28));
        CHLoadBUT = new QPushButton(groupBox_8);
        CHLoadBUT->setObjectName(QStringLiteral("CHLoadBUT"));
        CHLoadBUT->setGeometry(QRect(40, 90, 93, 28));
        aBox = new QDoubleSpinBox(groupBox_8);
        aBox->setObjectName(QStringLiteral("aBox"));
        aBox->setGeometry(QRect(220, 30, 111, 21));
        aBox->setMaximum(1e+6);
        aBox->setSingleStep(0.1);
        aBox->setValue(2);
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 60, 131, 16));
        bBox = new QDoubleSpinBox(groupBox_8);
        bBox->setObjectName(QStringLiteral("bBox"));
        bBox->setGeometry(QRect(220, 60, 111, 21));
        bBox->setMaximum(9999.99);
        bBox->setSingleStep(1);
        bBox->setValue(2);
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 30, 121, 16));
        Filter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Filter);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1910, 26));
        Filter->setMenuBar(menubar);
        statusbar = new QStatusBar(Filter);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Filter->setStatusBar(statusbar);

        retranslateUi(Filter);

        QMetaObject::connectSlotsByName(Filter);
    } // setupUi

    void retranslateUi(QMainWindow *Filter)
    {
        Filter->setWindowTitle(QApplication::translate("Filter", "\345\270\270\347\224\250\347\232\204\345\207\240\347\247\215\346\273\244\346\263\242", Q_NULLPTR));
        label->setText(QApplication::translate("Filter", "PassThrough", Q_NULLPTR));
        label_2->setText(QApplication::translate("Filter", "VoxelGrid", Q_NULLPTR));
        label_3->setText(QApplication::translate("Filter", "StatisticalOutlierRemoval ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Filter", "ModelCoefficients ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Filter", "ExtractIndices", Q_NULLPTR));
        label_6->setText(QApplication::translate("Filter", "ConditionalRemoval ", Q_NULLPTR));
        label_7->setText(QApplication::translate("Filter", "RadiusOutlierRemoval", Q_NULLPTR));
        label_8->setText(QApplication::translate("Filter", "CropHull", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Filter", "\347\273\237\350\256\241\345\210\206\346\236\220", Q_NULLPTR));
        label_11->setText(QApplication::translate("Filter", "StddevMulThresh", Q_NULLPTR));
        SODoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        SOLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        label_10->setText(QApplication::translate("Filter", "MeanK", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Filter", "\344\275\223\347\264\240\345\214\226\346\240\205\346\240\274\344\270\213\351\207\207\346\240\267", Q_NULLPTR));
        label_9->setText(QApplication::translate("Filter", "LeafSize", Q_NULLPTR));
        VGLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        VGDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Filter", "\345\237\272\344\272\216\351\232\217\346\234\272\344\270\200\350\207\264\346\200\247\345\210\206\345\211\262\347\256\227\346\263\225", Q_NULLPTR));
        label_12->setText(QApplication::translate("Filter", "DistanceThreshold", Q_NULLPTR));
        label_13->setText(QApplication::translate("Filter", "MaxIterations", Q_NULLPTR));
        MCLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        MCDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Filter", "\347\233\264\351\200\232\346\273\244\346\263\242", Q_NULLPTR));
        PTLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        PTDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        label_20->setText(QApplication::translate("Filter", "Upper Limit", Q_NULLPTR));
        label_21->setText(QApplication::translate("Filter", "Lower Limit", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Filter", "\350\277\207\346\273\244\350\214\203\345\233\264\345\206\205", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Filter", "\350\207\252\345\256\232\344\271\211\346\235\241\344\273\266\346\273\244\351\231\244", Q_NULLPTR));
        CRLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        CRDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        label_14->setText(QApplication::translate("Filter", "Z\346\226\271\345\220\221 GT", Q_NULLPTR));
        label_15->setText(QApplication::translate("Filter", "Z\346\226\271\345\220\221 LT", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Filter", "\345\257\206\345\272\246\346\273\244\351\231\244", Q_NULLPTR));
        RORLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        RORDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        label_16->setText(QApplication::translate("Filter", "\351\202\273\350\277\221\347\202\271\351\233\206\346\225\260", Q_NULLPTR));
        label_17->setText(QApplication::translate("Filter", "\345\215\212\345\276\204\350\214\203\345\233\264", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Filter", "\346\212\225\345\275\261\346\250\241\345\236\213", Q_NULLPTR));
        EIDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        EILoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Filter", "\345\244\232\350\276\271\345\275\242\345\206\205\351\203\250\347\202\271\344\272\221\346\217\220\345\217\226", Q_NULLPTR));
        CHDoBUT->setText(QApplication::translate("Filter", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        CHLoadBUT->setText(QApplication::translate("Filter", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        label_18->setText(QApplication::translate("Filter", "\345\207\275\346\225\260\347\273\264\345\272\246", Q_NULLPTR));
        label_19->setText(QApplication::translate("Filter", "\345\207\270\345\214\205\347\273\264\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Filter: public Ui_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
