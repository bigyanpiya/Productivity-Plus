/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_page1
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *page1)
    {
        if (page1->objectName().isEmpty())
            page1->setObjectName(QString::fromUtf8("page1"));
        page1->resize(1920, 768);
        verticalLayout = new QVBoxLayout(page1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_2 = new QPushButton(page1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(page1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        calendarWidget = new QCalendarWidget(page1);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        retranslateUi(page1);

        QMetaObject::connectSlotsByName(page1);
    } // setupUi

    void retranslateUi(QDialog *page1)
    {
        page1->setWindowTitle(QCoreApplication::translate("page1", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("page1", "Reminder", nullptr));
        pushButton->setText(QCoreApplication::translate("page1", "Add course", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page1: public Ui_page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
