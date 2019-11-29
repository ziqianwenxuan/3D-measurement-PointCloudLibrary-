#-------------------------------------------------
#
# Project created by QtCreator 2019-06-18T14:41:36
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCLProject2
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
include(E:\Program Code\QtCreator-PCL\PCL.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    filterpassthrough.cpp \
    filtervoxelgrid.cpp \
    filterstatiscaloutlier.cpp \
    filterextractindices.cpp \
    filterconditionalremoval.cpp \
    filterradiusoutlierremoval.cpp \
    filtercrophull.cpp

HEADERS  += mainwindow.h \
    global.h \
    filterpassthrough.h \
    filtervoxelgrid.h \
    filterstatiscaloutlier.h \
    filterextractindices.h \
    filterconditionalremoval.h \
    filterradiusoutlierremoval.h \
    filtercrophull.h

FORMS    += mainwindow.ui \
    filterpassthrough.ui \
    filtervoxelgrid.ui \
    filterstatiscaloutlier.ui \
    filterextractindices.ui \
    filterconditionalremoval.ui \
    filterradiusoutlierremoval.ui \
    filtercrophull.ui

RESOURCES += \
    res.qrc
