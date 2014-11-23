#include "rc4audio.h"

RC4Audio::RC4Audio()
{
}

bool RC4Audio::CipherAudioECB(quint8 myKey[], quint8 keyLength, QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting RC4 Cipher Encryption... ";
    qDebug() << "==========================================";
    RC4 myRC4;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint8 RC4Buffer[256], RC4Buffer2[256];

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

    quint8 keySchedule[256];
    myRC4.keyScheduling(myKey, keyLength, keySchedule);
    quint8 q=0;
    quint8 w=0;
    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int length;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; (h < 256) && (k < inputBuffer.newSamples); h++){
                RC4Buffer[h] = 0;
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                RC4Buffer[h] = inputBuffer.dataBuffer[k][h%x+y];
                temp = (h+1)%x;
                length = h;
            }
            length++;
            myRC4.encrypt(keySchedule, RC4Buffer, length, RC4Buffer2, q, w);
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<length; h++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][h%x+y] = RC4Buffer2[h];
                temp = (h+1)%x;
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
   qDebug() << "Finished RC4 Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}

bool RC4Audio::CipherAudioCBC(quint8 myKey[], quint8 keyLength, quint8 initVector[], quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting RC4 Cipher Encryption... ";
    qDebug() << "==========================================";
    RC4 myRC4;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint8 RC4Buffer[256], RC4Buffer2[256], vectTemp[256];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    for(int i=0; i<initVectorLength; i++)
        vectTemp[i] = initVector[i];

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int length;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; (h < 256) && (k < inputBuffer.newSamples); h++){
                RC4Buffer[h] = 0;
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                RC4Buffer[h] = inputBuffer.dataBuffer[k][h%x+y];
                temp = (h+1)%x;
                length = h;
            }
            length++;
            for(int h=0; h<length; h++)
                RC4Buffer[h] ^= vectTemp[h];
            myRC4.encryptDecrypt(myKey, keyLength, RC4Buffer, length, RC4Buffer2);
            for(int h=0; h<length; h++)
                vectTemp[h] = RC4Buffer2[h];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<length; h++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][h%x+y] = RC4Buffer2[h];
                temp = (h+1)%x;
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
   qDebug() << "Finished RC4 Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}

bool RC4Audio::DecipherAudioCBC(quint8 myKey[], quint8 keyLength, quint8 initVector[], quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting RC4 Cipher Decryption... ";
    qDebug() << "==========================================";
    RC4 myRC4;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint8 RC4Buffer[256], RC4Buffer2[256], vectTemp[256];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    for(int i=0; i<initVectorLength; i++)
        vectTemp[i] = initVector[i];

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int length;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; (h < 256) && (k < inputBuffer.newSamples); h++){
                RC4Buffer[h] = 0;
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                RC4Buffer[h] = inputBuffer.dataBuffer[k][h%x+y];
                temp = (h+1)%x;
                length = h;
            }
            length++;
            quint8 vectTemp2[256];
            for(int h=0; h<length; h++)
                vectTemp2[h] = RC4Buffer[h];

            myRC4.encryptDecrypt(myKey, keyLength, RC4Buffer, length, RC4Buffer2);
            for(int h=0; h<length; h++)
                RC4Buffer2[h] ^= vectTemp[h];
            for(int h=0; h<length; h++)
                vectTemp[h] = vectTemp2[h];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<length; h++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][h%x+y] = RC4Buffer2[h];
                temp = (h+1)%x;
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
   qDebug() << "Finished RC4 Cipher Decryption";
   qDebug() << "==========================================";
   return true;
}

bool RC4Audio::CipherAudioCFB(quint8 myKey[], quint8 keyLength, quint8 initVector[], quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting RC4 Cipher Encryption... ";
    qDebug() << "==========================================";
    RC4 myRC4;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint8 RC4Buffer[256], RC4Buffer2[256], vectTemp[256];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    for(int i=0; i<initVectorLength; i++)
        vectTemp[i] = initVector[i];

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int length;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; (h < 256) && (k < inputBuffer.newSamples); h++){
                RC4Buffer[h] = 0;
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                RC4Buffer[h] = inputBuffer.dataBuffer[k][h%x+y];
                temp = (h+1)%x;
                length = h;
            }
            length++;
            myRC4.encryptDecrypt(myKey, keyLength, vectTemp, length, RC4Buffer2);
            for(int h=0; h<length; h++){
                RC4Buffer2[h] ^= RC4Buffer[h];
                vectTemp[h] = RC4Buffer2[h];
            }
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<length; h++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][h%x+y] = RC4Buffer2[h];
                temp = (h+1)%x;
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
   qDebug() << "Finished RC4 Cipher Encryption";
   qDebug() << "==========================================";
   return true;
}

bool RC4Audio::DecipherAudioCFB(quint8 myKey[], quint8 keyLength, quint8 initVector[], quint8 initVectorLength, QString filenameIn, QString filenameOut, QString &error)
{
    qDebug() << "==========================================";
    qDebug() << "Starting RC4 Cipher Decryption... ";
    qDebug() << "==========================================";
    RC4 myRC4;
    int x, y;

    // Wav Variables
    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;
    quint8 RC4Buffer[256], RC4Buffer2[256], vectTemp[256];

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    for(int i=0; i<initVectorLength; i++)
        vectTemp[i] = initVector[i];

    x = (parameters.bitsPerSample*parameters.channelCount)/8;
    y = 4 - parameters.bitsPerSample/8;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            int k = i;
            int length;
            int temp = 1;
            // Fills the AES buffer with the Wav buffer
            for(int h = 0; (h < 256) && (k < inputBuffer.newSamples); h++){
                RC4Buffer[h] = 0;
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                RC4Buffer[h] = inputBuffer.dataBuffer[k][h%x+y];
                temp = (h+1)%x;
                length = h;
            }
            length++;
            quint8 vectTemp2[256];

            myRC4.encryptDecrypt(myKey, keyLength, vectTemp, length, vectTemp2);
            for(int h=0; h<length; h++)
                RC4Buffer2[h] = RC4Buffer[h] ^ vectTemp2[h];
            for(int h=0; h<length; h++)
                vectTemp[h] = RC4Buffer[h];
            k = i;
            temp = 1;
            // Fills the Wav buffer with the encryption data
            for(int h=0; h<length; h++){
                if(((parameters.channelCount == 2)&&(temp == 0) && (h != 1)) || ((parameters.channelCount == 1)&&(temp == 0))) k++;
                outputBuffer.dataBuffer[k][h%x+y] = RC4Buffer2[h];
                temp = (h+1)%x;
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
   qDebug() << "Finished RC4 Cipher Decryption";
   qDebug() << "==========================================";
   return true;
}
