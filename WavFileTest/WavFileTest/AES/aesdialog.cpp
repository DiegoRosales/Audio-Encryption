#include "aesdialog.h"
#include "ui_aesdialog.h"

aesDialog::aesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aesDialog)
{
    ui->setupUi(this);
}

aesDialog::~aesDialog()
{
    delete ui;
}
