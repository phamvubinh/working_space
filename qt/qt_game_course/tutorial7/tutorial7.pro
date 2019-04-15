#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T17:11:08
#
#-------------------------------------------------

QT       += core gui
QT       += mobility multimediakit
CONFIG   += mobility
MOBILITY = multimedia

TARGET = tutorial7
TEMPLATE = app


SOURCES += \
    main.cpp \
    Score.cpp \
    Player.cpp \
    Health.cpp \
    Game.cpp \
    Enemy.cpp \
    Bullet.cpp

HEADERS  += \
    Score.h \
    Player.h \
    Health.h \
    Game.h \
    Enemy.h \
    Bullet.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/QtMobility
INCLUDEPATH += /usr/include/QtMultimediaKit

RESOURCES += \
    res.qrc
