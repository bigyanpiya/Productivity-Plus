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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_page1
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *page1)
    {
        if (page1->objectName().isEmpty())
            page1->setObjectName(QString::fromUtf8("page1"));
        page1->resize(1920, 768);
        page1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        verticalLayout = new QVBoxLayout(page1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton = new QToolButton(page1);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        verticalLayout->addWidget(toolButton, 0, Qt::AlignRight);

        toolButton_2 = new QToolButton(page1);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        verticalLayout->addWidget(toolButton_2, 0, Qt::AlignRight);

        pushButton_2 = new QPushButton(page1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(78, 79, 80);"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(page1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 79, 80);"));

        verticalLayout->addWidget(pushButton);

        calendarWidget = new QCalendarWidget(page1);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setAutoFillBackground(false);
        calendarWidget->setStyleSheet(QString::fromUtf8("*{\n"
"navagationBar color=blue;\n"
"}"));
        calendarWidget->setNavigationBarVisible(true);

        verticalLayout->addWidget(calendarWidget);


        retranslateUi(page1);

        QMetaObject::connectSlotsByName(page1);
    } // setupUi

    void retranslateUi(QDialog *page1)
    {
        page1->setWindowTitle(QCoreApplication::translate("page1", "Dialog", nullptr));
        toolButton->setText(QCoreApplication::translate("page1", "[ ]", nullptr));
        toolButton_2->setText(QCoreApplication::translate("page1", "--", nullptr));
        pushButton_2->setText(QCoreApplication::translate("page1", "Reminder", nullptr));
        pushButton->setText(QCoreApplication::translate("page1", "Add course", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page1: public Ui_page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
