#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T12:52:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Excercise3
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    gun.cpp \
    target.cpp \
    shell.cpp

HEADERS  += mainwindow.h \
    gun.h \
    target.h \
    shell.h

FORMS    += mainwindow.ui
