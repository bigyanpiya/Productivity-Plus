#include "add.h"
#include "ui_add.h"
#include <QDebug>
#include <QMessageBox>

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()
        {
            members= QSqlDatabase::addDatabase("QSQLITE");
           members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
           if (!members.open()){
              qDebug("failed");
           }else{
              qDebug("sucessfool"); }
              if (!members.open()){
        ui->label0->setText("Failed to open the data base");
              }else{
        ui->label0->setText("Connected sucessfully"); }

              QString query = "CREATE TABLE memberss("
                              "Name VARCHAR(20),"
                              "username VARCHAR(20) ,"
                              "password VARCHAR(20));";
                          QSqlQuery qry;
              while (qry.next()) {
              QString assignment = ui->lineEdit->text();
              qry.prepare("INSERT INTO memberss("
                          "assignment)"
                          "VALUES(:assignment);");

              qry.bindValue(":assignment", assignment);
              if(qry.exec()){

                  while(qry.next()){
                  };

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
              };
        }


