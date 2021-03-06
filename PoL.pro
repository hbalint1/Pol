#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T10:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PoL
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


SOURCES += main.cpp\
        mainwindow.cpp \
    Robot/robot.cpp \
    drawablearea.cpp \
    Model/model.cpp \
    Robot/robotsim.cpp \
    Protocol/protocol.cpp \
    Utils/utils.cpp \
    Protocol/protocolsim.cpp \
    Protocol/protocoltwogatherlight.cpp \
    Robot/robottwogatherlight.cpp

HEADERS  += mainwindow.h \
    Robot/robot.h \
    drawablearea.h \
    Model/model.h \
    Robot/robotsim.h \
    Protocol/protocol.h \
    Protocol/protocolsim.h \
    Protocol/protocoltwogatherlight.h \
    Robot/robottwogatherlight.h

FORMS    += mainwindow.ui
