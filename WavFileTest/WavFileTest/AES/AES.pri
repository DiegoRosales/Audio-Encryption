INCLUDEPATH += AES
DEPENDPATH += .\

DEPENDPATH += AES

HEADERS += AES/aes.h \
    $$PWD/aesdialog.h \
    $$PWD/aesaudio.h

SOURCES +=AES/aes.cpp \
    $$PWD/aesdialog.cpp \
    $$PWD/aesaudio.cpp

FORMS += \
    $$PWD/aesdialog.ui
