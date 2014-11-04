/********************************************************************************
** Form generated from reading UI file 'wavinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVINFODIALOG_H
#define UI_WAVINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WavInfoDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *WavInfoDialog)
    {
        if (WavInfoDialog->objectName().isEmpty())
            WavInfoDialog->setObjectName(QStringLiteral("WavInfoDialog"));
        WavInfoDialog->resize(393, 260);
        buttonBox = new QDialogButtonBox(WavInfoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 220, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(WavInfoDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 371, 201));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 20, 351, 171));

        retranslateUi(WavInfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WavInfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WavInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WavInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *WavInfoDialog)
    {
        WavInfoDialog->setWindowTitle(QApplication::translate("WavInfoDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("WavInfoDialog", "Wave data", 0));
    } // retranslateUi

};

namespace Ui {
    class WavInfoDialog: public Ui_WavInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVINFODIALOG_H
