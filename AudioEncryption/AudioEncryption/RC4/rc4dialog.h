#ifndef RC4DIALOG_H
#define RC4DIALOG_H

#include <QDialog>

namespace Ui {
class RC4Dialog;
}

class RC4Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit RC4Dialog(QWidget *parent = 0);
    quint8 getKey(quint8 key[]);
    quint8 getInitVector(quint8 initVector[]);
    quint8 getEncryptionMode();
    ~RC4Dialog();

private slots:
    void setProgress(int progress);
    void on_BrowseIn_clicked();

    void on_BrowseOut_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::RC4Dialog *ui;
};

#endif // RC4DIALOG_H
