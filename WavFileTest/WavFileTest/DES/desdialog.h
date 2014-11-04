#ifndef DESDIALOG_H
#define DESDIALOG_H

#include <QDialog>
#include "DES.h"
namespace Ui {
class DESdialog;
}

class DESdialog : public QDialog
{
    Q_OBJECT

    QString filenameIn;
public:
    explicit DESdialog(QWidget *parent = 0);
    ~DESdialog();
    void setFilenameIn(QString filename);

private slots:
    void on_encryptPB_clicked();
    void setProgress(int progress);

    void on_decryptPB_clicked();

    void on_browsePButton_clicked();

    void on_browsePButton_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DESdialog *ui;

signals:
    void progressUpdate(int progress);
};

#endif // DESDIALOG_H
