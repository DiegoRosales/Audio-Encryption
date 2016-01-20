#ifndef RC4_H
#define RC4_H
#include <QtCore>
#include <qstring.h>


class RC4
{
public:
    RC4();
    static void encrypt(quint8 keySchedule[], quint8 plaintext[], quint32 length, quint8 ciphertext[]);
    static void encrypt(quint8 keySchedule[], quint8 plaintext[], quint32 length, quint8 ciphertext[], quint8 &i, quint8 &j);
    static void encryptDecrypt(quint8 key[], quint8 keyLength, quint8 dataIn[], quint32 dataInLength, quint8 dataOut[]);
    static void keyScheduling(quint8 key[], quint8 keyLength, quint8 keySchedule[]);

private:
    static void swap(quint8 &x, quint8 &y);
};

#endif // RC4_H
