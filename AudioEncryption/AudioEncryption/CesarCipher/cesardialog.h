#ifndef CESARDIALOG_H
#define CESARDIALOG_H

#include <QDialog>
#include <QFile>
#include <QtCore>
#include "wavfile.h"
#include "CesarCipher.h"

namespace Ui {
class CesarDialog;
}

class CesarDialog : public QDialog
{
    Q_OBJECT
    QDataStream in;
    QFile wavFile;
    QString fileName;

public:
    explicit CesarDialog(QWidget *parent = 0);
    ~CesarDialog();
    void setCesarFileName(QString name);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_BrowseIn_clicked();

    void on_BrowseOut_clicked();

private:
    Ui::CesarDialog *ui;
};

#endif // CESARDIALOG_H
