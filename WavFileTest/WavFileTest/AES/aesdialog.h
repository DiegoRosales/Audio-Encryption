#ifndef AESDIALOG_H
#define AESDIALOG_H

#include <QDialog>

namespace Ui {
class aesDialog;
}

class aesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aesDialog(QWidget *parent = 0);
    ~aesDialog();

private:
    Ui::aesDialog *ui;
};

#endif // AESDIALOG_H
