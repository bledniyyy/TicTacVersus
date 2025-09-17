/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QSlider *VolumeMusicSlider;
    QLabel *GromkostLabel;
    QPushButton *returnToMenuButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(377, 551);
        VolumeMusicSlider = new QSlider(Form);
        VolumeMusicSlider->setObjectName(QString::fromUtf8("VolumeMusicSlider"));
        VolumeMusicSlider->setGeometry(QRect(190, 90, 151, 16));
        VolumeMusicSlider->setOrientation(Qt::Horizontal);
        GromkostLabel = new QLabel(Form);
        GromkostLabel->setObjectName(QString::fromUtf8("GromkostLabel"));
        GromkostLabel->setGeometry(QRect(20, 90, 161, 16));
        returnToMenuButton = new QPushButton(Form);
        returnToMenuButton->setObjectName(QString::fromUtf8("returnToMenuButton"));
        returnToMenuButton->setGeometry(QRect(130, 330, 80, 23));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        GromkostLabel->setText(QCoreApplication::translate("Form", "\320\223\321\200\320\276\320\274\320\272\320\276\321\201\321\202\321\214 \320\274\321\203\320\267\321\213\320\272\320\270", nullptr));
        returnToMenuButton->setText(QCoreApplication::translate("Form", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
