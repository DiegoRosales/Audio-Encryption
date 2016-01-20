INCLUDEPATH += Wave\
DEPENDPATH += .\

DEPENDPATH += Wave

SOURCES += Wave/wavRead.cpp\
            Wave/wavinfodialog.cpp\
            Wave/wavwrite.cpp\
            Wave/wavebuffer.cpp \
    $$PWD/wavparameters.cpp

HEADERS += Wave/wavfile.h\
            Wave/wavinfodialog.h

FORMS += Wave/wavinfodialog.ui
