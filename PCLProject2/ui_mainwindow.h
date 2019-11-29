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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QVTKWidget *qvtkWidget;
    QGroupBox *load_button;
    QPushButton *LoadBUT;
    QPushButton *save_button;
    QPushButton *excuteButton;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox_3;
    QTextBrowser *textBrowser_2;
    QTextEdit *textEdit_2;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_X;
    QMenu *menu_V;
    QMenu *menu_P;
    QMenu *menu_O;
    QMenu *menu_S;
    QMenu *menu_A;
    QMenu *menu_W;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1409, 1084);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/treelcon/res_treeItemIcon/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/treelcon/res_treeItemIcon/Project.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon1);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/treelcon/res_treeItemIcon/folder_original.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 670, 171, 311));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 93, 28));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 70, 93, 28));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 120, 93, 28));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 160, 93, 28));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 210, 93, 28));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 250, 93, 28));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(200, 20, 781, 651));
        qvtkWidget->setAutoFillBackground(true);
        load_button = new QGroupBox(centralWidget);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(200, 680, 791, 61));
        LoadBUT = new QPushButton(load_button);
        LoadBUT->setObjectName(QStringLiteral("LoadBUT"));
        LoadBUT->setGeometry(QRect(140, 20, 93, 28));
        save_button = new QPushButton(load_button);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(390, 20, 93, 28));
        excuteButton = new QPushButton(load_button);
        excuteButton->setObjectName(QStringLiteral("excuteButton"));
        excuteButton->setGeometry(QRect(650, 20, 93, 28));
        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(1170, 10, 194, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 750, 931, 211));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1000, 10, 131, 731));
        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(20, 150, 93, 28));
        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 200, 93, 28));
        pushButton_12 = new QPushButton(groupBox_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(20, 250, 93, 28));
        pushButton_13 = new QPushButton(groupBox_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(20, 300, 93, 28));
        pushButton_14 = new QPushButton(groupBox_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(20, 350, 93, 28));
        pushButton_15 = new QPushButton(groupBox_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(20, 100, 93, 28));
        pushButton_16 = new QPushButton(groupBox_4);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 500, 81, 61));
        pushButton_16->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 170, 127);\n"
"font: 20pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"\n"
""));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(1140, 40, 240, 950));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 221, 581));
        textBrowser_2 = new QTextBrowser(groupBox_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 20, 201, 551));
        textEdit_2 = new QTextEdit(page);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 620, 201, 281));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 181, 641));
        treeView = new QTreeView(groupBox_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEnabled(true);
        treeView->setGeometry(QRect(0, 20, 181, 621));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1409, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_X = new QMenu(menuBar);
        menu_X->setObjectName(QStringLiteral("menu_X"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu_P = new QMenu(menuBar);
        menu_P->setObjectName(QStringLiteral("menu_P"));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        menu_S = new QMenu(menuBar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_A = new QMenu(menuBar);
        menu_A->setObjectName(QStringLiteral("menu_A"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QStringLiteral("menu_W"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_X->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_P->menuAction());
        menuBar->addAction(menu_O->menuAction());
        menuBar->addAction(menu_S->menuAction());
        menuBar->addAction(menu_A->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        mainToolBar->addAction(action);
        toolBar->addAction(action_3);
        toolBar_2->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PCL\350\260\203\345\217\202\346\265\213\350\257\225\345\267\245\345\205\267", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\267\245\347\250\213", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_2->setToolTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_3->setToolTip(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_3->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\240\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\202\271\344\272\221\346\213\274\346\216\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\253\230\345\272\246\346\265\213\351\207\217", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\271\263\351\235\242\345\272\246\346\265\213\351\207\217", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\344\275\223\347\247\257\350\256\241\347\256\227", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "ROI\350\243\201\345\211\252", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\345\274\202\347\211\251\346\243\200\346\265\213", Q_NULLPTR));
        load_button->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221\346\240\217", Q_NULLPTR));
        LoadBUT->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\347\202\271\344\272\221", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        excuteButton->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226\346\257\217\344\270\200\346\255\245\347\232\204\345\217\202\346\225\260\347\232\204", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\265\213\350\257\225\350\204\232\346\234\254", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "\345\216\273\351\231\244NAN\347\202\271", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "\347\202\271\344\272\221\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "\347\202\271\344\272\221\345\210\206\345\211\262", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "\347\211\271\345\276\201\347\255\233\351\200\211", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "\347\211\271\345\276\201\345\214\271\351\205\215", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\347\202\271\344\272\221", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\350\260\203\345\217\202\346\240\217", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\351\207\214\351\235\242\346\230\257\346\257\217\344\270\200\344\270\252\347\261\273\345\236\213\347\232\204\345\217\202\346\225\260\350\260\203\350\257\225</p></body></html>", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\351\207\214\346\230\257\347\274\226\350\276\221\346\241\206\357\274\214\347\224\250\346\235\245\345\206\231\345\244\207\346\263\250\347\232\204</p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275\346\240\217", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", Q_NULLPTR));
        menu_X->setTitle(QApplication::translate("MainWindow", "\346\211\247\350\241\214(X)", Q_NULLPTR));
        menu_V->setTitle(QApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226(V)", Q_NULLPTR));
        menu_P->setTitle(QApplication::translate("MainWindow", "\345\207\275\346\225\260(P)", Q_NULLPTR));
        menu_O->setTitle(QApplication::translate("MainWindow", "\347\256\227\345\255\220(O)", Q_NULLPTR));
        menu_S->setTitle(QApplication::translate("MainWindow", "\345\273\272\350\256\256(S)", Q_NULLPTR));
        menu_A->setTitle(QApplication::translate("MainWindow", "\345\212\251\346\211\213\357\274\210A\357\274\211", Q_NULLPTR));
        menu_W->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243(W)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
