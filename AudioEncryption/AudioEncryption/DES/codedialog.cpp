#include "codedialog.h"
#include "ui_codedialog.h"

codeDialog::codeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::codeDialog)
{
    ui->setupUi(this);
}

codeDialog::~codeDialog()
{
    delete ui;
}

void codeDialog::setPlainText(QString plaintext){
    ui->plainTextEdit->setPlainText(plaintext);
}
