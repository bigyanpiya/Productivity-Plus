#include "mainwindow.h"
#include "mainwindow1.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/photos/logo.png");
    ui->image->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_enter_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if (username ==  "admin" && password=="admin"){
   hide();
   dial=new MainWindow1(this);
   dial->showMaximized();
}
    else{
        QMessageBox::warning(this,"Email or Password is incorrect","Try Again");
    }
}

