#ifndef WAVINFODIALOG_H
#define WAVINFODIALOG_H

#include <QDialog>

namespace Ui {
class WavInfoDialog;
}

class WavInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WavInfoDialog(QWidget *parent = 0);
    ~WavInfoDialog();

    void setInfo(QString infoString);

private:
    Ui::WavInfoDialog *ui;
};

#endif // WAVINFODIALOG_H
