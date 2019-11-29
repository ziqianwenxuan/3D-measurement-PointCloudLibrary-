/********************************************************************************
** Form generated from reading UI file 'passthrough.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSTHROUGH_H
#define UI_PASSTHROUGH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassThrough
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLabel *label;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PassThrough)
    {
        if (PassThrough->objectName().isEmpty())
            PassThrough->setObjectName(QStringLiteral("PassThrough"));
        PassThrough->resize(280, 664);
        centralwidget = new QWidget(PassThrough);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 330, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 72, 15));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(150, 100, 46, 22));
        PassThrough->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PassThrough);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 280, 26));
        PassThrough->setMenuBar(menubar);
        statusbar = new QStatusBar(PassThrough);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PassThrough->setStatusBar(statusbar);

        retranslateUi(PassThrough);

        QMetaObject::connectSlotsByName(PassThrough);
    } // setupUi

    void retranslateUi(QMainWindow *PassThrough)
    {
        PassThrough->setWindowTitle(QApplication::translate("PassThrough", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PassThrough", "\346\211\247\350\241\214\350\277\207\346\273\244", Q_NULLPTR));
        label->setText(QApplication::translate("PassThrough", "\350\277\207\346\273\244\346\235\241\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PassThrough: public Ui_PassThrough {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSTHROUGH_H
