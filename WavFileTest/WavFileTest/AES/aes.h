#ifndef AES_H
#define AES_H
#include <QtCore>


class AES
{
    quint8 SBox[16][16];
    quint8 InverseSBox[16][16];
    quint8 MixColumn[4][4];
    quint8 InverseMixColumn[4][4];
    quint8 InvMultLUT[4][256];
    quint8 MultLUT[2][256];
public:
    AES();
    void encrypt(quint8 key[16], quint32 data[4], quint32 ciphertext[4]);
    void encrypt(quint32 roundKeys[10][4], quint32 data[4], quint32 ciphertext[4]);
    void decrypt(quint8 key[16], quint32 data[4], quint32 plaintext[4]);
    void decrypt(quint32 roundKeys[10][4], quint32 data[4], quint32 plaintext[4]);
    void keyExpansion(quint8 key[16], quint32 roundKeys[10][4]);

private:
    // Key functions
    quint32 rotWord(quint32 data);
    quint32 sBox(quint32 data);
    quint32 inverseSBox(quint32 data);

    // Data Functions
    // Encryption
    void subBytes(quint32 data[4]); // Step 1
    void shiftRows(quint32 data[4]); // Step 2 (Encryption and Decryption)
    void mixColumns(quint32 data[4]); // Step 3
    void addRoundKey(quint32 data[4], quint32 roundKey[4]); // Step 4
    // Decryption
    void inverseShiftRows(quint32 data[4]); // Step 1
    void inverseSubBytes(quint32 data[4]); // Step 3
    void inverseMixColumns(quint32 data[4]); // Step 4

    // Misc
    quint8 gmul(quint8 b, quint8 a);
    quint8 gmulInv(quint8 a, quint8 b);
};

#endif // AES_H
