#include "mainwindow.h"
#include <QApplication>
#include "wavfile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //WavFile myFile("D:/Users/Diego/Documents/MATLAB/440SineWave8bit.wav");
    //myFile.extract(false);
    //qDebug() << myFile.getParameters().dataTag[1];
    return a.exec();
    //return 0;
}
