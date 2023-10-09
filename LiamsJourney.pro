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
    gestionhaptique.cpp \
    pageone.cpp \
    homepage.cpp

HEADERS  += mainwindow.h \
    gestionhaptique.h \
    pageone.h \
    homepage.h

FORMS    += mainwindow.ui \
    pageone.ui \
    homepage.ui

DISTFILES += \
    README.md \
    ressources/effects/vibreur.ifr \
    tutoQT/Dessiner.pdf \
    tutoQT/D�monstrationQt.pdf \
    tutoQT/Ev�nements-QEvent.pdf \
    tutoQT/IntroductionQt.pdf \
    tutoQT/Objets-SignalSlot.pdf \
    tutoQT/WidgetsEtAgencements.pdf \
    ressources/images/home_image.jpg

RESOURCES += \
