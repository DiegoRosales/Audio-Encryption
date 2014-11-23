#include "aesdialog.h"
#include "ui_aesdialog.h"
#include "aesaudio.h"
#include <QMessageBox>
#include <QFileDialog>
#include "codedialog.h"

aesDialog::aesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aesDialog)
{
    ui->setupUi(this);
}

void aesDialog::getKey(quint8 key[])
{
    QString keyString = ui->keyEdit->text();

    QString keyTemp = "";
    quint8 x = 0, y = 0;

    for(int i=0; i<4; i++)
        key[i] = 0;

    while((x < keyString.length()) && (y < 16)){
        keyTemp.append(keyString[x]);
        x++;
        if(x%2 == 0){
            key[y] = keyTemp.toUShort(0, 16);
            qDebug() << keyTemp.toUShort(0, 16);
            keyTemp = "";
            qDebug() << QString::number(key[y], 16);
            y++;
        }
    }
}

void aesDialog::getIV(quint32 IV[])
{
    QString ivString = ui->ivEdit->text();

    QString ivTemp = "";

    for(int i=0; i<32; i++){
        if(i != 0){
            if(i%8 == 0){
                IV[i/8] = ivTemp.toUInt(0, 16);
                ivTemp = "";
            }
        }
        if(i >= ivString.length())
            ivTemp.append(QString::number(0));
        else
            ivTemp.append(ivString[i]);

    }
}

aesDialog::~aesDialog()
{
    delete ui;
}

void aesDialog::setProgress(int progress){
    ui->progressBar->setValue(progress);
}

void aesDialog::on_pushButton_2_clicked()
{
    aesAudio myAES;
    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());
    QString error;
    quint8 key[16];
    quint32 IV[4];
    getKey(key);
    getIV(IV);
    connect(&myAES, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QTime mTime;
    mTime.start();

    if(ui->ECB_RB->isChecked()){
        if(!myAES.CipherAudioECB(key, fileIn, filenameOut, error))
            QMessageBox::warning(this, "Error", error);
        else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio encrypted succesfully using Electronic Codebook");
        }
    }else if(ui->CBC_RB->isChecked()){
        if(!myAES.CipherAudioCBC(key, IV, fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" ms");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio encrypted succesfully using Cipher Block Chaning");
        }
    }else if(ui->CFB_RB->isChecked()){
        if(!myAES.CipherAudioCBF(key, IV, fileIn, filenameOut, error)){
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

void aesDialog::on_pushButton_3_clicked()
{
    aesAudio myAES;
    QString filenameOut = ui->OutputCbox->itemText(ui->OutputCbox->currentIndex());
    QString fileIn = ui->InputCbox->itemText(ui->InputCbox->currentIndex());
    QString error;
    quint8 key[16];
    quint32 IV[4];
    getKey(key);
    getIV(IV);
    connect(&myAES, SIGNAL(progressChange(int)), this, SLOT(setProgress(int)));

    QTime mTime;
    mTime.start();

    if(ui->ECB_RB->isChecked()){
        if(!myAES.DecipherAudioECB(key, fileIn, filenameOut, error))
            QMessageBox::warning(this, "Error", error);
        else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" seconds");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Electronic Codebook");
        }
    }else if(ui->CBC_RB->isChecked()){
        if(!myAES.DecipherAudioCBC(key, IV, fileIn, filenameOut, error))
            QMessageBox::warning(this, "Error", error);
        else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" seconds");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Cipher Block Chaning");
        }
    }else if(ui->CFB_RB->isChecked()){
        if(!myAES.DecipherAudioCBF(key, IV, fileIn, filenameOut, error)){
            QMessageBox::warning(this, "Error", error);
        }else{
            QString time = "Execution time: ";
            time.append(QString::number(mTime.elapsed()));
            time.append(" seconds");
            ui->timeLabel->setText(time);
            QMessageBox::information(this, "Success!!", "Audio decrypted succesfully using Cipher Feedback");
        }
    }
}

void aesDialog::on_BrowseIn_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this, tr("Open .wav file..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(inputFileName != "" && ui->InputCbox->findText(inputFileName, Qt::MatchExactly) == -1){
        ui->InputCbox->addItem(inputFileName);
        ui->InputCbox->setCurrentIndex(ui->InputCbox->count()-1);
    }
}

void aesDialog::on_BrowseOut_clicked()
{
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              "D:/Test", tr("Wave File (*.wav)"));
    if(outputFileName != "" && ui->OutputCbox->findText(outputFileName, Qt::MatchExactly) == -1){
        ui->OutputCbox->addItem(outputFileName);
        ui->OutputCbox->setCurrentIndex(ui->OutputCbox->count()-1);
    }
}

void aesDialog::on_statPB_clicked()
{
    QString code;
    codeDialog myDialog;

    code.append("% Autocorrelation and Cross correlation analysis\n\n");
    code.append("clear\nclc\nclf\n\n");
    code.append("plainAudio = audioread('");
    code.append(ui->InputCbox->itemText(ui->InputCbox->currentIndex()));
    code.append("');\n");
    code.append("cipherAudio = audioread('");
    code.append(ui->OutputCbox->itemText(ui->OutputCbox->currentIndex()));
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
