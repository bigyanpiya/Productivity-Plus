#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include"calpop.h"
#include"ad.h"
#include"dialog.h"
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString _username;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_clicked();

//    void on_pushButton_clicked();

    void on_pushButton_clicked();


    void on_calendar_clicked(const QDate &date);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    calpop *dial;
    Dialog *dial1;
    ad *dial3;



//    MainWindow2 *dial2;


       QSqlDatabase members;
};
#endif // MAINWINDOW_H
