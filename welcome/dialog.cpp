#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_signup_2_clicked()
{
    {
        members= QSqlDatabase::addDatabase("QSQLITE");
       members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
       if (!members.open()){
          qDebug("failed");
       }else{
          qDebug("sucessfool"); }
          if (!members.open()){
    ui->label->setText("Failed to open the data base");
          }else{
    ui->label->setText("Connected sucessfully"); }

          QString query = "CREATE TABLE memberss("
                          "Name VARCHAR(20),"
                          "username VARCHAR(20) ,"
                          "password VARCHAR(20));";
          QString name = ui->line1->text();
          QString username = ui->line2->text();
          QString password = ui->line3->text();
          QSqlQuery qry;
          qry.prepare("INSERT INTO memberss("
                      "Name,"
                      "username,"
                      "password)"
                      "VALUES(:Name,:username,:password);");

          qry.bindValue(":Name", name);
          qry.bindValue(":username", username);
          qry.bindValue(":password", password);
          if(qry.exec()){
              qDebug("sucess updating data ");
              QMessageBox::information(this, "Saved","<FONT COLOR='green'>Sucess updating data</FONT>");
          }
          else{
              QMessageBox::critical(this, " not Saved","<FONT COLOR='red'>Error updating data</FONT>");
          }

          if(!qry.exec(query)){
              qDebug("error creating table // it may already exxist");
          }
          members.close();

          qDebug("Db.closed");

    }
}

