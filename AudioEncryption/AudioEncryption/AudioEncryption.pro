#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T16:38:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioEncryption
TEMPLATE = app

include(Wave/Wave.pri)
include(CesarCipher/CesarCipher.pri)
include(VigenereCipher/VigenereCipher.pri)
include(DES/DES.pri)
include(AES/AES.pri)
include(RC4/RC4.pri)


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \

FORMS    += mainwindow.ui \

