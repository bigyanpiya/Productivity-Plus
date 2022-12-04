#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include"calpop.h"
#include"ad.h"
#include"dialog.h"
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<ui_mainwindow.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    QString _username;



    void putAssignmentsIntoDb(vector<QString>& assgs);
      void putInternalsIntoDb(vector<QString>& inter);
      void putBooksIntoDb(vector<QString>& bok);
    vector<QString> getAllAssignments();
       vector<QString> getAllInternals();
       vector<QString> getAllBooks();


    void updateAssignment(QString assignments){
        string __assignments  = "1. " + assignments.toStdString();
        int i = 2;
        while(__assignments.find(",") != string::npos){
            __assignments.replace(__assignments.find(","), strlen(","), "\n" +to_string(i) + ". ");
            i++;
        }
        ui->nameLabel_2->setText(QString::fromStdString(__assignments));
    }
    void updateInternal(QString internals){
        string __internals = "1. " + internals.toStdString();
        int i = 2;
        while(__internals.find(",") != string::npos){
            __internals.replace(__internals.find(","), strlen(","), "\n" +to_string(i) + ". ");
            i++;
        }
        ui->nameLabel_1->setText(QString::fromStdString(__internals));
    }


    void updateBook(QString books){
        string __books = "1. " + books.toStdString();
        int i = 2;
        while(__books.find(",") != string::npos){
            __books.replace(__books.find(","), strlen(","), "\n" +to_string(i) + ". ");
            i++;
        }
        ui->nameLabel_4->setText(QString::fromStdString(__books));

    }
    void updateproject(QString projects){
        string __projects = "1. " + projects.toStdString();
        int i = 2;
        while(__projects.find(",") != string::npos){
            __projects.replace(__projects.find(","), strlen(","), "\n" +to_string(i) + ". ");
            i++;
        }
        ui->nameLabel_3->setText(QString::fromStdString(__projects));

    }


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_enter_clicked();

//    void on_pushButton_clicked();

    void on_pushButton_clicked();


    void on_calendar_clicked(const QDate &date);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


    void on_pushButton_10_clicked();

    void on_calendar_activated(const QDate &date);

private:
    Ui::MainWindow *ui;

    calpop *dial;
    Dialog *dial1;
    ad *dial3;
//    MainWindow2 *dial2;

   QSqlDatabase members;
};
#endif // MAINWINDOW_H
