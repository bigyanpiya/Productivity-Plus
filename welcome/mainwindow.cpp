#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
     members=QSqlDatabase::addDatabase("QSQLITE");
          members.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/git/Productivity-Plus/welcome/time.db");
           if( members.open())
                   ui->label_4->setText("Connected");
           else
               ui->label->setText("Not");

    QPixmap pix(":/img/photos/logo.png");
    ui->image->setPixmap(pix);
//    members.close();
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
      if (qry.exec("select * from memberss where username = '" +username + "'  and password  ='" + password +"'")){

          while(qry.next()){
              ui->stackedWidget->setCurrentIndex(1);
             QString books = qry.value(3).toString();
             ui->nameLabel->setText(books);
             QString internal = qry.value(4).toString();
             ui->nameLabel_1->setText(internal);
             QString assignment = qry.value(5).toString();
             ui->nameLabel_2->setText(assignment);
             QString project = qry.value(6).toString();
             ui->nameLabel_3->setText(project);

          };
//        int count = 0;
//          while(qry.next()){
//              count++;
//          }
//          if(count==1){
              /*hide();
              dial=new MainWindow1(this);
              dial->showMaximized();*/

          }
      else{
          QMessageBox::critical(this,"ERROR", "<FONT COLOR='red'>Enter Correct username or password</FONT>");
          }
      }







void MainWindow::on_pushButton_clicked()
{
              //ui->stackedWidget->setCurrentIndex(2);
    dial1=new Dialog;
    dial1->show();
}




void MainWindow::on_calendar_clicked(const QDate &) //&date)
{
    dial=new calpop;
    dial->show();

}


