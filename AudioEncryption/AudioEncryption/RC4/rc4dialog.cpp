#include "rc4dialog.h"
#include "ui_rc4dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include "rc4audio.h"

RC4Dialog::RC4Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RC4Dialog)
{
    ui->setupUi(this);
}

quint8 RC4Dialog::getKey(quint8 key[])
{
    QString keyString = ui->keyEdit->text();
    keyString.toUtf8();
    for(int i=0; (i<keyString.length() || i<256); i++)
        key[i] = keyString[i].unicode();
    return keyString.length();
}

quint8 RC4Dialog::getInitVector(quint8 initVector[])
{
    QString initVectorString = ui->keyEdit->text();
    initVectorString.toUtf8();
    for(int i=0; (i<initVectorString.length() || i<256); i++)
        initVector[i] = initVectorString[i].unicode();
    return initVectorString.length();
}

RC4Dialog::~RC4Dialog()
{
    delete ui;
}

void RC4Dialog::setProgress(int progress)
{
    ui->progressBar->setValue(progress);
}

void RC4Dialog::on_BrowseIn_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this, tr("Open .wav file..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(inputFileName != "" && ui->InputCbox->findText(inputFileName, Qt::MatchExactly) == -1){
        ui->InputCbox->addItem(inputFileName);
        ui->InputCbox->setCurrentIndex(ui->InputCbox->count()-1);
    }
}

void RC4Dialog::on_BrowseOut_clicked()
{
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(outputFileName != "" && ui->OutputCbox->findText(outputFileName, Qt::MatchExactly) == -1){
        ui->OutputCbox->addItem(outputFileName);
        ui->OutputCbox->setCurrentIndex(ui->OutputCbox->count()-1);
    }
}

void RC4Dialog::on_pushButton_2_clicked()
{
    RC4Audio myRC4;
    quint8 key[256];
    quint8 length = getKey(key);
    quint8 initVector[256];
    quint8 initVectorLength = getInitVector(initVector);

    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());
    QString error;
    connect(&myRC4, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QTime mTime;
    mTime.start();

    QString time = "Execution time: ";

    switch(getEncryptionMode()){
    case ECB:
        myRC4.CipherAudioECB(key, length, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    case CBC:
        myRC4.CipherAudioCBC(key, length, initVector, initVectorLength, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    case CFB:
        myRC4.CipherAudioCFB(key, length, initVector, initVectorLength, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    }
}

quint8 RC4Dialog::getEncryptionMode(){
    if(ui->CBC_RB->isChecked())
        return CBC;
    else if(ui->ECB_RB->isChecked())
        return ECB;
    else if(ui->CFB_RB->isChecked())
        return CFB;
    else
        return 0;
}

void RC4Dialog::on_pushButton_3_clicked()
{
    RC4Audio myRC4;
    quint8 key[256];
    quint8 length = getKey(key);
    quint8 initVector[256];
    quint8 initVectorLength = getInitVector(initVector);

    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());
    QString error;
    connect(&myRC4, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QString time = "Execution time: ";
    QTime mTime;
    mTime.start();

    switch(getEncryptionMode()){
    case ECB:
        myRC4.CipherAudioECB(key, length, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    case CBC:
        myRC4.DecipherAudioCBC(key, length, initVector, initVectorLength, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    case CFB:
        myRC4.DecipherAudioCFB(key, length, initVector, initVectorLength, fileIn, filenameOut, error);
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        break;
    }
}
