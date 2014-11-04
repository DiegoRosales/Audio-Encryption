#-------------------------------------------------
#
# Project created by QtCreator 2014-09-21T17:42:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WavFileTest
TEMPLATE = app

include(Wave/Wave.pri)
include(CesarCipher/CesarCipher.pri)
include(VigenereCipher/VigenereCipher.pri)
include(DES/DES.pri)
include(AES/AES.pri)


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \

FORMS    += mainwindow.ui \

