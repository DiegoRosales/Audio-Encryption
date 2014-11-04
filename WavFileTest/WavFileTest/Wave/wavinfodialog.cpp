#include "wavinfodialog.h"
#include "ui_wavinfodialog.h"

WavInfoDialog::WavInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WavInfoDialog)
{
    ui->setupUi(this);
}

WavInfoDialog::~WavInfoDialog()
{

    delete ui;
}

void WavInfoDialog::setInfo(QString infoString){
    ui->plainTextEdit->setPlainText(infoString);
}
