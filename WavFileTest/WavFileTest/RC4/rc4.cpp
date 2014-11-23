#include "rc4.h"

RC4::RC4()
{
}

void RC4::keyScheduling(quint8 key[], quint8 keyLength, quint8 keySchedule[]){
    quint8 T[256];
    quint32 j = 0;
    for(int i=0; i<256; i++){
        keySchedule[i] = i;
        T[i] = key[i % keyLength];
    }

    for(int i=0; i<256; i++){
        j = (j + keySchedule[i] + T[i]) % 256;
        swap(keySchedule[i], keySchedule[j]);

    }
    for(int i=0; i<256; i++){
        //qDebug() << QString::number(keySchedule[i], 16);
    }
}

void RC4::swap(quint8 &x, quint8 &y){
    quint8 temp = x;
    x = y;
    y = temp;
}

void RC4::encrypt(quint8 keySchedule[], quint8 plaintext[], quint32 length, quint8 ciphertext[]){
    quint8 i=0, j=0;
    for(quint32 k=0; k<length; k++){
        i = (i+1)%256;
        j = (j+keySchedule[i])%256;
        swap(keySchedule[i], keySchedule[j]);
        ciphertext[k] = plaintext[k]^keySchedule[(keySchedule[i]+keySchedule[j])%256];
        //qDebug() << "Key = " << QString::number(keySchedule[keySchedule[i]+keySchedule[j]], 16);
        //qDebug() << QString::number(ciphertext[k], 16);
    }
}

void RC4::encrypt(quint8 keySchedule[], quint8 plaintext[], quint32 length, quint8 ciphertext[], quint8 &i, quint8 &j){
    //quint8 i=0, j=0;
    for(quint32 k=0; k<length; k++){
        i = (i+1)%256;
        j = (j+keySchedule[i])%256;
        swap(keySchedule[i], keySchedule[j]);
        ciphertext[k] = plaintext[k]^keySchedule[(keySchedule[i]+keySchedule[j])%256];
        //qDebug() << "Key = " << QString::number(keySchedule[keySchedule[i]+keySchedule[j]], 16);
        //qDebug() << QString::number(ciphertext[k], 16);
    }
}

void RC4::encryptDecrypt(quint8 key[], quint8 keyLength, quint8 dataIn[], quint32 dataInLength, quint8 dataOut[]){
    quint8 keySchedule[256];
    keyScheduling(key, keyLength, keySchedule);
    encrypt(keySchedule, dataIn, dataInLength, dataOut);
}
