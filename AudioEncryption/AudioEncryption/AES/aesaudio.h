#ifndef AESAUDIO_H
#define AESAUDIO_H
#include <QtCore>
#include <QObject>
#include "aes.h"
#include "wavfile.h"

class aesAudio : public QObject
{
    Q_OBJECT
public:
    aesAudio();
    // Electronic Codebook
    bool CipherAudioECB(quint8 myKey[], QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioECB(quint8 myKey[], QString filenameIn, QString filenameOut, QString &error);

    // Cipher Block Chaining
    bool CipherAudioCBC(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCBC(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error);

    // Cipher block Feedback
    bool CipherAudioCBF(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCBF(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error);

signals:
    void progressChange(int progress);
};

#endif // AESAUDIO_H
