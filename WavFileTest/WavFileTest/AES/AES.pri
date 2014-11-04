INCLUDEPATH += AES
DEPENDPATH += .\

DEPENDPATH += AES

HEADERS += AES/aes.h \
    $$PWD/aesdialog.h

SOURCES +=AES/aes.cpp \
    $$PWD/aesdialog.cpp

FORMS += \
    $$PWD/aesdialog.ui
