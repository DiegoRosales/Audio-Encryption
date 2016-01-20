INCLUDEPATH += CesarCipher
DEPENDPATH += .\

DEPENDPATH += CesarCipher

SOURCES += CesarCipher/CesarCipher.cpp \
    $$PWD/cesardialog.cpp

HEADERS += CesarCipher/CesarCipher.h \
    $$PWD/cesardialog.h

FORMS += \
    $$PWD/cesardialog.ui
