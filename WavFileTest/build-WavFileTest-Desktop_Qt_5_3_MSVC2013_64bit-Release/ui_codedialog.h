/********************************************************************************
** Form generated from reading UI file 'codedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEDIALOG_H
#define UI_CODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_codeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *codeDialog)
    {
        if (codeDialog->objectName().isEmpty())
            codeDialog->setObjectName(QStringLiteral("codeDialog"));
        codeDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(codeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(codeDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(codeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(codeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), codeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), codeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(codeDialog);
    } // setupUi

    void retranslateUi(QDialog *codeDialog)
    {
        codeDialog->setWindowTitle(QApplication::translate("codeDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class codeDialog: public Ui_codeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEDIALOG_H
