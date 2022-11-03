#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include"mainwindow1.h"
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow1 *dial;
       QSqlDatabase members;
};
#endif // MAINWINDOW_H
