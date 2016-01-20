#include "desdialog.h"
#include "ui_desdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include "codedialog.h"
DESdialog::DESdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DESdialog)
{
    //ui->comboBox_2->addItem(filenameIn);
    ui->setupUi(this);
}

DESdialog::~DESdialog()
{
    delete ui;
}

void DESdialog::on_encryptPB_clicked()
{
    DES myDes;
    QString filenameOut = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString fileIn = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
    QString error;
    connect(&myDes, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));
    QTime mTime;
    mTime.start();
    if(ui->ECB_RB->isChecked()){
        if(!myDes.CipherAudioECB(ui->lineEdit_2->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error))
            QMessageBox::warning(this, "Error", error);
        else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio encrypted succesfully using Electronic Codebook");
        }
    }else if(ui->CBC_RB->isChecked()){
        if(!myDes.CipherAudioCBC(ui->lineEdit_2->text().toLongLong(0, 0),
                                   ui->initVectorEdit->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio encrypted succesfully using Cipher Block Chaning");
        }
    }else if(ui->CFB_RB->isChecked()){
        if(!myDes.CipherAudioCFB(ui->lineEdit_2->text().toLongLong(0, 0),
                                   ui->initVectorEdit->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio encrypted succesfully using Cipher Feedback");
        }
    }

}

void DESdialog::setFilenameIn(QString filename){
    filenameIn = filename;
    ui->comboBox_2->addItem(filenameIn);
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->count() - 1);
}

void DESdialog::setProgress(int progress){
    ui->progressBar->setValue(progress);
}

// Decryption
void DESdialog::on_decryptPB_clicked()
{
    DES myDes;
    QString filenameOut = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString fileIn = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
    QString error;

    connect(&myDes, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QTime mTime;
    mTime.start();

    if(ui->ECB_RB->isChecked()){
        if(!myDes.DecipherAudioECB(ui->lineEdit_2->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error))
            QMessageBox::warning(this, "Error", error);
        else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Electronic Codebook");
        }
    }else if(ui->CBC_RB->isChecked()){
        if(!myDes.DecipherAudioCBC(ui->lineEdit_2->text().toLongLong(0, 0),
                                   ui->initVectorEdit->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Cipher Block Chaning");
        }
    }else if(ui->CFB_RB->isChecked()){
        if(!myDes.DecipherAudioCFB(ui->lineEdit_2->text().toLongLong(0, 0),
                                   ui->initVectorEdit->text().toLongLong(0, 0),
                                   fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Cipher Feedback");
        }
    }

}

void DESdialog::on_browsePButton_clicked()
{
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(outputFileName != "" && ui->comboBox->findText(outputFileName, Qt::MatchExactly) == -1){
        ui->comboBox->addItem(outputFileName);
        ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
    }
}

void DESdialog::on_browsePButton_2_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this, tr("Open .wav file..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(inputFileName != "" && ui->comboBox_2->findText(inputFileName, Qt::MatchExactly) == -1){
        ui->comboBox_2->addItem(inputFileName);
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->count()-1);
    }
}

void DESdialog::on_pushButton_2_clicked()
{
    QString code;
    codeDialog myDialog;

    code.append("% Autocorrelation and Cross correlation analysis\n\n");
    code.append("clear\nclc\nclf\n\n");
    code.append("plainAudio = audioread('");
    code.append(ui->comboBox_2->itemText(ui->comboBox_2->currentIndex()));
    code.append("');\n");
    code.append("cipherAudio = audioread('");
    code.append(ui->comboBox->itemText(ui->comboBox->currentIndex()));
    code.append("');\n\n");
    code.append("subplot(2, 2, 1);\n");
    code.append("autocorr(plainAudio(:, 1));\n\n");
    code.append("title('Plain audio Autocorrelation');\n");
    code.append("subplot(2, 2, 3);\n");
    code.append("autocorr(cipherAudio(:, 1));\n");
    code.append("title('Cipher audio Autocorrelation');\n\n");
    code.append("subplot(2, 2, [2, 4]);\n");
    code.append("crosscorr(plainAudio(:, 1), cipherAudio(:, 1));\n");
    code.append("title('Cross correlation')\n");

    myDialog.setPlainText(code);
    myDialog.setModal(true);
    myDialog.show();
    myDialog.exec();
}
