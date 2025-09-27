/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QPushButton *StartButton;
    QGridLayout *gridLayout;
    QToolButton *OffMusic;
    QGroupBox *gameFieldBox;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gameField;
    QToolButton *cell_2_2;
    QToolButton *cell_1_0;
    QToolButton *cell_2_1;
    QToolButton *cell_0_1;
    QToolButton *cell_0_2;
    QToolButton *cell_2_0;
    QToolButton *cell_1_1;
    QToolButton *cell_1_2;
    QToolButton *cell_0_0;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(500, 650);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(500, 650));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(130, 210, 261, 111));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        StartButton = new QPushButton(verticalLayoutWidget_2);
        StartButton->setObjectName("StartButton");

        verticalLayout_4->addWidget(StartButton);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        OffMusic = new QToolButton(verticalLayoutWidget_2);
        OffMusic->setObjectName("OffMusic");

        gridLayout->addWidget(OffMusic, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        gameFieldBox = new QGroupBox(centralwidget);
        gameFieldBox->setObjectName("gameFieldBox");
        gameFieldBox->setEnabled(true);
        gameFieldBox->setGeometry(QRect(60, 80, 361, 381));
        verticalLayout_6 = new QVBoxLayout(gameFieldBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        gameField = new QGridLayout();
        gameField->setObjectName("gameField");
        gameField->setSizeConstraint(QLayout::SetNoConstraint);
        cell_2_2 = new QToolButton(gameFieldBox);
        cell_2_2->setObjectName("cell_2_2");
        sizePolicy.setHeightForWidth(cell_2_2->sizePolicy().hasHeightForWidth());
        cell_2_2->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_2_2, 2, 2, 1, 1);

        cell_1_0 = new QToolButton(gameFieldBox);
        cell_1_0->setObjectName("cell_1_0");
        sizePolicy.setHeightForWidth(cell_1_0->sizePolicy().hasHeightForWidth());
        cell_1_0->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_1_0, 1, 0, 1, 1);

        cell_2_1 = new QToolButton(gameFieldBox);
        cell_2_1->setObjectName("cell_2_1");
        sizePolicy.setHeightForWidth(cell_2_1->sizePolicy().hasHeightForWidth());
        cell_2_1->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_2_1, 2, 1, 1, 1);

        cell_0_1 = new QToolButton(gameFieldBox);
        cell_0_1->setObjectName("cell_0_1");
        sizePolicy.setHeightForWidth(cell_0_1->sizePolicy().hasHeightForWidth());
        cell_0_1->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_0_1, 0, 1, 1, 1);

        cell_0_2 = new QToolButton(gameFieldBox);
        cell_0_2->setObjectName("cell_0_2");
        sizePolicy.setHeightForWidth(cell_0_2->sizePolicy().hasHeightForWidth());
        cell_0_2->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_0_2, 0, 2, 1, 1);

        cell_2_0 = new QToolButton(gameFieldBox);
        cell_2_0->setObjectName("cell_2_0");
        sizePolicy.setHeightForWidth(cell_2_0->sizePolicy().hasHeightForWidth());
        cell_2_0->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_2_0, 2, 0, 1, 1);

        cell_1_1 = new QToolButton(gameFieldBox);
        cell_1_1->setObjectName("cell_1_1");
        sizePolicy.setHeightForWidth(cell_1_1->sizePolicy().hasHeightForWidth());
        cell_1_1->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_1_1, 1, 1, 1, 1);

        cell_1_2 = new QToolButton(gameFieldBox);
        cell_1_2->setObjectName("cell_1_2");
        cell_1_2->setEnabled(true);
        sizePolicy.setHeightForWidth(cell_1_2->sizePolicy().hasHeightForWidth());
        cell_1_2->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_1_2, 1, 2, 1, 1);

        cell_0_0 = new QToolButton(gameFieldBox);
        cell_0_0->setObjectName("cell_0_0");
        sizePolicy.setHeightForWidth(cell_0_0->sizePolicy().hasHeightForWidth());
        cell_0_0->setSizePolicy(sizePolicy);

        gameField->addWidget(cell_0_0, 0, 0, 1, 1);


        verticalLayout_6->addLayout(gameField);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        StartButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
        OffMusic->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        gameFieldBox->setTitle(QString());
        cell_2_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_1_0->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_2_1->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_0_1->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_0_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_2_0->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_1_1->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_1_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        cell_0_0->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
