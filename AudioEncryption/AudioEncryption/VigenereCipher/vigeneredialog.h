#ifndef VIGENEREDIALOG_H
#define VIGENEREDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QObject>
#include "vigenerecipher.h"
#include "wavfile.h"

namespace Ui {
class VigenereDialog;
}

class VigenereDialog : public QDialog
{
    Q_OBJECT
    QString fileName;
    QString keyFileName;
    QString outputFileName;
    QString error;
public:
    explicit VigenereDialog(QWidget *parent = 0);
    ~VigenereDialog();

    void setFileName(QString fileName);
private slots:
    void on_encryptButton_clicked();

    void on_searchButton_2_clicked();

    void setProgress(int progress);

    void on_decryptButton_clicked();

private:
    Ui::VigenereDialog *ui;
signals:
    void progressUpdate(int progress);
};

#endif // VIGENEREDIALOG_H
