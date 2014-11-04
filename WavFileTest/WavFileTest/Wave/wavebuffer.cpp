#include "wavfile.h"

QDataStream &operator<<(QDataStream &out, const wavBuffer &buffer){
    switch(buffer.stereoMono){
    case MONO:
        switch(buffer.resolution){
        case 8:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3];
            break;
        case 16:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2];
            break;
        case 24:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2]
                        << buffer.dataBuffer[i][1];
            break;
        case 32:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2]
                        << buffer.dataBuffer[i][1]
                        << buffer.dataBuffer[i][0];
            break;
        }

        break;
    case STEREO:
        switch(buffer.resolution){
        case 8:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][4];
            break;
        case 16:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2]
                        << buffer.dataBuffer[i][4]
                        << buffer.dataBuffer[i][5];
            break;
        case 24:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2]
                        << buffer.dataBuffer[i][1]
                        << buffer.dataBuffer[i][4]
                        << buffer.dataBuffer[i][5]
                        << buffer.dataBuffer[i][6];
            break;
        case 32:
            for(int i = 0; i < buffer.newSamples; i++)
                out << buffer.dataBuffer[i][3]
                        << buffer.dataBuffer[i][2]
                        << buffer.dataBuffer[i][1]
                        << buffer.dataBuffer[i][0]
                        << buffer.dataBuffer[i][4]
                        << buffer.dataBuffer[i][5]
                        << buffer.dataBuffer[i][6]
                        << buffer.dataBuffer[i][7];
            break;
        }
        break;
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, wavBuffer &buffer){
    int bufferOffset = 0;
    while(bufferOffset < BUF_SIZE){

        if(buffer.resolution <= 8){
            if(buffer.stereoMono == MONO){
                in >> buffer.dataBuffer[bufferOffset][3];
            }else{
                // Channel 1
                in >> buffer.dataBuffer[bufferOffset][3];
                // Channel 2
                in >> buffer.dataBuffer[bufferOffset][4];
            }
        }else if(buffer.resolution > 8 && buffer.resolution <=16){
            if(buffer.stereoMono == MONO){
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
            }else{
                // Channel 1
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
                // Channel 2
                in >> buffer.dataBuffer[bufferOffset][4];
                in >> buffer.dataBuffer[bufferOffset][5];
            }

        }else if(buffer.resolution > 16 && buffer.resolution <=24){
            if(buffer.stereoMono == MONO){
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
                in >> buffer.dataBuffer[bufferOffset][1];
            }else{
                // Channel 1
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
                in >> buffer.dataBuffer[bufferOffset][1];
                // Channel 2
                in >> buffer.dataBuffer[bufferOffset][4];
                in >> buffer.dataBuffer[bufferOffset][5];
                in >> buffer.dataBuffer[bufferOffset][6];
            }

        }else if(buffer.resolution > 24){
            if(buffer.stereoMono == MONO){
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
                in >> buffer.dataBuffer[bufferOffset][1];
                in >> buffer.dataBuffer[bufferOffset][0];
            }else{
                // Channel 1
                in >> buffer.dataBuffer[bufferOffset][3];
                in >> buffer.dataBuffer[bufferOffset][2];
                in >> buffer.dataBuffer[bufferOffset][1];
                in >> buffer.dataBuffer[bufferOffset][0];
                // Channel 2
                in >> buffer.dataBuffer[bufferOffset][4];
                in >> buffer.dataBuffer[bufferOffset][5];
                in >> buffer.dataBuffer[bufferOffset][6];
                in >> buffer.dataBuffer[bufferOffset][7];
            }
        }
        bufferOffset++;
        if(bufferOffset == BUF_SIZE-1){
            buffer.dataOffset += BUF_SIZE;
            buffer.newSamples = BUF_SIZE;
            //break;
        }else if(in.atEnd()){
            buffer.endOfFile = true;
            buffer.dataOffset += bufferOffset;
            buffer.newSamples = bufferOffset;
            qDebug() << "End of file";
            break;
        }
    }
    return in;
}
