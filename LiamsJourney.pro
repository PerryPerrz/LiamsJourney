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
    clickablelabel.cpp \
    pagetwo.cpp \
    utils.cpp \
    pagethree.cpp

HEADERS  += mainwindow.h \
    pageone.h \
    homepage.h \
    haptichandler.h \
    clickablelabel.h \
    pagetwo.h \
    utils.h \
    pagethree.h

FORMS    += mainwindow.ui \
    pageone.ui \
    homepage.ui \
    pagetwo.ui \
    pagethree.ui

DISTFILES += \
    README.md \
    tutoQT/Dessiner.pdf \
    tutoQT/D�monstrationQt.pdf \
    tutoQT/Ev�nements-QEvent.pdf \
    tutoQT/IntroductionQt.pdf \
    tutoQT/Objets-SignalSlot.pdf \
    tutoQT/WidgetsEtAgencements.pdf \

RESOURCES += \
    ressources.qrc
