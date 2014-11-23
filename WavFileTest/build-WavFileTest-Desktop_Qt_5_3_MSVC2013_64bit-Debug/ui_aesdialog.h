/********************************************************************************
** Form generated from reading UI file 'aesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AESDIALOG_H
#define UI_AESDIALOG_H

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

class Ui_aesDialog
{
public:
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_5;
    QComboBox *InputCbox;
    QComboBox *OutputCbox;
    QVBoxLayout *verticalLayout_7;
    QPushButton *BrowseIn;
    QPushButton *BrowseOut;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *ECB_RB;
    QRadioButton *CBC_RB;
    QRadioButton *CFB_RB;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *keyEdit;
    QLabel *label_2;
    QLineEdit *ivEdit;
    QProgressBar *progressBar;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *statPB;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *aesDialog)
    {
        if (aesDialog->objectName().isEmpty())
            aesDialog->setObjectName(QStringLiteral("aesDialog"));
        aesDialog->resize(444, 340);
        verticalLayout_11 = new QVBoxLayout(aesDialog);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox = new QGroupBox(aesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        InputCbox = new QComboBox(groupBox);
        InputCbox->setObjectName(QStringLiteral("InputCbox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputCbox->sizePolicy().hasHeightForWidth());
        InputCbox->setSizePolicy(sizePolicy);
        InputCbox->setEditable(true);

        verticalLayout_5->addWidget(InputCbox);

        OutputCbox = new QComboBox(groupBox);
        OutputCbox->setObjectName(QStringLiteral("OutputCbox"));
        sizePolicy.setHeightForWidth(OutputCbox->sizePolicy().hasHeightForWidth());
        OutputCbox->setSizePolicy(sizePolicy);
        OutputCbox->setEditable(true);

        verticalLayout_5->addWidget(OutputCbox);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        BrowseIn = new QPushButton(groupBox);
        BrowseIn->setObjectName(QStringLiteral("BrowseIn"));

        verticalLayout_7->addWidget(BrowseIn);

        BrowseOut = new QPushButton(groupBox);
        BrowseOut->setObjectName(QStringLiteral("BrowseOut"));

        verticalLayout_7->addWidget(BrowseOut);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_11->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(aesDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ECB_RB = new QRadioButton(groupBox_2);
        ECB_RB->setObjectName(QStringLiteral("ECB_RB"));
        ECB_RB->setChecked(true);

        verticalLayout_3->addWidget(ECB_RB);

        CBC_RB = new QRadioButton(groupBox_2);
        CBC_RB->setObjectName(QStringLiteral("CBC_RB"));
        CBC_RB->setChecked(false);

        verticalLayout_3->addWidget(CBC_RB);

        CFB_RB = new QRadioButton(groupBox_2);
        CFB_RB->setObjectName(QStringLiteral("CFB_RB"));

        verticalLayout_3->addWidget(CFB_RB);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(aesDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        keyEdit = new QLineEdit(groupBox_4);
        keyEdit->setObjectName(QStringLiteral("keyEdit"));

        verticalLayout->addWidget(keyEdit);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        ivEdit = new QLineEdit(groupBox_4);
        ivEdit->setObjectName(QStringLiteral("ivEdit"));
        ivEdit->setEnabled(false);
        ivEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(ivEdit);


        horizontalLayout_3->addWidget(groupBox_4);


        verticalLayout_11->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(aesDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_11->addWidget(progressBar);

        timeLabel = new QLabel(aesDialog);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_11->addWidget(timeLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(aesDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(aesDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);

        statPB = new QPushButton(aesDialog);
        statPB->setObjectName(QStringLiteral("statPB"));

        verticalLayout_2->addWidget(statPB);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pushButton_4 = new QPushButton(aesDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_11->addLayout(horizontalLayout_5);


        retranslateUi(aesDialog);
        QObject::connect(pushButton_4, SIGNAL(clicked()), aesDialog, SLOT(close()));
        QObject::connect(ECB_RB, SIGNAL(toggled(bool)), ivEdit, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(aesDialog);
    } // setupUi

    void retranslateUi(QDialog *aesDialog)
    {
        aesDialog->setWindowTitle(QApplication::translate("aesDialog", "Advanced Encryption Standard", 0));
        groupBox->setTitle(QApplication::translate("aesDialog", "Input/Output", 0));
        label_3->setText(QApplication::translate("aesDialog", "Input: ", 0));
        label_4->setText(QApplication::translate("aesDialog", "Output: ", 0));
        InputCbox->clear();
        InputCbox->insertItems(0, QStringList()
         << QApplication::translate("aesDialog", "D:/Test/Test Files/test.wav", 0)
        );
        OutputCbox->clear();
        OutputCbox->insertItems(0, QStringList()
         << QApplication::translate("aesDialog", "D:/Test/AES Encryption.wav", 0)
         << QApplication::translate("aesDialog", "D:/Test/AES Decryption.wav", 0)
        );
        BrowseIn->setText(QApplication::translate("aesDialog", "Browse...", 0));
        BrowseOut->setText(QApplication::translate("aesDialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("aesDialog", "Mode of operation", 0));
        ECB_RB->setText(QApplication::translate("aesDialog", "ECB (ELectronic Codebook)", 0));
        CBC_RB->setText(QApplication::translate("aesDialog", "CBC (Cipher Block Chaining)", 0));
        CFB_RB->setText(QApplication::translate("aesDialog", "CFB (Cipher Feedback)", 0));
        groupBox_4->setTitle(QApplication::translate("aesDialog", "Key", 0));
        label->setText(QApplication::translate("aesDialog", "Key (Hex)", 0));
        keyEdit->setText(QApplication::translate("aesDialog", "0123456789ABCDEF0123456789ABCDEF", 0));
        label_2->setText(QApplication::translate("aesDialog", "Initialization Vector (Hex)", 0));
        ivEdit->setText(QApplication::translate("aesDialog", "AAAABBBBCCCCDDDDEEEEFFFFAAAAFFFF", 0));
        timeLabel->setText(QApplication::translate("aesDialog", "Execution time:", 0));
        pushButton_2->setText(QApplication::translate("aesDialog", "Encrypt", 0));
        pushButton_3->setText(QApplication::translate("aesDialog", "Decrypt", 0));
        statPB->setText(QApplication::translate("aesDialog", "Matlab Code for Statistical Analysis", 0));
        pushButton_4->setText(QApplication::translate("aesDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class aesDialog: public Ui_aesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AESDIALOG_H
