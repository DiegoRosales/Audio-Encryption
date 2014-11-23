/********************************************************************************
** Form generated from reading UI file 'vigeneredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIGENEREDIALOG_H
#define UI_VIGENEREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VigenereDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *keyEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *filenameCBox_2;
    QPushButton *searchButton_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QProgressBar *progressBar;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QDialog *VigenereDialog)
    {
        if (VigenereDialog->objectName().isEmpty())
            VigenereDialog->setObjectName(QStringLiteral("VigenereDialog"));
        VigenereDialog->resize(317, 247);
        verticalLayout_5 = new QVBoxLayout(VigenereDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(VigenereDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        keyEdit = new QLineEdit(groupBox);
        keyEdit->setObjectName(QStringLiteral("keyEdit"));

        verticalLayout_2->addWidget(keyEdit);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(VigenereDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filenameCBox_2 = new QComboBox(groupBox_2);
        filenameCBox_2->setObjectName(QStringLiteral("filenameCBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filenameCBox_2->sizePolicy().hasHeightForWidth());
        filenameCBox_2->setSizePolicy(sizePolicy);
        filenameCBox_2->setEditable(true);

        horizontalLayout_2->addWidget(filenameCBox_2);

        searchButton_2 = new QPushButton(groupBox_2);
        searchButton_2->setObjectName(QStringLiteral("searchButton_2"));

        horizontalLayout_2->addWidget(searchButton_2);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_5->addLayout(verticalLayout_3);

        groupBox_3 = new QGroupBox(VigenereDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_4->addWidget(progressBar);

        timeLabel = new QLabel(groupBox_3);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_4->addWidget(timeLabel);


        verticalLayout_5->addWidget(groupBox_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        encryptButton = new QPushButton(VigenereDialog);
        encryptButton->setObjectName(QStringLiteral("encryptButton"));

        horizontalLayout_3->addWidget(encryptButton);

        decryptButton = new QPushButton(VigenereDialog);
        decryptButton->setObjectName(QStringLiteral("decryptButton"));

        horizontalLayout_3->addWidget(decryptButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cancelButton = new QPushButton(VigenereDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(VigenereDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), VigenereDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(VigenereDialog);
    } // setupUi

    void retranslateUi(QDialog *VigenereDialog)
    {
        VigenereDialog->setWindowTitle(QApplication::translate("VigenereDialog", "Vigenere Cipher", 0));
        groupBox->setTitle(QApplication::translate("VigenereDialog", "Key", 0));
        keyEdit->setText(QApplication::translate("VigenereDialog", "myKey", 0));
        groupBox_2->setTitle(QApplication::translate("VigenereDialog", "Output file", 0));
        filenameCBox_2->clear();
        filenameCBox_2->insertItems(0, QStringList()
         << QApplication::translate("VigenereDialog", "D:/Test/vCipherTest.wav", 0)
        );
        searchButton_2->setText(QApplication::translate("VigenereDialog", "Browse...", 0));
        groupBox_3->setTitle(QApplication::translate("VigenereDialog", "Benchmark", 0));
        timeLabel->setText(QApplication::translate("VigenereDialog", "Execution time: ", 0));
        encryptButton->setText(QApplication::translate("VigenereDialog", "Encrypt", 0));
        decryptButton->setText(QApplication::translate("VigenereDialog", "Decrypt", 0));
        cancelButton->setText(QApplication::translate("VigenereDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class VigenereDialog: public Ui_VigenereDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIGENEREDIALOG_H
