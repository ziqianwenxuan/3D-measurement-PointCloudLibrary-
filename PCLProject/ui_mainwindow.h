/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action8;
    QAction *actionFilter;
    QAction *actionSegmentation;
    QAction *actionRegistation;
    QAction *actionTransform;
    QAction *actionFeature;
    QAction *actionFlow;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menuDemo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1854, 1217);
        action8 = new QAction(MainWindow);
        action8->setObjectName(QStringLiteral("action8"));
        actionFilter = new QAction(MainWindow);
        actionFilter->setObjectName(QStringLiteral("actionFilter"));
        actionSegmentation = new QAction(MainWindow);
        actionSegmentation->setObjectName(QStringLiteral("actionSegmentation"));
        actionRegistation = new QAction(MainWindow);
        actionRegistation->setObjectName(QStringLiteral("actionRegistation"));
        actionTransform = new QAction(MainWindow);
        actionTransform->setObjectName(QStringLiteral("actionTransform"));
        actionFeature = new QAction(MainWindow);
        actionFeature->setObjectName(QStringLiteral("actionFeature"));
        actionFlow = new QAction(MainWindow);
        actionFlow->setObjectName(QStringLiteral("actionFlow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1831, 1141));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1854, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menuDemo = new QMenu(menuBar);
        menuDemo->setObjectName(QStringLiteral("menuDemo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menuDemo->menuAction());
        menu->addAction(actionFilter);
        menu_2->addAction(actionSegmentation);
        menu_3->addAction(actionRegistation);
        menu_4->addAction(actionTransform);
        menu_5->addAction(actionFeature);
        menuDemo->addAction(actionFlow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PCL\345\272\223\345\277\253\346\215\267\350\260\203\347\224\250\346\225\210\346\236\234\346\274\224\347\244\272", Q_NULLPTR));
        action8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        actionFilter->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        actionSegmentation->setText(QApplication::translate("MainWindow", "Segmentation", Q_NULLPTR));
        actionRegistation->setText(QApplication::translate("MainWindow", "Registation", Q_NULLPTR));
        actionTransform->setText(QApplication::translate("MainWindow", "Transform", Q_NULLPTR));
        actionFeature->setText(QApplication::translate("MainWindow", "Feature", Q_NULLPTR));
        actionFlow->setText(QApplication::translate("MainWindow", "Flow", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\273\244\346\263\242", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\210\206\345\211\262", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\205\215\345\207\206", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\275\254\346\215\242", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\347\211\271\345\276\201", Q_NULLPTR));
        menuDemo->setTitle(QApplication::translate("MainWindow", "Demo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
