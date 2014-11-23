/********************************************************************************
** Form generated from reading UI file 'cesardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CESARDIALOG_H
#define UI_CESARDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CesarDialog
{
public:
    QVBoxLayout *verticalLayout_4;
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
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QDialog *CesarDialog)
    {
        if (CesarDialog->objectName().isEmpty())
            CesarDialog->setObjectName(QStringLiteral("CesarDialog"));
        CesarDialog->resize(350, 224);
        verticalLayout_4 = new QVBoxLayout(CesarDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(CesarDialog);
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


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CesarDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addWidget(groupBox_2);

        timeLabel = new QLabel(CesarDialog);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_4->addWidget(timeLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(CesarDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout);

        pushButton = new QPushButton(CesarDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(CesarDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(CesarDialog);
        QObject::connect(pushButton_3, SIGNAL(clicked()), CesarDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CesarDialog);
    } // setupUi

    void retranslateUi(QDialog *CesarDialog)
    {
        CesarDialog->setWindowTitle(QApplication::translate("CesarDialog", "Caesar Cipher", 0));
        groupBox->setTitle(QApplication::translate("CesarDialog", "Input/Output", 0));
        label_3->setText(QApplication::translate("CesarDialog", "Input: ", 0));
        label_4->setText(QApplication::translate("CesarDialog", "Output: ", 0));
        InputCbox->clear();
        InputCbox->insertItems(0, QStringList()
         << QApplication::translate("CesarDialog", "D:/Test/Test Files/test.wav", 0)
         << QApplication::translate("CesarDialog", "D:/Test/Caesar Encryption.wav", 0)
        );
        OutputCbox->clear();
        OutputCbox->insertItems(0, QStringList()
         << QApplication::translate("CesarDialog", "D:/Test/Caesar Encryption.wav", 0)
         << QApplication::translate("CesarDialog", "D:/Test/Caesar Decryption.wav", 0)
        );
        BrowseIn->setText(QApplication::translate("CesarDialog", "Browse...", 0));
        BrowseOut->setText(QApplication::translate("CesarDialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("CesarDialog", "Key", 0));
        timeLabel->setText(QApplication::translate("CesarDialog", "Execution time:", 0));
        pushButton_2->setText(QApplication::translate("CesarDialog", "Decrypt", 0));
        pushButton->setText(QApplication::translate("CesarDialog", "Encrypt", 0));
        pushButton_3->setText(QApplication::translate("CesarDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CesarDialog: public Ui_CesarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CESARDIALOG_H
