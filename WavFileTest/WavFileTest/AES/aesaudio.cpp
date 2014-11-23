#include "aesaudio.h"

aesAudio::aesAudio(){

}

bool aesAudio::CipherAudioECB(quint8 myKey[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Encryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            myAES.encrypt(roundKeys, AESBuffer, AESBuffer2);
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}

bool aesAudio::DecipherAudioECB(quint8 myKey[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Decryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);
    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            myAES.decrypt(roundKeys, AESBuffer, AESBuffer2);
            k = i;
            temp = 1;
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Decryption";
   qDebug() << "==========================================";
   return true;
}

bool aesAudio::CipherAudioCBC(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Encryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    // CBC Variables
    quint32 vectTemp[4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);
    for(int i=0; i<4; i++)
        vectTemp[i] = initVector[i];

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            // CBC
            for(int j=0; j<4; j++)
                AESBuffer[j] ^= vectTemp[j];
            myAES.encrypt(roundKeys, AESBuffer, AESBuffer2);
            // CBC
            for(int j=0; j<4; j++)
                vectTemp[j] = AESBuffer2[j];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}


bool aesAudio::DecipherAudioCBC(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Decryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    // CBC Variables
    quint32 vectTemp[4], vectTemp2[4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);
    for(int i=0; i<4; i++)
        vectTemp[i] = initVector[i];

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            // CBC
            for(int j=0; j<4; j++)
                vectTemp2[j] = AESBuffer[j];
            myAES.decrypt(roundKeys, AESBuffer, AESBuffer2);
            // CBC
            for(int j=0; j<4; j++)
                AESBuffer2[j] ^= vectTemp[j];
            for(int j=0; j<4; j++)
                vectTemp[j] = vectTemp2[j];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Decryption";
   qDebug() << "==========================================";
   return true;
}

bool aesAudio::CipherAudioCBF(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Encryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    // CBC Variables
    quint32 vectTemp[4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);
    for(int i=0; i<4; i++)
        vectTemp[i] = initVector[i];

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            myAES.encrypt(roundKeys, vectTemp, AESBuffer2);
            // CBC
            for(int j=0; j<4; j++)
                AESBuffer2[j] ^= AESBuffer[j];
            for(int j=0; j<4; j++)
                vectTemp[j] = AESBuffer2[j];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}

bool aesAudio::DecipherAudioCBF(quint8 myKey[], quint32 initVector[], QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting AES Cipher Decryption... ";
    qDebug() << "==========================================";
    AES myAES;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint32 AESBuffer[4], AESBuffer2[4];

    // Key Variables
    quint32 roundKeys[10][4];

    // CBC Variables
    quint32 vectTemp[4], vectTemp2[4];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    myAES.keyExpansion(myKey, roundKeys);
    for(int i=0; i<4; i++)
        vectTemp[i] = initVector[i];

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; h < 4; h++){
                AESBuffer[h] = 0;
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    AESBuffer[h] |= inputBuffer.dataBuffer[k][j%x+y];

                    if(j<3)
                        AESBuffer[h] <<= 8;
                    temp = (j+1)%x;
                }
            }
            myAES.encrypt(roundKeys, vectTemp, vectTemp2);
            // CFB
            for(int j=0; j<4; j++)
                AESBuffer2[j] = AESBuffer[j] ^ vectTemp2[j];
            for(int j=0; j<4; j++)
                vectTemp[j] = AESBuffer[j];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<4; h++){
                for(int j=0; j<4; j++){
                    if(((parameters.channelCount == 2)&&(temp == 0) && (j != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                    outputBuffer.dataBuffer[k][j%x+y] = 0xFF & (AESBuffer2[h]>>(8*(3-j)));
                    //if(j<7)
                        //DESBuffer <<= 8;
                    temp = (j+1)%x;
                }
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
   qDebug() << "Finished AES Cipher Decryption";
   qDebug() << "==========================================";
   return true;
}
