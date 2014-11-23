/********************************************************************************
** Form generated from reading UI file 'rc4dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RC4DIALOG_H
#define UI_RC4DIALOG_H

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

class Ui_RC4Dialog
{
public:
    QVBoxLayout *verticalLayout_8;
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
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *statPB;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *RC4Dialog)
    {
        if (RC4Dialog->objectName().isEmpty())
            RC4Dialog->setObjectName(QStringLiteral("RC4Dialog"));
        RC4Dialog->resize(400, 346);
        verticalLayout_8 = new QVBoxLayout(RC4Dialog);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox = new QGroupBox(RC4Dialog);
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


        verticalLayout_8->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(RC4Dialog);
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

        groupBox_4 = new QGroupBox(RC4Dialog);
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


        verticalLayout_8->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(RC4Dialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_8->addWidget(progressBar);

        timeLabel = new QLabel(RC4Dialog);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_8->addWidget(timeLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(RC4Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(RC4Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);

        statPB = new QPushButton(RC4Dialog);
        statPB->setObjectName(QStringLiteral("statPB"));

        verticalLayout_2->addWidget(statPB);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pushButton_4 = new QPushButton(RC4Dialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_5);


        retranslateUi(RC4Dialog);
        QObject::connect(pushButton_4, SIGNAL(clicked()), RC4Dialog, SLOT(close()));
        QObject::connect(ECB_RB, SIGNAL(toggled(bool)), ivEdit, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(RC4Dialog);
    } // setupUi

    void retranslateUi(QDialog *RC4Dialog)
    {
        RC4Dialog->setWindowTitle(QApplication::translate("RC4Dialog", "Rivest Code 4", 0));
        groupBox->setTitle(QApplication::translate("RC4Dialog", "Input/Output", 0));
        label_3->setText(QApplication::translate("RC4Dialog", "Input: ", 0));
        label_4->setText(QApplication::translate("RC4Dialog", "Output: ", 0));
        InputCbox->clear();
        InputCbox->insertItems(0, QStringList()
         << QApplication::translate("RC4Dialog", "D:/Test/Test Files/test.wav", 0)
         << QApplication::translate("RC4Dialog", "D:/Test/RC4 Encryption.wav", 0)
        );
        OutputCbox->clear();
        OutputCbox->insertItems(0, QStringList()
         << QApplication::translate("RC4Dialog", "D:/Test/RC4 Encryption.wav", 0)
         << QApplication::translate("RC4Dialog", "D:/Test/RC4 Decryption.wav", 0)
        );
        BrowseIn->setText(QApplication::translate("RC4Dialog", "Browse...", 0));
        BrowseOut->setText(QApplication::translate("RC4Dialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("RC4Dialog", "Mode of operation", 0));
        ECB_RB->setText(QApplication::translate("RC4Dialog", "Stream", 0));
        CBC_RB->setText(QApplication::translate("RC4Dialog", "CBC (Cipher Block Chaining)", 0));
        CFB_RB->setText(QApplication::translate("RC4Dialog", "CFB (Cipher Feedback)", 0));
        groupBox_4->setTitle(QApplication::translate("RC4Dialog", "Key", 0));
        label->setText(QApplication::translate("RC4Dialog", "Key (Hex)", 0));
        keyEdit->setText(QApplication::translate("RC4Dialog", "0123456789ABCDEF0123456789ABCDEF", 0));
        label_2->setText(QApplication::translate("RC4Dialog", "Initialization Vector (Hex)", 0));
        ivEdit->setText(QApplication::translate("RC4Dialog", "AAAABBBBCCCCDDDDEEEEFFFFAAAAFFFF", 0));
        timeLabel->setText(QApplication::translate("RC4Dialog", "Execution Time: ", 0));
        pushButton_2->setText(QApplication::translate("RC4Dialog", "Encrypt", 0));
        pushButton_3->setText(QApplication::translate("RC4Dialog", "Decrypt", 0));
        statPB->setText(QApplication::translate("RC4Dialog", "Matlab Code for Statistical Analysis", 0));
        pushButton_4->setText(QApplication::translate("RC4Dialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class RC4Dialog: public Ui_RC4Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RC4DIALOG_H
