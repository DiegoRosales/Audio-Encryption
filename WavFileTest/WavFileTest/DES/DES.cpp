#include "DES.h"

DES::DES()
{
    int PC1_Init[56] = {
                57, 49, 41, 33, 25, 17, 9,
                1, 58, 50, 42, 34, 26, 18,
                10, 2, 59, 51, 43, 35, 27,
                19, 11, 3, 60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7, 62, 54, 46, 38, 30, 22,
                14, 6, 61, 53, 45, 37, 29,
                21, 13, 5, 28, 20, 12, 4};

    int PC2_Init[56] = {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32};

    int IP_Init[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7};

    int Ebit_Init [48] = {
        32, 1, 2, 3, 4, 5,
        4, 5, 6, 7, 8, 9,
        8, 9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1,};

    int P_Init [32] = {
        16, 7, 20, 21,
        29, 12, 28, 17,
        1, 15, 23, 26,
        5, 18, 31, 10,
        2, 8, 24, 14,
        32, 27, 3, 9,
        19, 13, 30, 6,
        22, 11, 4, 25};

    int IIP_Init [64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25};

    int SBox_Init [8][4][16] = {
        // S1
        {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
        // S2
        {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
         {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
         {0, 14, 7, 11, 10, 4,  13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
         {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
        // S3
        {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
         {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
         {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
         {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
        // S4
        {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
         {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
         {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
         {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
        // S5
        {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
         {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
         {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
         {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
        // S6
        {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
         {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
         {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
         {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
        // S7
        {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
         {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
         {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
         {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
        // S8
        {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
         {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
         {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
         {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}},
    };


    for(int i=0; i<56; i++){
        PC1[i] = PC1_Init[i];
        PC2[i] = PC2_Init[i];
    }
    for(int i=0; i<64; i++){
        IP[i] = IP_Init[i];
    }
    for(int i=0; i<48; i++){
        Ebit[i] = Ebit_Init[i];
    }
    for(int i=0; i<32; i++){
        P[i] = P_Init[i];
    }
    for(int i=0; i<64; i++){
        IIP[i] = IIP_Init[i];
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<16; k++){
                SBox[i][j][k] = SBox_Init[i][j][k];
            }
        }
    }
}

// *********** KEY ************ //

// Step 1.1 - Initial permutation and key split
void DES::permutedChoice1(quint64 data, quint32 &Cx, quint32 &Dx){
    quint64 newKey = 0;
    for(int i=0; i<56; i++){
        int x = 64-PC1[i];
        newKey |= ((data&((quint64)1<<(quint64)(x))) != 0);
        if(i < 55)
            newKey <<= 1;
    }
    Cx = 0xFFFFFFF&(newKey>>28);
    Dx = 0xFFFFFFF&newKey;
}

// Step 1.2 - Circular left shift
void DES::leftShift(quint32 &Cx, quint32 &Dx, int iteration){
    switch(iteration){
    case 1:
    case 2:
    case 9:
    case 16:
        Cx <<= 1;
        Cx = ((Cx&0x1FFFFFFE) | Cx>>27)&0xFFFFFFF;

        Dx <<= 1;
        Dx = ((Dx&0x1FFFFFFE) | Dx>>28)&0xFFFFFFF;
        break;
        break;

    default :
        Cx <<= 2;
        Cx = ((Cx&0x3FFFFFFC) | Cx>>28)&0xFFFFFFF;

        Dx <<= 2;
        Dx = ((Dx&0x3FFFFFFC) | Dx>>28)&0xFFFFFFF;
        break;
    }
}

void DES::rightShift(quint32 &Cx, quint32 &Dx, int iteration){
    switch(iteration){
    case 1:
    case 2:
    case 9:
    case 16:
        Cx >>= 1;
        Cx = ((Cx&0x7FFFFFF) | Cx<<27)&0xFFFFFFF;

        Dx <<= 1;
        Dx = ((Dx&0x7FFFFFF) | Dx<<27)&0xFFFFFFF;
        break;
        break;

    default :
        Cx >>= 2;
        Cx = ((Cx&0x3FFFFFF) | Cx<<27)&0xFFFFFFF;

        Dx >>= 2;
        Dx = ((Dx&0x3FFFFFFC) | Dx<<27)&0xFFFFFFF;
        break;
    }
}

// Step 1.3
quint64 DES::permutedChoice2(quint32 Cx, quint32 Dx){
    quint64 keyTemp = ((quint64)Cx<<28)|(quint64)Dx;
    quint64 currentKey = 0;
    for(int i=0; i<48; i++){
       int x = 64-8-PC2[i];
       currentKey |= ((keyTemp&((quint64)1<<x)) != 0);
       if(i < 47){
           currentKey = currentKey << 1;
       }
    }
    return currentKey;
}

// *********** DATA ************ //

// Step 2.1 - Initial permutation
quint64 DES::initialPermutation(quint64 data){
    quint64 newPlaintext = 0;
    for(int i=0; i<64; i++){
        int x = 64-IP[i];
        newPlaintext |= ((data&((quint64)1<<(quint64)(x))) != 0);
        if(i < 63)
            newPlaintext <<= 1;
    }
    return newPlaintext;
}

// Step 2.2
void DES::separateLR(quint64 data, quint32 &L, quint32 &R){
    L = 0xFFFFFFFF&(data>>32);
    R = 0xFFFFFFFF&data;
}

// Step 2.3 - Perform the permutation/expansion process
quint64 DES::permutationExpansion(quint32 data){
    quint64 R48 = 0;
    for(int i=0; i<48; i++){
        int x = 64-32-Ebit[i];
        R48 |= ((data&((quint64)1<<x)) != 0);

        if(i < 47){
            R48 = R48 << 1;
        }
    }
    return R48;
}

// Step 2.4 - Perform the substitution process (S-Box)
quint32 DES::sBox(quint64 data){
    int index1, index2;
    int currentR = 0;
    quint8 byteTemp;
    for(int i=7; i>=0; i--){
        byteTemp = 0x3F&(data>>(i*6));
        index1 = (1&byteTemp) | (2&((byteTemp>>4)));
        index2 = 0xF&(byteTemp>>1);
        currentR |= SBox[7-i][index1][index2];
        if(i>0)
            currentR <<= 4;
    }
    return currentR;
}

// Step 2.5 - Perform the final permutation
quint32 DES::finalPermutation(quint32 data){
    quint32 R_temp = 0;
    for(int i=0; i<32; i++){
        int x = 32 - P[i];
        R_temp |= (data&(1<<x)) != 0;
        if(i < 31)
            R_temp <<= 1;
    }
    return R_temp;
}

// Step 2.6 - Inverse Initial Permutation
quint64 DES::inverseInitialPermutation(quint32 L, quint32 R){
    quint64 ciphertext_temp = ((quint64)R<<32)|L;
    quint64 ciphertext = 0;
    for(int i=0; i<64; i++){
        int x = 64 - IIP[i];
        ciphertext |= (quint64)(ciphertext_temp&((quint64)1<<x)) != 0;
        if(i<63)
            ciphertext <<= 1;
    }

    return ciphertext;
}

void DES::keySchedule(quint64 key, quint64 keyVector[16], bool encryptDecrypt){
    //quint64 keyTemp;
    quint32 Cx, Dx;

    for(int i=0; i<16; i++){
        // This is performed only once
        if(i == 0){
           permutedChoice1(key, Cx, Dx);
           //qDebug() << "C0 = " << QString("%1").arg(Cx, 28, 2, QChar('0'));
           //qDebug() << "D0 = " << QString("%1").arg(Dx, 28, 2, QChar('0'));
        }
        if(encryptDecrypt == ENCRYPT)
            leftShift(Cx, Dx, i+1);
        else
            rightShift(Cx, Dx, i+1);
        //qDebug() << "C" << i << " = " << QString("%1").arg(Cx, 28, 2, QChar('0'));
        //qDebug() << "D" << i << " = " << QString("%1").arg(Dx, 28, 2, QChar('0'));
        keyVector[i] = permutedChoice2(Cx, Dx);
        //qDebug() << "Key "<< i << " = " << QString("%1").arg(keyVector[i], 48, 2, QChar('0'));
        //qDebug() << "----------------------------";
    }
}

quint32 DES::mangler(quint32 R, quint64 key){
    quint64 R48;
    quint32 Rtemp;

    R48 = permutationExpansion(R);
    R48 ^= key;
    Rtemp = sBox(R48);
    Rtemp = finalPermutation(Rtemp);
    return Rtemp;
}

quint64 DES::encrypt(quint64 key, quint64 plaintext){
    quint64 keyVector[16];
    quint64 ciphertext;
    quint32 L, R, Rtemp;
    keySchedule(key, keyVector, ENCRYPT);
    for(int i=0; i<16; i++){
        if(i==0){
            ciphertext = initialPermutation(plaintext);
            separateLR(ciphertext, L, R);
        }
        Rtemp = mangler(R, keyVector[i]);
        Rtemp ^= L;
        L = R;
        R = Rtemp;
    }
    ciphertext = inverseInitialPermutation(L, R);
    return ciphertext;
}

quint64 DES::encrypt(quint64 keyVector[16], quint64 plaintext){
    quint64 ciphertext;
    quint32 L, R, Rtemp;
    for(int i=0; i<16; i++){
        if(i==0){
            ciphertext = initialPermutation(plaintext);
            separateLR(ciphertext, L, R);
        }
        Rtemp = mangler(R, keyVector[i]);
        Rtemp ^= L;
        L = R;
        R = Rtemp;
    }
    ciphertext = inverseInitialPermutation(L, R);
    return ciphertext;
}

quint64 DES::decrypt(quint64 key, quint64 ciphertext){
    quint64 keyVector[16];
    quint64 plaintext;
    quint32 L, R, Rtemp;
    keySchedule(key, keyVector, ENCRYPT);
    for(int i=0; i<16; i++){
        if(i==0){
            plaintext = initialPermutation(ciphertext);
            separateLR(plaintext, L, R);
        }
        Rtemp = mangler(R, keyVector[15-i]);
        Rtemp = L ^ Rtemp;
        L = R;
        R = Rtemp;
    }
    plaintext = inverseInitialPermutation(L, R);
    return plaintext;
}

quint64 DES::decrypt(quint64 keyVector[16], quint64 ciphertext){
    quint64 plaintext;
    quint32 L, R, Rtemp;
    for(int i=0; i<16; i++){
        if(i==0){
            plaintext = initialPermutation(ciphertext);
            separateLR(plaintext, L, R);
        }
        Rtemp = mangler(R, keyVector[15-i]);
        Rtemp = L ^ Rtemp;
        L = R;
        R = Rtemp;
    }
    plaintext = inverseInitialPermutation(L, R);
    return plaintext;
}


bool DES::CipherAudioECB(quint64 myKey, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Encryption... ";
    qDebug() << "==========================================";
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;

    // DES Variables
    quint64 DESBuffer;
    quint64 keyVector[16];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    keySchedule(myKey, keyVector, ENCRYPT);
    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            DESBuffer = encrypt(keyVector, DESBuffer);
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            i = k;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }
   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Encryption";
   qDebug() << "==========================================";
   return true;

}

bool DES::DecipherAudioECB(quint64 myKey, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Decryption... ";
    qDebug() << "==========================================";

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;

    // DES Variables
    quint64 DESBuffer;
    quint64 keyVector[16];


    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    keySchedule(myKey, keyVector, ENCRYPT);
    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    int x = (parameters.bitsPerSample*parameters.channelCount)/8;
    int y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){

        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            DESBuffer = decrypt(keyVector, DESBuffer);
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer >>= 8;
                temp = (j+1)%x;
            }
            i += k-i;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }

   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Decryption";
   qDebug() << "==========================================";
   return true;

}
//-----------------------
// Cipher Block Chaining
//-----------------------
bool DES::CipherAudioCBC(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Encryption... ";
    qDebug() << "==========================================";
    int x, y;
    quint64 vectTemp = initVector;
    // WAV buffers
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    // DES Temporal buffer
    quint64 DESBuffer;
    // WAV parameters
    wavParameters parameters;
    //hasKey = false;
    // Reads and writes WAV files
    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            DESBuffer ^= vectTemp;
            DESBuffer = encrypt(myKey, DESBuffer);
            vectTemp = DESBuffer;
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            i = k;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }
   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Encryption";
   qDebug() << "==========================================";
   return true;

}

bool DES::DecipherAudioCBC(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Decryption... ";
    qDebug() << "==========================================";

    quint64 vectTemp = initVector, bufferTemp;
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    quint64 DESBuffer;
    wavParameters parameters;
    //hasKey = false;
    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    int x = (parameters.bitsPerSample*parameters.channelCount)/8;
    int y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){

        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            bufferTemp = DESBuffer;
            DESBuffer = decrypt(myKey, DESBuffer);
            DESBuffer ^= vectTemp;
            vectTemp = bufferTemp;
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer >>= 8;
                temp = (j+1)%x;
            }
            i += k-i;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }

   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Decryption";
   qDebug() << "==========================================";
   return true;

}

//-----------------------
// Cipher Feedback
//-----------------------

bool DES::CipherAudioCFB(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Encryption... ";
    qDebug() << "==========================================";
    int x, y;
    quint64 vectTemp = initVector;
    // WAV buffers
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    // DES Temporal buffer
    quint64 DESBuffer;
    // WAV parameters
    wavParameters parameters;
    //hasKey = false;
    // Reads and writes WAV files
    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }

            vectTemp = encrypt(myKey, vectTemp);
            DESBuffer ^= vectTemp;
            vectTemp = DESBuffer;
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            i = k;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }
   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Encryption";
   qDebug() << "==========================================";
   return true;

}

bool DES::DecipherAudioCFB(quint64 myKey, quint64 initVector, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting DES Cipher Decryption... ";
    qDebug() << "==========================================";

    quint64 vectTemp = initVector, bufferTemp;
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    quint64 DESBuffer;
    wavParameters parameters;
    //hasKey = false;
    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    int x = (parameters.bitsPerSample*parameters.channelCount)/8;
    int y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){

        for(int i=0; i<inputBuffer.newSamples; i++){
            DESBuffer = 0;
            int k = i;
            int temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                DESBuffer |= inputBuffer.dataBuffer[k][j%x+y];

                if(j<7)
                    DESBuffer <<= 8;
                temp = (j+1)%x;
            }
            bufferTemp = encrypt(myKey, vectTemp);
            vectTemp = DESBuffer;
            DESBuffer ^= bufferTemp;
            k = i;
            temp = 1;
            for(int j=0; j<8; j++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (DESBuffer>>(8*(7-j)));
                //if(j<7)
                    //DESBuffer >>= 8;
                temp = (j+1)%x;
            }
            i += k-i;

        }
        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = outputBuffer.dataOffset*parameters.channelCount*(parameters.bitsPerSample/8)*100 / inputBuffer.chunkSize;
        emit progressChange(progress);
   }

   parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
   parameters.filesize = parameters.dataSize + 0x24;
   cipherAudio.setSizes(parameters);
   cipherAudio.closeFile();
   qDebug() << "==========================================";
   qDebug() << "Finished DES Cipher Decryption";
   qDebug() << "==========================================";
   return true;

}
