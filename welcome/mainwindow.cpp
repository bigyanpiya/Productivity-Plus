#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ad.h"
#include<QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
     members=QSqlDatabase::addDatabase("QSQLITE");
          members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
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


//QString putInternal(QString q_query){
//        std::string query = q_query.toLocal8Bit().constData();
//        std::string local,global;
//        for(auto e:query){
//            if(e==','){
//                global+=local;
//                global+='\n';
//                local="";
//            }else local+=e;
//        }
//        global+=local;
//
//        return QString::fromLocal8Bit(global);
//
//}

void MainWindow::on_enter_clicked()
{


    QString username = ui->lineEdit_username->text();
    this->_username = username;
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



void MainWindow::on_pushButton_2_clicked()
{
                  ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked() {
    dial3 = new ad(nullptr, this->_username);
    dial3->show();
}
