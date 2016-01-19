#include "CesarCipher.h"
#include "wavfile.h"
#include "iostream"

int cCipher(int key, int plaintext){
    return key + plaintext;
}

int cDecipher(int key, int ciphertext){
    return key - ciphertext;
}

bool cCipherAudio(int key, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting Caesar Cipher Encryption... ";
    qDebug() << "==========================================";

    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;

    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            for(int j=0; j<8; j++)
                outputBuffer.dataBuffer[i][j] = inputBuffer.dataBuffer[i][j] + key;
        }

        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
   }
    parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
    parameters.filesize = parameters.dataSize + 0x24;
    cipherAudio.setSizes(parameters);
    cipherAudio.closeFile();
    qDebug() << "==========================================";
    qDebug() << "Finished Caesar Cipher Encryption";
    qDebug() << "==========================================";
    return true;
}

bool cDecipherAudio(int key, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting Caesar Cipher Decryption... ";
    qDebug() << "==========================================";

    wavBuffer inputBuffer;
    wavBuffer outputBuffer;
    wavParameters parameters;

    wavRead plainAudio(filenameIn, parameters);
    if(plainAudio.getReadError(error))
        return false;
    wavWrite cipherAudio(filenameOut, parameters);
    if(cipherAudio.getWriteError(error))
        return false;
    outputBuffer.resolution = parameters.bitsPerSample;
    outputBuffer.stereoMono = parameters.channelCount;

    while(plainAudio.getData(inputBuffer)){
        for(int i=0; i<inputBuffer.newSamples; i++){
            for(int j=0; j<8; j++)
                outputBuffer.dataBuffer[i][j] = inputBuffer.dataBuffer[i][j] - key;
        }

        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
   }
    parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
    parameters.filesize = parameters.dataSize + 0x24;
    cipherAudio.setSizes(parameters);
    cipherAudio.closeFile();
    qDebug() << "==========================================";
    qDebug() << "Finished Caesar Cipher Decryption";
    qDebug() << "==========================================";
    return true;
}
