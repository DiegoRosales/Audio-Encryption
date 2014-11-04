#ifndef WAVFILE_H
#define WAVFILE_H

#define BUF_SIZE 256
#define STEREO 2
#define MONO 1

#include <QString>
#include <QFile>
#include <QDebug>

class wavBuffer
{
public:
    quint8 dataBuffer[BUF_SIZE][8];
    quint8 stereoMono;
    quint8 resolution;
    bool endOfFile = false;
    int dataOffset = 0;
    int chunkSize;
    int newSamples;

};

class wavParameters{

public:
    // Basic header
        quint8 ID[4]; // ID ex. RIFF
        quint32 filesize;
        quint8 formatName[4]; // Format name ex. WAVE

    // fmt header
        quint8 formatTag[4]; // Format tag ex. fmt+{null}
        quint32 formatLength; // Format data length ex. 16
        quint16 formatType; // Format type ex. 1 = PCM, 2 = Byte
        quint16 channelCount; // Channel count ex. 1
        quint32 sampleRate; // Sample Rate ex. 44100
        quint32 byteRate; // Byte Rate = (Sample Rate * BitsPerSample * Channels) / 8.
        quint16 blockAlign;
        quint16 bitsPerSample; // Bits Per Sample (Resolution) ex. 16

    // data header
        quint8 dataTag[4];
        quint32 dataSize;

        wavParameters(){
            ID[0] = 'R';
            ID[1] = 'I';
            ID[2] = 'F';
            ID[3] = 'F';
            filesize = 0xFFFFFFFF;
            formatName[0] = 'W';
            formatName[1] = 'A';
            formatName[2] = 'V';
            formatName[3] = 'E';

            formatTag[0] = 'f';
            formatTag[1] = 'm';
            formatTag[2] = 't';
            formatTag[3] = ' ';

            formatLength = 16;
            formatType = 1;
            channelCount = 1;
            sampleRate = 48000;
            byteRate = 48000;
            blockAlign = 1;
            bitsPerSample = 8;

            dataTag[0] = 'd';
            dataTag[1] = 'a';
            dataTag[2] = 't';
            dataTag[3] = 'a';
        }
};


class wavRead
{
    QFile wave;
    QString filePath;
    QDataStream in;

    wavParameters myParameters;
    wavBuffer myBuffer;
    QString myError;
    bool myErrorInt = 0;

public:
    wavRead(QString path);
    wavRead(QString path, wavParameters &parameters);
    wavRead();
    ~wavRead();
    void extract();
    void setPath(QString path);
    int getData(wavBuffer &buffer); // Returns data in chunks
    wavParameters getParameters();
    bool getReadError(QString &error);
};

class wavWrite
{
    wavParameters myParameters;
    QString fileName = "D:/Test/myWave.wav";
    QFile wavFile;
    QDataStream out;
    QString myError;
    bool myErrorInt = 0;
public:
    wavWrite();
    wavWrite(QString filename);
    wavWrite(QString filename, wavParameters parameters);
    void setParameters(wavParameters parameters);
    void setFileName(QString filename);
    int createWave(bool cont);
    int writeBuffer(wavBuffer buffer);
    void closeFile();
    void setSizes(wavParameters parameters);
    bool getWriteError(QString &error);
};

QDataStream &operator<<(QDataStream &out, const wavParameters &parameters);
QDataStream &operator>>(QDataStream &in, wavParameters &parameters);

QDataStream &operator<<(QDataStream &out, const wavBuffer &buffer);
QDataStream &operator>>(QDataStream &in, wavBuffer &buffer);

#endif // WAVFILE_H
