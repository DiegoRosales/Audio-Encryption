#ifndef CESARCIPHER_H
#define CESARCIPHER_H

#include <QtCore>
#include "wavfile.h"

int cCipher(int key, int plaintext);
int cDecipher(int key, int ciphertext);
bool cCipherAudio(int key, QString filenameIn, QString filenameOut, QString &error);
bool cDecipherAudio(int key, QString filenameIn, QString filenameOut, QString &error);
#endif // CESARCIPHER_H
