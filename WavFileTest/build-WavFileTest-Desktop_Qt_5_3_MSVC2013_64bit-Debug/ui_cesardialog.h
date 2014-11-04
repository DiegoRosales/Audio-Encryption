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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CesarDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *CesarDialog)
    {
        if (CesarDialog->objectName().isEmpty())
            CesarDialog->setObjectName(QStringLiteral("CesarDialog"));
        CesarDialog->resize(134, 150);
        verticalLayout_2 = new QVBoxLayout(CesarDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CesarDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(CesarDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(CesarDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(CesarDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(CesarDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CesarDialog);
        QObject::connect(pushButton_3, SIGNAL(clicked()), CesarDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CesarDialog);
    } // setupUi

    void retranslateUi(QDialog *CesarDialog)
    {
        CesarDialog->setWindowTitle(QApplication::translate("CesarDialog", "Cesar Cipher", 0));
        label->setText(QApplication::translate("CesarDialog", "Key", 0));
        pushButton->setText(QApplication::translate("CesarDialog", "Cipher", 0));
        pushButton_2->setText(QApplication::translate("CesarDialog", "Decipher", 0));
        pushButton_3->setText(QApplication::translate("CesarDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CesarDialog: public Ui_CesarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CESARDIALOG_H
