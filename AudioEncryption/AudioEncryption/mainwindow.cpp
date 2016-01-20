#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addressEdit->addItem("D:/Users/Diego/Documents/MATLAB/440SineWave8bit.wav");
    index++;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browsePushButton_clicked(){
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                              "D:/Test/Test Files", tr("Wave Files (*.wave *.wav)"));
    if(fileName != "" && ui->addressEdit->findText(fileName, Qt::MatchExactly) == -1){
        ui->addressEdit->addItem(fileName);
        qDebug() << "Filename" << fileName;
        qDebug() << "Index: " << index;
        qDebug() << "Written to combobox:" << ui->addressEdit->itemText(index);
        index++;
        ui->addressEdit->setCurrentIndex(ui->addressEdit->count()-1);
    }
    //ui->lineEdit->setText(fileName);
}

void MainWindow::on_getInfoPushButton_clicked(){
    wavRead myWave;
    WavInfoDialog myDialog;
    QString infoString, format;

    myWave.setPath(ui->addressEdit->itemText(ui->addressEdit->currentIndex()));
    myWave.extract();
    switch(myWave.getParameters().formatType){
    case 1:
        format = "PCM";
        break;
    case 2:
        format = "Microsoft ADPCM";
        break;
    case 6:
        format = "ITU G.711 a-law";
        break;
    case 7:
        format = "ITU G.711 Âµ-law";
        break;
    case 17:
        format = "IMA ADPCM";
        break;
    case 20:
        format = "ITU G.723 ADPCM (Yamaha)";
        break;
    case 49:
        format = "GSM 6.10";
        break;
    case 64:
        format = "ITU G.721 ADPCM";
        break;
    case 80:
        format = "MPEG";
        break;
    case 0:
        format = "Unknown";
        break;
    }


    infoString.append("Overall size: ");
    infoString.append(QString::number(myWave.getParameters().filesize, 10));
    infoString.append(" bytes \n\r");
    infoString.append("Sample Rate: ");
    infoString.append(QString::number(myWave.getParameters().sampleRate, 10));
    infoString.append("Hz \n\r");
    infoString.append("Number of Channels: ");
    infoString.append(QString::number(myWave.getParameters().channelCount, 10));
    infoString.append("\n\r");
    infoString.append("Resolution: ");
    infoString.append(QString::number(myWave.getParameters().bitsPerSample));
    infoString.append(" bits \n\r");
    infoString.append("Format: ");
    infoString.append(format);
    infoString.append("\n\r");
    infoString.append("Data rate: ");
    infoString.append(QString::number(myWave.getParameters().byteRate, 10));
    infoString.append(" bytes per second \n\r");

    qDebug() << infoString;

    myDialog.setInfo(infoString);
    myDialog.setModal(true);
    myDialog.exec();
    //wavWrite newWave;

   // newWave.createWave(false);

}

void MainWindow::on_viewPushButton_clicked()
{
    wavRead myWave;
    WavInfoDialog myDialog;
    QString dataString;
    quint32 bufferTemp = 0;
    wavBuffer buffer;
    int sampleNumber = 0x24;

    myWave.setPath(ui->addressEdit->itemText(ui->addressEdit->currentIndex()));
    myWave.extract();
    //int size = myWave.getData(buffer);

    if(ui->mlPlotRadioButton->isChecked()) // Matlab plot
        dataString.append("clear\nclc\n\nclf\n\ny = [");

    while(myWave.getData(buffer) != 0){
        //outputFile.createWave(buffer, numSamples);
        for(int i=0; i<buffer.newSamples; i++){
            bufferTemp = 0;
            for(int j = 0; j < 32; j+=8){
                bufferTemp |= (quint32)buffer.dataBuffer[i][(int)floor(j/8)];
                if(j < 24)
                    bufferTemp <<= 8;
                //qDebug() << "Buffertemp";
                //qDebug() << bufferTemp;
            }
            if(ui->shOffsetRadioButton->isChecked()){
                dataString.append(QString::number(sampleNumber, 16));
                sampleNumber++;
                dataString.append(": ");
            }
            if(ui->binaryRadioButton->isChecked())
                dataString.append(QString::number(bufferTemp, 2));
            else if(ui->decimalRadioButton->isChecked())
                dataString.append(QString::number(bufferTemp));
            else
                dataString.append(QString::number(bufferTemp, 16));
            if(ui->mlPlotRadioButton->isChecked())
                dataString.append(", ");
            else
                dataString.append("\n");
        }
        if(ui->mlPlotRadioButton->isChecked())
            dataString.append("...\n");
    }
    if(ui->mlPlotRadioButton->isChecked())
        dataString.append("];\nx = 1:1:length(y)\nplot(x, y)");

    //outputFile.setSizes(sampleNumber+1+0x24, sampleNumber+1);
    //outputFile.closeFile();

    myDialog.setInfo(dataString);
    myDialog.setModal(true);
    myDialog.exec();
}


void MainWindow::on_cesarButton_clicked()
{
    CesarDialog myCesarDialog;
    myCesarDialog.setCesarFileName(ui->addressEdit->itemText(ui->addressEdit->currentIndex()));

    myCesarDialog.setModal(true);
    myCesarDialog.exec();
}

void MainWindow::on_vigenereButton_clicked()
{
    VigenereDialog myVigenereDialog;
    myVigenereDialog.setFileName(ui->addressEdit->itemText(ui->addressEdit->currentIndex()));
    myVigenereDialog.setModal(true);
    myVigenereDialog.exec();
}

void MainWindow::on_desButton_clicked()
{
    DESdialog myDESDialog;
    myDESDialog.setFilenameIn(ui->addressEdit->itemText(ui->addressEdit->currentIndex()));
    myDESDialog.setModal(true);
    myDESDialog.exec();
}

void MainWindow::on_aesButton_clicked()
{
    aesDialog myAES;
    if(!&myAES)
        qDebug() << "Fail";
    else{
        qDebug() << "Good";
        myAES.setModal(true);
        myAES.exec();
    }

}

void MainWindow::on_rc4Button_clicked()
{
    RC4Dialog myRC4;
    myRC4.setModal(true);
    myRC4.exec();
}
