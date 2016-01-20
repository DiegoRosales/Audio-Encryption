#ifndef CODEDIALOG_H
#define CODEDIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class codeDialog;
}

class codeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit codeDialog(QWidget *parent = 0);
    ~codeDialog();
    void setPlainText(QString plaintext);

private:
    Ui::codeDialog *ui;
};

#endif // CODEDIALOG_H
