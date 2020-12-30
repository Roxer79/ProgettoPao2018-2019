#-------------------------------------------------
#
# Project created by QtCreator 2019-02-15T17:36:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto-PAO-2019-Videogame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    modello.cpp \
    Gerarchia/qontainer.cpp \
    GUI/menuprogetto.cpp \
    GUI/mainwindow.cpp \
    GUI/controller.cpp \
    GUI/layoutricerca.cpp \
    GUI/layoutinserisci.cpp \
    GUI/layoutinseriscigioconuovo.cpp \
    GUI/layoutinseriscivideogame.cpp \
    GUI/layoutinseriscicollertorsedition.cpp \
    GUI/layoutinseriscigiocousato.cpp \
    GUI/layoutinserisciphysical.cpp \
    GUI/layoutinseriscidigital.cpp \
    GUI/layoutinseriscidlc.cpp \
    GUI/layoutinseriscikey.cpp \
    GUI/fileeccezioniprintaschermo.cpp \
    GUI/videogameoggettilista.cpp \
    GUI/videogamewidgetlista.cpp \
    GUI/layoutricercaperoggetti.cpp \
    GUI/popupgenerico.cpp

HEADERS += \
    modello.h \
    Gerarchia/qontainer.h \
    GUI/menuprogetto.h \
    GUI/mainwindow.h \
    GUI/controller.h \
    GUI/layoutricerca.h \
    GUI/layoutinserisci.h \
    GUI/layoutinseriscigioconuovo.h \
    GUI/layoutinseriscivideogame.h \
    GUI/layoutinseriscigiocousato.h \
    GUI/layoutinseriscicollectorsedition.h \
    GUI/layoutinseriscikey.h \
    GUI/layoutinseriscidlc.h \
    GUI/layoutinserisciphysical.h \
    GUI/layoutinseriscidigital.h \
    Gerarchia/gerarchiavideogame.h \
    GUI/fileeccezioniprintaschermo.h \
    GUI/videogameoggettilista.h \
    GUI/videogamewidgetlista.h \
    GUI/layoutricercaperoggetti.h \
    GUI/popupgenerico.h

FORMS += \
    modello.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
