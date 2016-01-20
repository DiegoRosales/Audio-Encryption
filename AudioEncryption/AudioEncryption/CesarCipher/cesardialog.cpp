#include "cesardialog.h"
#include "ui_cesardialog.h"
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>

CesarDialog::CesarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CesarDialog)
{
    ui->setupUi(this);
}

CesarDialog::~CesarDialog()
{
    delete ui;
}

void CesarDialog::setCesarFileName(QString name){
    fileName = name;
}

void CesarDialog::on_pushButton_clicked()
{
    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());
    QString error;

    QString time = "Execution time: ";
    QTime mTime;
    mTime.start();
    if(!cCipherAudio(ui->lineEdit->text().toInt(), fileIn, filenameOut, error))
        QMessageBox::warning(this, "Error", error);
    else{
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        QMessageBox::information(this, "Operation completed", "Encryption completed succesfully");
    }
}

void CesarDialog::on_pushButton_2_clicked()
{
    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());

    QString error;

    float timeMiliseconds = QTime::currentTime().msec();
    float timeSeconds = QTime::currentTime().second();
    float timeMinutes = QTime::currentTime().minute();
    QString time = "Execution time: ";

    if(!cDecipherAudio(ui->lineEdit->text().toInt(), fileIn, filenameOut, error))
       QMessageBox::warning(this, "Error", error);
    else{
       time.append(QString::number(QTime::currentTime().msec()-timeMiliseconds
                                   +60*(QTime::currentTime().minute()-timeMinutes)
                                   +1000*(QTime::currentTime().second()-timeSeconds)));
       time.append(" ms");
       ui->timeLabel->setText(time);
       QMessageBox::information(this, "Operation completed", "Decryption completed succesfully");
    }
}

void CesarDialog::on_BrowseIn_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this, tr("Open .wav file..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(inputFileName != "" && ui->InputCbox->findText(inputFileName, Qt::MatchExactly) == -1){
        ui->InputCbox->addItem(inputFileName);
        ui->InputCbox->setCurrentIndex(ui->InputCbox->count()-1);
    }
}

void CesarDialog::on_BrowseOut_clicked()
{
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(outputFileName != "" && ui->OutputCbox->findText(outputFileName, Qt::MatchExactly) == -1){
        ui->OutputCbox->addItem(outputFileName);
        ui->OutputCbox->setCurrentIndex(ui->OutputCbox->count()-1);
    }
}
