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
           members.setDatabaseName("E:/Productivity-Plus/welcome/member.db");
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
      if (qry.exec("select * from members where username = '" +username + "'  and password  ='" + password +"'")){
          while(qry.next()){
              QString name = qry.value(1).toString();
              ui->nameLabel->setText(name);
              ui->stackedWidget->setCurrentIndex(1);
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
          QMessageBox::about(this,"OPPPSSS", "Enter correct username and password");
      }




}



void MainWindow::on_pushButton_clicked()
{
              ui->stackedWidget->setCurrentIndex(2);
}




void MainWindow::on_calendar_clicked(const QDate &date)
{
    dial=new calpop;
    dial->show();

}

