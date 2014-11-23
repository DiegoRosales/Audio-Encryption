/********************************************************************************
** Form generated from reading UI file 'desdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESDIALOG_H
#define UI_DESDIALOG_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DESdialog
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_2;
    QPushButton *browsePButton_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *browsePButton;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *ECB_RB;
    QRadioButton *CBC_RB;
    QRadioButton *CFB_RB;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *initVectorEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QProgressBar *progressBar;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *encryptPB;
    QPushButton *decryptPB;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *DESdialog)
    {
        if (DESdialog->objectName().isEmpty())
            DESdialog->setObjectName(QStringLiteral("DESdialog"));
        DESdialog->resize(337, 414);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DESdialog->sizePolicy().hasHeightForWidth());
        DESdialog->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(DESdialog);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_4 = new QGroupBox(DESdialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comboBox_2 = new QComboBox(groupBox_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        comboBox_2->setEditable(true);

        horizontalLayout_4->addWidget(comboBox_2);

        browsePButton_2 = new QPushButton(groupBox_4);
        browsePButton_2->setObjectName(QStringLiteral("browsePButton_2"));

        horizontalLayout_4->addWidget(browsePButton_2);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox = new QGroupBox(DESdialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setEditable(true);

        horizontalLayout->addWidget(comboBox);

        browsePButton = new QPushButton(groupBox);
        browsePButton->setObjectName(QStringLiteral("browsePButton"));

        horizontalLayout->addWidget(browsePButton);


        verticalLayout_7->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(DESdialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ECB_RB = new QRadioButton(groupBox_2);
        ECB_RB->setObjectName(QStringLiteral("ECB_RB"));
        ECB_RB->setChecked(true);

        verticalLayout->addWidget(ECB_RB);

        CBC_RB = new QRadioButton(groupBox_2);
        CBC_RB->setObjectName(QStringLiteral("CBC_RB"));

        verticalLayout->addWidget(CBC_RB);

        CFB_RB = new QRadioButton(groupBox_2);
        CFB_RB->setObjectName(QStringLiteral("CFB_RB"));

        verticalLayout->addWidget(CFB_RB);


        horizontalLayout_2->addWidget(groupBox_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(DESdialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(DESdialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label = new QLabel(DESdialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        initVectorEdit = new QLineEdit(DESdialog);
        initVectorEdit->setObjectName(QStringLiteral("initVectorEdit"));
        initVectorEdit->setEnabled(false);

        verticalLayout_2->addWidget(initVectorEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(DESdialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);


        verticalLayout_7->addWidget(groupBox_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        encryptPB = new QPushButton(DESdialog);
        encryptPB->setObjectName(QStringLiteral("encryptPB"));

        horizontalLayout_3->addWidget(encryptPB);

        decryptPB = new QPushButton(DESdialog);
        decryptPB->setObjectName(QStringLiteral("decryptPB"));

        horizontalLayout_3->addWidget(decryptPB);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_2 = new QPushButton(DESdialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(DESdialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(pushButton);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        pushButton_3 = new QPushButton(DESdialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_6->addWidget(pushButton_3);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_5);

        groupBox->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox_2->raise();
        pushButton_2->raise();

        retranslateUi(DESdialog);
        QObject::connect(ECB_RB, SIGNAL(toggled(bool)), initVectorEdit, SLOT(setDisabled(bool)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), DESdialog, SLOT(close()));

        QMetaObject::connectSlotsByName(DESdialog);
    } // setupUi

    void retranslateUi(QDialog *DESdialog)
    {
        DESdialog->setWindowTitle(QApplication::translate("DESdialog", "Dialog", 0));
        groupBox_4->setTitle(QApplication::translate("DESdialog", "Input File", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("DESdialog", "D:/Test/DES Encryption.wav", 0)
         << QApplication::translate("DESdialog", "D:/Test/DES Decryption.wav", 0)
         << QApplication::translate("DESdialog", "D:/Test/DESCipherTest.wav", 0)
        );
        browsePButton_2->setText(QApplication::translate("DESdialog", "Browse...", 0));
        groupBox->setTitle(QApplication::translate("DESdialog", "Output file", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DESdialog", "D:/Test/DES Encryption.wav", 0)
         << QApplication::translate("DESdialog", "D:/Test/DES Decryption.wav", 0)
         << QApplication::translate("DESdialog", "D:/Test/DESCipherTest.wav", 0)
        );
        browsePButton->setText(QApplication::translate("DESdialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("DESdialog", "Encryption format", 0));
        ECB_RB->setText(QApplication::translate("DESdialog", "ECB (Electronic Codebook)", 0));
        CBC_RB->setText(QApplication::translate("DESdialog", "CBC (Cipher Block Chaining)", 0));
        CFB_RB->setText(QApplication::translate("DESdialog", "CFB (Cipher Feedback)", 0));
        label_3->setText(QApplication::translate("DESdialog", "Key (HEX)", 0));
        lineEdit_2->setText(QApplication::translate("DESdialog", "0x0123456789ABCDEF", 0));
        label->setText(QApplication::translate("DESdialog", "Initialization vector (HEX)", 0));
        initVectorEdit->setText(QApplication::translate("DESdialog", "0xCE27CB141098FEB0", 0));
        groupBox_3->setTitle(QApplication::translate("DESdialog", "Progress", 0));
        label_2->setText(QApplication::translate("DESdialog", "Execution time: ", 0));
        encryptPB->setText(QApplication::translate("DESdialog", "Encrypt", 0));
        decryptPB->setText(QApplication::translate("DESdialog", "Decrypt", 0));
        pushButton_2->setText(QApplication::translate("DESdialog", "Generate Cross-correlation  Code", 0));
        pushButton->setText(QApplication::translate("DESdialog", "Generate Autocorrelation Code", 0));
        pushButton_3->setText(QApplication::translate("DESdialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class DESdialog: public Ui_DESdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESDIALOG_H
