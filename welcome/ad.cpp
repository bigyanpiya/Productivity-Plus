#include "ad.h"
#include "ui_ad.h"
#include<QMessageBox>

QString getAllInternals(QSqlQuery* qry, QString username);

ad::ad(QWidget *parent, QString __username) :
    QDialog(parent),
    ui(new Ui::ad)
{
    this->_username = __username;
    ui->setupUi(this);
}

ad::~ad()
{
    delete ui;
}
QString putInternal(QString q_query){
        std::string query = q_query.toLocal8Bit().constData();
        std::string local,global;
        for(auto e:query){
            if(e==','){
                global+=local;
                global+='\n';
                local="";
            }else local+=e;
        }
        global+=local;

        return QString::fromLocal8Bit(global);

}
void ad::on_pushButton_clicked()
{


    members= QSqlDatabase::addDatabase("QSQLITE");
   members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
   if (!members.open()){
      qDebug("failed");
   }else{
      qDebug("sucessfool"); }
      if (!members.open()){
//ui->label->setText("Failed to open the data base");
      }else{
//ui->label->setText("Connected sucessfully"); }

      QString query = "CREATE TABLE memberss("
                      "Name VARCHAR(20),"
                      "username VARCHAR(20) ,"
                      "password VARCHAR(20));";
      QString hardCode = ui->lineEdit->text();
      qInfo()<<putInternal(hardCode);
      QSqlQuery qry;
      //qry.prepare("INSERT INTO memberss(internal)"
      //            "VALUES(':internal') WHERE username = ':username' ;");
      qDebug() << "The data i got here is " <<  getAllInternals(&qry, _username);
      qry.prepare("UPDATE memberss SET internal = :internal WHERE username = :username ;");
      qry.bindValue(":internal", hardCode);
      qry.bindValue(":username", this->_username);

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


QString getAllInternals(QSqlQuery* qry, QString username){
    std::string query = "SELECT internal FROM memberss WHERE username = '" + username.toStdString() + "'";
      qDebug() << QString::fromStdString(query);

     if (qry->exec("SELECT internal FROM memberss WHERE username = '"+username+"'")){
         return qry->value(0).toString();
      }
}
