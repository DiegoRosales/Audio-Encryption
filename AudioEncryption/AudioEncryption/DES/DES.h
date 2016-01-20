#ifndef DES_H
#define DES_H
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "wavfile.h"

#define ENCRYPT true
#define DECRYPT false

class DES : public QObject{
    Q_OBJECT

    int PC1[56], PC2[56], IP[64], Ebit[48], P[32], IIP[64];
    int SBox[8][4][16];

public:
    DES();
    void keySchedule(quint64 key, quint64 keyVector[16], bool encryptDecrypt);
    quint32 mangler(quint32 R, quint64 key);
    quint64 encrypt(quint64 key, quint64 plaintext);
    quint64 encrypt(quint64 keyVector[16], quint64 plaintext);
    quint64 decrypt(quint64 key, quint64 ciphertext);
    quint64 decrypt(quint64 keyVector[16], quint64 ciphertext);
    bool CipherAudioECB(quint64 myKey, QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioECB(quint64 myKey, QString filenameIn, QString filenameOut, QString &error);
    bool CipherAudioCBC(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCBC(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error);
    bool CipherAudioCFB(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error);
    bool DecipherAudioCFB(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error);


private:
    // Keys
    void permutedChoice1(quint64 data, quint32 &Cx, quint32 &Dx); // Step 1.1
    void leftShift(quint32 &Cx, quint32 &Dx, int iteration); // Step 1.2
    void rightShift(quint32 &Cx, quint32 &Dx, int iteration);
    quint64 permutedChoice2(quint32 Cx, quint32 Dx); // Step 1.3

    // Data
    quint64 initialPermutation(quint64 data); // Step 2.1
    void separateLR(quint64 data, quint32 &L, quint32 &R); // Step 2.2
    quint64 permutationExpansion(quint32 data); // Step 2.3
    quint32 sBox(quint64 data); // Step 2.4
    quint32 finalPermutation(quint32 data); // Step 2.5
    quint64 inverseInitialPermutation(quint32 L, quint32 R); // Step 2.6


signals:
    void progressChange(int progress);
};

#endif // DES_H
