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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aesDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *aesDialog)
    {
        if (aesDialog->objectName().isEmpty())
            aesDialog->setObjectName(QStringLiteral("aesDialog"));
        aesDialog->resize(437, 230);
        verticalLayout_2 = new QVBoxLayout(aesDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(aesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setEditable(true);

        horizontalLayout_2->addWidget(comboBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(aesDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(aesDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));

        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(aesDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);


        horizontalLayout_3->addWidget(groupBox_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

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

        QMetaObject::connectSlotsByName(aesDialog);
    } // setupUi

    void retranslateUi(QDialog *aesDialog)
    {
        aesDialog->setWindowTitle(QApplication::translate("aesDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("aesDialog", "Output file", 0));
        pushButton->setText(QApplication::translate("aesDialog", "Browse...", 0));
        groupBox_2->setTitle(QApplication::translate("aesDialog", "Stream cipher", 0));
        groupBox_3->setTitle(QApplication::translate("aesDialog", "Size", 0));
        groupBox_4->setTitle(QApplication::translate("aesDialog", "Key", 0));
        label->setText(QApplication::translate("aesDialog", "Key (Hex)", 0));
        label_2->setText(QApplication::translate("aesDialog", "Initialization Vector (Hex)", 0));
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
