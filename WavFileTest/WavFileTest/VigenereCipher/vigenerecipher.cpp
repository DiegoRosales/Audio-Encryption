#include "vigenerecipher.h"

void vigenereCipher::vCipher(QString key, quint8 inputBuffer[][8], int size, quint8 outputBuffer[][8]){
    int j=0;
    for(int i=0; i<size; i++){
        outputBuffer[i][3] = inputBuffer[i][3] + key[j].unicode();
        if(j >= key.length()-1)
            j=0;
        else
            j++;
    }
}

/**
 * Vigenere Cipher for Audio
 */
bool vigenereCipher::vCipherAudio(QString key, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting Vigènere Cipher Encryption... ";
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
    outputBuffer.chunkSize = parameters.dataSize;

    while(plainAudio.getData(inputBuffer)){
        int k = 0;
        for(int i=0; i<inputBuffer.newSamples; i++){
            for(int j=0; j<8; j++){
                outputBuffer.dataBuffer[i][j] = inputBuffer.dataBuffer[i][j] + key[i%key.length()].unicode();
            }
//            if(k >= key.length()-1)
//                k=0;
//            else
//                k++;
        }

        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = (outputBuffer.dataOffset*100*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8))/outputBuffer.chunkSize;
        emit progressChange(progress);
    }
    parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
    parameters.filesize = parameters.dataSize + 0x24;
    cipherAudio.setSizes(parameters);
    cipherAudio.closeFile();

    qDebug() << "==========================================";
    qDebug() << "Finished Vigènere Cipher Encryption!";
    qDebug() << "==========================================";

}

bool vigenereCipher::vDecipherAudio(QString key, QString filenameIn, QString filenameOut, QString &error){
    qDebug() << "==========================================";
    qDebug() << "Starting Vigènere Cipher Decryption... ";
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
    outputBuffer.chunkSize = parameters.dataSize;

    while(plainAudio.getData(inputBuffer)){
        int k = 0;
        for(int i=0; i<inputBuffer.newSamples; i++){
            for(int j=0; j<8; j++){
                outputBuffer.dataBuffer[i][j] = inputBuffer.dataBuffer[i][j] - key[k].unicode();
            }
            if(k >= key.length()-1)
                k=0;
            else
                k++;
        }

        outputBuffer.newSamples = inputBuffer.newSamples;
        outputBuffer.dataOffset += outputBuffer.newSamples;
        cipherAudio.writeBuffer(outputBuffer);
        int progress = (outputBuffer.dataOffset*100*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8))/outputBuffer.chunkSize;
        emit progressChange(progress);
    }
    parameters.dataSize = outputBuffer.dataOffset*outputBuffer.stereoMono*floor((float)outputBuffer.resolution/(float)8);
    parameters.filesize = parameters.dataSize + 0x24;
    cipherAudio.setSizes(parameters);
    cipherAudio.closeFile();

    qDebug() << "==========================================";
    qDebug() << "Finished Vigènere Cipher Decryption!";
    qDebug() << "==========================================";

}
