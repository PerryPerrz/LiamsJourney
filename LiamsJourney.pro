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
    pageone.cpp \
    homepage.cpp \
    haptichandler.cpp \
    clickablelabel.cpp

HEADERS  += mainwindow.h \
    pageone.h \
    homepage.h \
    haptichandler.h \
    clickablelabel.h

FORMS    += mainwindow.ui \
    pageone.ui \
    homepage.ui

DISTFILES += \
    README.md \
    tutoQT/Dessiner.pdf \
    tutoQT/DémonstrationQt.pdf \
    tutoQT/Evénements-QEvent.pdf \
    tutoQT/IntroductionQt.pdf \
    tutoQT/Objets-SignalSlot.pdf \
    tutoQT/WidgetsEtAgencements.pdf \

RESOURCES += \
    ressources.qrc
