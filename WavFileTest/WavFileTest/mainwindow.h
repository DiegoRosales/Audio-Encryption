#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDataStream>
#include <QString>
#include <QFile>
#include "wavfile.h"
#include "wavinfodialog.h"
#include "cesardialog.h"
#include "vigeneredialog.h"
#include "desdialog.h"
#include "AES/aesdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString fileName;
    int index = 0;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_browsePushButton_clicked();
    void on_getInfoPushButton_clicked();
    void on_viewPushButton_clicked();

    void on_cesarButton_clicked();

    void on_vigenereButton_clicked();

    void on_desButton_clicked();

    void on_aesButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
