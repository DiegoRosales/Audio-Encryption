/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *addressEdit;
    QPushButton *browsePushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *liveButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *getInfoPushButton;
    QPushButton *viewPushButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *binaryRadioButton;
    QRadioButton *decimalRadioButton;
    QRadioButton *hexadecimalRadioButton;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *shOffsetRadioButton;
    QRadioButton *mlPlotRadioButton;
    QRadioButton *dshOffsetRadioButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *cesarButton;
    QPushButton *vigenereButton;
    QPushButton *aesButton;
    QPushButton *desButton;
    QPushButton *rc4Button;
    QPushButton *rsaButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(388, 312);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        addressEdit = new QComboBox(centralWidget);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy1);
        addressEdit->setEditable(true);

        horizontalLayout_2->addWidget(addressEdit);

        browsePushButton = new QPushButton(centralWidget);
        browsePushButton->setObjectName(QStringLiteral("browsePushButton"));

        horizontalLayout_2->addWidget(browsePushButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        liveButton = new QPushButton(centralWidget);
        liveButton->setObjectName(QStringLiteral("liveButton"));

        horizontalLayout_3->addWidget(liveButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        getInfoPushButton = new QPushButton(groupBox);
        getInfoPushButton->setObjectName(QStringLiteral("getInfoPushButton"));

        verticalLayout_3->addWidget(getInfoPushButton);

        viewPushButton = new QPushButton(groupBox);
        viewPushButton->setObjectName(QStringLiteral("viewPushButton"));

        verticalLayout_3->addWidget(viewPushButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        binaryRadioButton = new QRadioButton(groupBox_3);
        binaryRadioButton->setObjectName(QStringLiteral("binaryRadioButton"));
        binaryRadioButton->setChecked(false);
        binaryRadioButton->setAutoExclusive(true);

        verticalLayout->addWidget(binaryRadioButton);

        decimalRadioButton = new QRadioButton(groupBox_3);
        decimalRadioButton->setObjectName(QStringLiteral("decimalRadioButton"));
        decimalRadioButton->setChecked(true);

        verticalLayout->addWidget(decimalRadioButton);

        hexadecimalRadioButton = new QRadioButton(groupBox_3);
        hexadecimalRadioButton->setObjectName(QStringLiteral("hexadecimalRadioButton"));

        verticalLayout->addWidget(hexadecimalRadioButton, 0, Qt::AlignLeft);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        shOffsetRadioButton = new QRadioButton(groupBox_4);
        shOffsetRadioButton->setObjectName(QStringLiteral("shOffsetRadioButton"));
        shOffsetRadioButton->setChecked(true);

        verticalLayout_2->addWidget(shOffsetRadioButton);

        mlPlotRadioButton = new QRadioButton(groupBox_4);
        mlPlotRadioButton->setObjectName(QStringLiteral("mlPlotRadioButton"));

        verticalLayout_2->addWidget(mlPlotRadioButton);

        dshOffsetRadioButton = new QRadioButton(groupBox_4);
        dshOffsetRadioButton->setObjectName(QStringLiteral("dshOffsetRadioButton"));

        verticalLayout_2->addWidget(dshOffsetRadioButton);


        horizontalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout_4->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cesarButton = new QPushButton(groupBox_2);
        cesarButton->setObjectName(QStringLiteral("cesarButton"));
        sizePolicy1.setHeightForWidth(cesarButton->sizePolicy().hasHeightForWidth());
        cesarButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cesarButton, 0, 0, 1, 1);

        vigenereButton = new QPushButton(groupBox_2);
        vigenereButton->setObjectName(QStringLiteral("vigenereButton"));
        sizePolicy1.setHeightForWidth(vigenereButton->sizePolicy().hasHeightForWidth());
        vigenereButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(vigenereButton, 1, 0, 1, 1);

        aesButton = new QPushButton(groupBox_2);
        aesButton->setObjectName(QStringLiteral("aesButton"));
        sizePolicy1.setHeightForWidth(aesButton->sizePolicy().hasHeightForWidth());
        aesButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(aesButton, 1, 1, 1, 1);

        desButton = new QPushButton(groupBox_2);
        desButton->setObjectName(QStringLiteral("desButton"));
        sizePolicy1.setHeightForWidth(desButton->sizePolicy().hasHeightForWidth());
        desButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(desButton, 0, 1, 1, 1);

        rc4Button = new QPushButton(groupBox_2);
        rc4Button->setObjectName(QStringLiteral("rc4Button"));
        sizePolicy1.setHeightForWidth(rc4Button->sizePolicy().hasHeightForWidth());
        rc4Button->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(rc4Button, 0, 2, 1, 1);

        rsaButton = new QPushButton(groupBox_2);
        rsaButton->setObjectName(QStringLiteral("rsaButton"));
        sizePolicy1.setHeightForWidth(rsaButton->sizePolicy().hasHeightForWidth());
        rsaButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(rsaButton, 1, 2, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 388, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(mlPlotRadioButton, SIGNAL(toggled(bool)), binaryRadioButton, SLOT(setDisabled(bool)));
        QObject::connect(mlPlotRadioButton, SIGNAL(toggled(bool)), hexadecimalRadioButton, SLOT(setDisabled(bool)));
        QObject::connect(mlPlotRadioButton, SIGNAL(toggled(bool)), decimalRadioButton, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Audio Cipher", 0));
        label->setText(QApplication::translate("MainWindow", "Wave file:", 0));
        addressEdit->clear();
        addressEdit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "D:/Test/Test Files/440SineWave8bit.wav", 0)
         << QApplication::translate("MainWindow", "D:/Test/Test Files/test.wav", 0)
         << QApplication::translate("MainWindow", "D:/Test/Test Files/13 Geograf\303\255a.wav", 0)
         << QApplication::translate("MainWindow", "D:/Test/Test Files/01 The Circle of Life.wav", 0)
        );
        addressEdit->setCurrentText(QApplication::translate("MainWindow", "D:/Test/Test Files/440SineWave8bit.wav", 0));
        browsePushButton->setText(QApplication::translate("MainWindow", "Browse...", 0));
        liveButton->setText(QApplication::translate("MainWindow", "Live encryption", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "View audio data", 0));
        getInfoPushButton->setText(QApplication::translate("MainWindow", "Get .wav info", 0));
        viewPushButton->setText(QApplication::translate("MainWindow", "View raw data", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Format type", 0));
        binaryRadioButton->setText(QApplication::translate("MainWindow", "Binary", 0));
        decimalRadioButton->setText(QApplication::translate("MainWindow", "Decimal", 0));
        hexadecimalRadioButton->setText(QApplication::translate("MainWindow", "Hexadecimal", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Misc", 0));
        shOffsetRadioButton->setText(QApplication::translate("MainWindow", "Show offset", 0));
        mlPlotRadioButton->setText(QApplication::translate("MainWindow", "Matlab plot", 0));
        dshOffsetRadioButton->setText(QApplication::translate("MainWindow", "Don't show offset", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Encryption", 0));
        cesarButton->setText(QApplication::translate("MainWindow", "Caesar Cipher", 0));
        vigenereButton->setText(QApplication::translate("MainWindow", "Vigenere Cipher", 0));
        aesButton->setText(QApplication::translate("MainWindow", "AES", 0));
        desButton->setText(QApplication::translate("MainWindow", "DES", 0));
        rc4Button->setText(QApplication::translate("MainWindow", "RC4", 0));
        rsaButton->setText(QApplication::translate("MainWindow", "RSA", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
