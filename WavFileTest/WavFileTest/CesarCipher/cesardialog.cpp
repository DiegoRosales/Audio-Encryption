#include "cesardialog.h"
#include "ui_cesardialog.h"
#include <QtGui>
#include <QMessageBox>

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
    QString error;
    if(!cCipherAudio(ui->lineEdit->text().toInt(), fileName, "D:/Test/cCipherTest.wav", error))
        QMessageBox::warning(this, "Error", error);
    else
       QMessageBox::information(this, "Operation completed", "Encryption completed succesfully");

}

void CesarDialog::on_pushButton_2_clicked()
{
    QString error;
    if(!cDecipherAudio(ui->lineEdit->text().toInt(), fileName, "D:/Test/cCipherTest.wav", error))
       QMessageBox::warning(this, "Error", error);
    else
       QMessageBox::information(this, "Operation completed", "Decryption completed succesfully");
}
