#include "mainwindow.h"
#include "page1.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/OneDrive/Documents/logo.png");
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
   dial=new page1(this);
   dial->show();

}
    else{
        QMessageBox::warning(this,"Email or Password is incorrect","Try Again");
    }
}

