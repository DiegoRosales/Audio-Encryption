#include "wavfile.h"

// Constructors
wavRead::wavRead(QString path){
    for(int i=0; i<BUF_SIZE; i++){
        for(int j = 0; j < 8; j++){
            myBuffer.dataBuffer[i][j] = 0;
        }
    }
    filePath = path;
    //extract(false);
}
wavRead::wavRead(QString path, wavParameters &parameters){
    for(int i=0; i<BUF_SIZE; i++){
        for(int j = 0; j < 8; j++){
            myBuffer.dataBuffer[i][j] = 0;
        }
    }
    filePath = path;
    extract();
    parameters = myParameters;
}

wavRead::wavRead(){
    for(int i=0; i<BUF_SIZE; i++){
        for(int j = 0; j < 8; j++){
            myBuffer.dataBuffer[i][j] = 0;
        }
    }
}
wavRead::~wavRead(){
    qDebug() << "----------------------------------------";
    qDebug() << "Calling WavFile destructor";
    qDebug() << "Closing wav file...";
    qDebug() << "----------------------------------------";
    /*-----------------------------------------*/
    // closing file
    wave.close();
    qDebug() << "File closed";
}


// Step 1 - Set the filename (file path)
void wavRead::setPath(QString path){
    qDebug() << "----------------------------------------";
    qDebug() << "void WavFile::setPath(QString path)";
    qDebug() << "path = " << path;
    qDebug() << "----------------------------------------";
    filePath = path;
    qDebug() << "----------------------------------------";
    qDebug() << "END OF void WavFile::setPath(QString path)";
    qDebug() << "----------------------------------------";
}

// Step 2 - Extract the basic Wav information
void wavRead::extract(){
    myErrorInt = false;
    wave.setFileName(filePath);
    in.setDevice(&wave);

    if(!wave.open(QIODevice::ReadOnly)){
        qDebug() << "Couldn't read the wave file";
        myErrorInt = true;
        myError = wave.errorString();
        return;
    }else{
        qDebug() << "File read with success";
        qDebug() << filePath;
    }

    myBuffer.endOfFile = false;
    in >> myParameters;
    myBuffer.stereoMono = myParameters.channelCount;
    myBuffer.resolution = myParameters.bitsPerSample;
    myBuffer.chunkSize = myParameters.dataSize;

}

// Step 3 - Fill  the buffer with audio data
int wavRead::getData(wavBuffer &buffer){
    if(myBuffer.endOfFile)
        return 0;
    in >> myBuffer;
    buffer = myBuffer;
    return myBuffer.newSamples;
}

// Returns the class containing all Wav parameters
wavParameters wavRead::getParameters(){
    return myParameters;
}

bool wavRead::getReadError(QString &error){
    error = myError;
    return myErrorInt;
}
