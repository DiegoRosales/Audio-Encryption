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
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *InputCbox;
    QPushButton *Browse1;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *OutputCbox;
    QPushButton *Browse2;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *aesDialog)
    {
        if (aesDialog->objectName().isEmpty())
            aesDialog->setObjectName(QStringLiteral("aesDialog"));
        aesDialog->resize(445, 290);
        verticalLayout_2 = new QVBoxLayout(aesDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(aesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        InputCbox = new QComboBox(groupBox);
        InputCbox->setObjectName(QStringLiteral("InputCbox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputCbox->sizePolicy().hasHeightForWidth());
        InputCbox->setSizePolicy(sizePolicy);
        InputCbox->setEditable(true);

        horizontalLayout_2->addWidget(InputCbox);

        Browse1 = new QPushButton(groupBox);
        Browse1->setObjectName(QStringLiteral("Browse1"));

        horizontalLayout_2->addWidget(Browse1);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        OutputCbox = new QComboBox(groupBox);
        OutputCbox->setObjectName(QStringLiteral("OutputCbox"));
        sizePolicy.setHeightForWidth(OutputCbox->sizePolicy().hasHeightForWidth());
        OutputCbox->setSizePolicy(sizePolicy);
        OutputCbox->setEditable(true);

        horizontalLayout_4->addWidget(OutputCbox);

        Browse2 = new QPushButton(groupBox);
        Browse2->setObjectName(QStringLiteral("Browse2"));

        horizontalLayout_4->addWidget(Browse2);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

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


        verticalLayout_2->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(aesDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_2 = new QPushButton(aesDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(aesDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(aesDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(aesDialog);
        QObject::connect(pushButton_4, SIGNAL(clicked()), aesDialog, SLOT(close()));
        QObject::connect(ECB_RB, SIGNAL(toggled(bool)), ivEdit, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(aesDialog);
    } // setupUi

    void retranslateUi(QDialog *aesDialog)
    {
        aesDialog->setWindowTitle(QApplication::translate("aesDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("aesDialog", "Input/Output", 0));
        InputCbox->clear();
        InputCbox->insertItems(0, QStringList()
         << QApplication::translate("aesDialog", "D:/Test/Test Files/test.wav", 0)
        );
        Browse1->setText(QApplication::translate("aesDialog", "Browse...", 0));
        OutputCbox->clear();
        OutputCbox->insertItems(0, QStringList()
         << QApplication::translate("aesDialog", "D:/Test/AES Encryption.wav", 0)
         << QApplication::translate("aesDialog", "D:/Test/AES Decryption.wav", 0)
        );
        Browse2->setText(QApplication::translate("aesDialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("aesDialog", "Stream cipher", 0));
        ECB_RB->setText(QApplication::translate("aesDialog", "ECB (ELectronic Codebook)", 0));
        CBC_RB->setText(QApplication::translate("aesDialog", "CBC (Cipher Block Chaining)", 0));
        CFB_RB->setText(QApplication::translate("aesDialog", "CFB (Cipher Feedback)", 0));
        groupBox_4->setTitle(QApplication::translate("aesDialog", "Key", 0));
        label->setText(QApplication::translate("aesDialog", "Key (Hex)", 0));
        keyEdit->setText(QApplication::translate("aesDialog", "0123456789ABCDEF0123456789ABCDEF", 0));
        label_2->setText(QApplication::translate("aesDialog", "Initialization Vector (Hex)", 0));
        ivEdit->setText(QApplication::translate("aesDialog", "AAAABBBBCCCCDDDDEEEEFFFFAAAAFFFF", 0));
        pushButton_2->setText(QApplication::translate("aesDialog", "Encrypt", 0));
        pushButton_3->setText(QApplication::translate("aesDialog", "Decrypt", 0));
        pushButton_4->setText(QApplication::translate("aesDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class aesDialog: public Ui_aesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AESDIALOG_H
