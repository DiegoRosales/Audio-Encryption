#include "wavfile.h"

wavWrite::wavWrite()
{
}
wavWrite::wavWrite(QString filename){
    fileName = filename;
}
wavWrite::wavWrite(QString filename, wavParameters parameters){
    myErrorInt = false;
    fileName = filename;
    myParameters = parameters;
    wavFile.setFileName(fileName);
    out.setDevice(&wavFile);
    // Creates new file with basic parameters
    if(!wavFile.open(QIODevice::ReadWrite)){
        myErrorInt = true;
        myError = wavFile.errorString();
        qDebug() << "Couldn't create the wave file";
        return;
    }else{
        qDebug() << "File created with success";
        qDebug() << "Directory " << fileName;
        out << myParameters;
        wavFile.flush();
    }
}

void wavWrite::setParameters(wavParameters parameters){
    myParameters = parameters;
}

void wavWrite::setFileName(QString filename){
    fileName = filename;
}

int wavWrite::createWave(bool cont){
    myErrorInt = false;
    wavFile.setFileName(fileName);
    out.setDevice(&wavFile);

    if(!wavFile.open(QIODevice::ReadWrite)){
        qDebug() << "Couldn't create the wave file";
        myErrorInt = true;
        myError = wavFile.errorString();
        return -1;
    }else{
        qDebug() << "File created with success";
        qDebug() << "Directory " << fileName;
    }
    out << myParameters;

    wavFile.flush();
    if(!cont)
        wavFile.close();
    return 0;
}

int wavWrite::writeBuffer(wavBuffer buffer){
    out << buffer;
    wavFile.flush();
    return 0;
}

void wavWrite::closeFile(){
    wavFile.close();
}

void wavWrite::setSizes(wavParameters parameters){
    myParameters = parameters;
    createWave(false);
}

bool wavWrite::getWriteError(QString &error){
    error = myError;
    return myErrorInt;
}
