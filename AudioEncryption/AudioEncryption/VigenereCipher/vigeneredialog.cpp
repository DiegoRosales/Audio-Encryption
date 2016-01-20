#include "vigeneredialog.h"
#include "ui_vigeneredialog.h"
#include <QMessageBox>
VigenereDialog::VigenereDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VigenereDialog)
{
    ui->setupUi(this);
}

VigenereDialog::~VigenereDialog()
{
    delete ui;
}

void VigenereDialog::setFileName(QString fileName){
    this->fileName = fileName;
}

void VigenereDialog::on_encryptButton_clicked(){
    vigenereCipher myVigenere;
    connect(&myVigenere, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QString time = "Execution time: ";
    QTime mTime;
    mTime.start();
    if(!myVigenere.vCipherAudio(ui->keyEdit->text(), fileName, ui->filenameCBox_2->itemText(ui->filenameCBox_2->currentIndex()), error))
        QMessageBox::warning(this, "Error", error);
    else{
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        QMessageBox::information(this, "Operation completed", "Encryption completed succesfully");
    }
}

void VigenereDialog::on_searchButton_2_clicked()
{
    outputFileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              "D:/Test", tr("Wave File (*.wav)"));

    ui->filenameCBox_2->addItem(outputFileName);
}

void VigenereDialog::setProgress(int progress){
    ui->progressBar->setValue(progress);
}


void VigenereDialog::on_decryptButton_clicked()
{
    vigenereCipher myVigenere;
    connect(&myVigenere, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QString time = "Execution time: ";
    QTime mTime;
    mTime.start();
    if(!myVigenere.vDecipherAudio(ui->keyEdit->text(), fileName, ui->filenameCBox_2->itemText(ui->filenameCBox_2->currentIndex()), error))
        QMessageBox::warning(this, "Error", error);
    else{
        time.append(QString::number(mTime.elapsed()));
        time.append(" ms");
        ui->timeLabel->setText(time);
        QMessageBox::information(this, "Operation completed", "Decryption completed succesfully");
    }
}
