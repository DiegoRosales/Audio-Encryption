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
    void getKey(quint8 key[]);
    void getIV(quint32 IV[]);
    ~aesDialog();

private slots:
    void setProgress(int progress);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_BrowseIn_clicked();

    void on_BrowseOut_clicked();

    void on_statPB_clicked();

private:
    Ui::aesDialog *ui;
};

#endif // AESDIALOG_H
