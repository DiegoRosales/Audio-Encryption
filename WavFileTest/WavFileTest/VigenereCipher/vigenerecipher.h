#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <QString>
#include <QtCore>
#include "wavfile.h"

class vigenereCipher : public QObject{
Q_OBJECT

public:
    void vCipher(QString key, quint8 inputBuffer[][8], int size, quint8 outputBuffer[][8]);
    bool vCipherAudio(QString key, QString filenameIn, QString filenameOut, QString &error);
    bool vDecipherAudio(QString key, QString filenameIn, QString filenameOut, QString &error);
signals:
    void progressChange(int progress);
};


#endif // VIGENERECIPHER_H
