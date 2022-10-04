/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;
    QPushButton *Events;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        calendarWidget = new QCalendarWidget(Dialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 1, 3, 1);

        Events = new QPushButton(Dialog);
        Events->setObjectName(QString::fromUtf8("Events"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Terminal")});
        Events->setFont(font1);

        gridLayout->addWidget(Events, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Reminder", nullptr));
        Events->setText(QCoreApplication::translate("Dialog", "Events", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
