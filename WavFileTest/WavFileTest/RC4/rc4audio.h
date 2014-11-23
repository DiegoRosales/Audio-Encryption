#ifndef RC4AUDIO_H
#define RC4AUDIO_H
#include <QtCore>
#include "rc4.h"
#include "wavfile.h"

#define ECB 1
#define CBC 2
#define CFB 3

class RC4Audio: public QObject
{
    Q_OBJECT

public:
    RC4Audio();
    // Electronic Codebook
    bool CipherAudioECB(quint8 myKey[], quint8 keyLength, QString filenameIn,
                        QString filenameOut, QString &error);
    bool DecipherAudioECB(quint8 myKey[], quint8 keyLength, QString filenameIn,
                          QString filenameOut, QString &error);

    // Cipher Block Chaining
    bool CipherAudioCBC(quint8 myKey[], quint8 keyLength, quint8 initVector[],
                        quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCBC(quint8 myKey[], quint8 keyLength, quint8 initVector[],
                          quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error);

    // Cipher block Feedback
    bool CipherAudioCFB(quint8 myKey[], quint8 keyLength, quint8 initVector[],
                        quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCFB(quint8 myKey[], quint8 keyLength, quint8 initVector[],
                          quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error);

signals:
    void progressChange(int progress);
};

#endif // RC4AUDIO_H
