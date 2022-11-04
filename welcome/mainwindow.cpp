#include "mainwindow.h"
#include "mainwindow1.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     members=QSqlDatabase::addDatabase("QSQLITE");
           members.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/db/member.db");
           if( members.open())
                   ui->label_4->setText("Connected");
           else
               ui->label->setText("Not");

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
      if( !members.isOpen()){
          qDebug()<<"Failed to open";
          return;

      }
      QSqlQuery qry;
      if (qry.exec("select * from members where username = '" +username + "'  and password  ='" + password +"'"  )){
        int count = 0;
          while(qry.next()){
              count++;

          }
          if(count==1){

              hide();
              dial=new MainWindow1(this);
              dial->showMaximized();}
         else{
              QMessageBox::about(this,"Error", "Enter correct username and password");
          }



      }




}


void MainWindow::on_pushButton_clicked()
{
    hide();
    dial= new MainWindow2(this);
}

