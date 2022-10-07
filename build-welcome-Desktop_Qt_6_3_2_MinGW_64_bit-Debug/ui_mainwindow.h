/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QPushButton *enter;
    QPushButton *pushButton;
    QLabel *image;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 452);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2, 0, Qt::AlignVCenter);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setStyleSheet(QString::fromUtf8("*{background-color:rgb(218, 218, 218);}"));

        horizontalLayout->addWidget(lineEdit_username);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3, 0, Qt::AlignVCenter);

        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("*{background-color:rgb(216, 216, 216);}"));

        horizontalLayout->addWidget(lineEdit_password);

        enter = new QPushButton(centralwidget);
        enter->setObjectName(QString::fromUtf8("enter"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Script")});
        font.setPointSize(12);
        enter->setFont(font);
        enter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(enter);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("*{background-color:rgb(207, 207, 207);\n"
"}"));

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignBottom);


        verticalLayout->addLayout(horizontalLayout);

        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));

        verticalLayout->addWidget(image, 0, Qt::AlignHCenter);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("*{\n"
"text color:white:\n"
"}"));

        verticalLayout->addWidget(label, 0, Qt::AlignVCenter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#ffffff;\">Email:</span></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_username->setWhatsThis(QCoreApplication::translate("MainWindow", "<html>\n"
"<body bgcolor=\"white\">\n"
"<input type=\"password\">\n"
"</body>\n"
"</html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_username->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#ffffff;\">Password:</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_password->setToolTip(QCoreApplication::translate("MainWindow", "<html>\n"
"<body>\n"
"<input type=\"password\">\n"
"</body>\n"
"</html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_password->setWhatsThis(QCoreApplication::translate("MainWindow", "<html>\n"
"<body>\n"
"<input type=\"password\">\n"
"</body>\n"
"</html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_password->setText(QString());
        enter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Don't have an account? Sign Up Now!", nullptr));
        image->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">FOCUS ON BEING PRODUCTIVE INSTEAD OF BUSY</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
