#include "wavfile.h"

QDataStream &operator<<(QDataStream &out, const wavParameters &parameters){
    // 0x00 - RIFF ID
    out.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        out << parameters.ID[i];
    // 0x04 - Size ID
    out.setByteOrder(QDataStream::LittleEndian);
    out << parameters.filesize;
    // 0x08 Format name
    out.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        out << parameters.formatName[i];
    // 0x0B Format tag
    for(int i=0; i<4; i++)
        out << parameters.formatTag[i];
    out.setByteOrder(QDataStream::LittleEndian);
    out << parameters.formatLength;
    out << parameters.formatType;
    out << parameters.channelCount;
    out << parameters.sampleRate;
    out << parameters.byteRate;
    out << parameters.blockAlign;
    out << parameters.bitsPerSample;
    out.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        out << parameters.dataTag[i];
    out.setByteOrder(QDataStream::LittleEndian);
    out << parameters.dataSize;

    return out;
}

QDataStream &operator>>(QDataStream &in, wavParameters &parameters){

    in.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        in >> parameters.ID[i];

    in.setByteOrder(QDataStream::LittleEndian);
    in >> parameters.filesize;

    in.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        in >> parameters.formatName[i];
    for(int i=0; i<4; i++)
        in >> parameters.formatTag[i];

    in.setByteOrder(QDataStream::LittleEndian);
    in >> parameters.formatLength;
    in >> parameters.formatType;
    in >> parameters.channelCount;
    in >> parameters.sampleRate;
    in >> parameters.byteRate;
    in >> parameters.blockAlign;
    in >> parameters.bitsPerSample;

    in.setByteOrder(QDataStream::BigEndian);
    for(int i=0; i<4; i++)
        in >> parameters.dataTag[i];

    in.setByteOrder(QDataStream::LittleEndian);
    in >> parameters.dataSize;

    return in;
}
