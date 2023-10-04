#-------------------------------------------------
#
# Project created by QtCreator 2023-09-28T12:46:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LiamsJourney
TEMPLATE = app

INCLUDEPATH += "C:/Program Files/Immersion Corporation/IFC23/inc"

LIBS +="C:/Program Files/Immersion Corporation/IFC23/lib/IFC23.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    gestionhaptique.cpp

HEADERS  += mainwindow.h \
    gestionhaptique.h

FORMS    += mainwindow.ui
