INCLUDEPATH += DES
DEPENDPATH += .\

DEPENDPATH += DES

SOURCES += DES/DES.cpp \
    $$PWD/desdialog.cpp \
    $$PWD/codedialog.cpp

HEADERS += DES/DES.h \
    $$PWD/desdialog.h \
    $$PWD/codedialog.h

FORMS += \
    $$PWD/desdialog.ui \
    $$PWD/codedialog.ui
