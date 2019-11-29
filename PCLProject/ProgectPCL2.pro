#-------------------------------------------------
#
# Project created by QtCreator 2019-06-11T16:49:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgectPCL2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(E:\DHRoboticsWork\QtCreator-PCL\PCL.pri)


SOURCES += main.cpp\
        mainwindow.cpp \
    filter.cpp \
    pclsegmentation.cpp \
    registation.cpp \
    transform.cpp \
    feature.cpp \
    flow.cpp

HEADERS  += mainwindow.h \
    filter.h \
    global.h \
    pclsegmentation.h \
    registation.h \
    transform.h \
    feature.h \
    flow.h

FORMS    += mainwindow.ui \
    filter.ui \
    pclsegmentation.ui \
    registation.ui \
    transform.ui \
    feature.ui \
    flow.ui

RESOURCES += \
    img.qrc
