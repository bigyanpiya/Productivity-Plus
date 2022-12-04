#include "ad.h"
#include "ui_ad.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

using namespace std;

void __updateAssignment(QString assignments, Ui::MainWindow* __ui);
void __updateInternal(QString internals, Ui::MainWindow* __ui);
void __updateBook(QString books, Ui::MainWindow* __ui);
QString get(QSqlQuery* qry, QString username);

ad::ad(QWidget *parent, QString __username, Ui::MainWindow* _ui) :
    QDialog(parent),
    ui(new Ui::ad)
{
    this->_username = __username;
    ui->setupUi(this);
    ad_mw_ui = _ui;
}

ad::~ad()
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

void ad::on_pushButton_clicked()
{    members= QSqlDatabase::addDatabase("QSQLITE", "BIGYAN");
     members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
     members.exec("PRAGMA locking_mode = EXCLUSIVE");

  ////ui->label->setText("Connected sucessfully"); }
  //
  //      QString query = "CREATE TABLE memberss("
  //                      "Name VARCHAR(20),"
  //                      "username VARCHAR(20) ,"
  //                      "password VARCHAR(20));";
  //
     QString getInternal= ui->lineEdit->text();
           QString currentInternals = getAllInternals();
           qDebug() << currentInternals;
             if(currentInternals != "_ERR_"){
              QString updateInternals = currentInternals;
              QDateEdit* qd = ui->internal_date_edit;
              QString date = qd->date().toString();
              getInternal= getInternal+ "  (" + date + ")";

              if(updateInternals.length() < 5 && !updateInternals.contains(',')){
                  qDebug() << "CAME WITHOUT COMMA";
                 updateInternals.append(getInternal);
              }else{
                  qDebug() << "CAME WITH COMMA";
                  updateInternals.append(",");
                  updateInternals.append(getInternal);

                  qDebug() << updateInternals;
              }

               qDebug() << members.isValid();


              QSqlQuery query(members);
              query.prepare("UPDATE memberss SET internal = :internal WHERE username = :username");

              query.bindValue(":internal", updateInternals);
              query.bindValue(":username", this->_username);

              if(query.exec()){
                    __updateInternal(updateInternals, ad_mw_ui);
                    qDebug("sucess updating data ");
                    QMessageBox::information(this, "Saved","<FONT COLOR='green'>Sucess updating data</FONT>");

                 }else{
                    QMessageBox::critical(this, " not Saved","<FONT COLOR='red'>Error updating data</FONT>");
                 }
              qDebug() << query.lastError();
           }


           //if(!qry.exec(query)){
           //    qDebug("error creating table // it may already exxist");
           //}
           //members.close();

           qDebug("Db.closed");

           members.close();
           QSqlDatabase::removeDatabase("BIGYAN");

}

QString ad::getAllInternals(){
   if (!members.open()){
      return "_ERR_";
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT internal FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        return query.value(0).toString();
      }else{
        return "_ERR_";
      }
   }
}




void ad::on_pushButton_2_clicked()
{

    members= QSqlDatabase::addDatabase("QSQLITE", "BIGYAN");
    members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
    members.exec("PRAGMA locking_mode = EXCLUSIVE");

 ////ui->label->setText("Connected sucessfully"); }
 //
 //      QString query = "CREATE TABLE memberss("
 //                      "Name VARCHAR(20),"
 //                      "username VARCHAR(20) ,"
 //                      "password VARCHAR(20));";
 //
    QString getAssignment = ui->lineEdit_3->text();
          QString currentAssignments = getAllAssignments();
          qDebug() << currentAssignments;
            if(currentAssignments != "_ERR_"){
             QString updateAssignments = currentAssignments;
             QDateEdit* qd = ui->dateEdit_3;
             QString date = qd->date().toString();
             getAssignment = getAssignment+ "  (" + date + ")";

             if(updateAssignments.length() < 5 && !updateAssignments.contains(',')){
                 qDebug() << "CAME WITHOUT COMMA";
                updateAssignments.append(getAssignment);
             }else{
                 qDebug() << "CAME WITH COMMA";
                 updateAssignments.append(",");
                 updateAssignments.append(getAssignment);

                 qDebug() << updateAssignments;
             }

              qDebug() << members.isValid();


             QSqlQuery query(members);
             query.prepare("UPDATE memberss SET assignment = :assignment WHERE username = :username");

             query.bindValue(":assignment", updateAssignments);
             query.bindValue(":username", this->_username);

             if(query.exec()){
                   __updateAssignment(updateAssignments, ad_mw_ui);
                   qDebug("sucess updating data ");
                   QMessageBox::information(this, "Saved","<FONT COLOR='green'>Sucess updating data</FONT>");

                }else{
                   QMessageBox::critical(this, " not Saved","<FONT COLOR='red'>Error updating data</FONT>");
                }
             qDebug() << query.lastError();
          }


          //if(!qry.exec(query)){
          //    qDebug("error creating table // it may already exxist");
          //}
          //members.close();

          qDebug("Db.closed");

          members.close();
          QSqlDatabase::removeDatabase("BIGYAN");
}
QString ad::getAllAssignments(){
   if (!members.open()){
      return "_ERR_";
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT assignment FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        return query.value(0).toString();
      }else{
        return "_ERR_";
      }
   }
}


void ad::on_pushButton_3_clicked(){
    members= QSqlDatabase::addDatabase("QSQLITE", "BIGYAN");
    members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
    members.exec("PRAGMA locking_mode = EXCLUSIVE");

 ////ui->label->setText("Connected sucessfully"); }
 //
 //      QString query = "CREATE TABLE memberss("
 //                      "Name VARCHAR(20),"
 //                      "username VARCHAR(20) ,"
 //                      "password VARCHAR(20));";
 //
    QString getBook = ui->lineEdit_2->text();
          QString currentBooks = getAllBooks();
          qDebug() << currentBooks;
            if(currentBooks != "_ERR_"){
             QString updateBooks = currentBooks;
             QDateEdit* qd = ui->dateEdit;
             QString date = qd->date().toString();
             getBook = getBook+ "  (" + date + ")";

             if(updateBooks.length() < 5 && !updateBooks.contains(',')){
                 qDebug() << "CAME WITHOUT COMMA";
                updateBooks.append(getBook);
             }else{
                 qDebug() << "CAME WITH COMMA";
                 updateBooks.append(",");
                 updateBooks.append(getBook);

                 qDebug() << updateBooks;
             }

              qDebug() << members.isValid();


             QSqlQuery query(members);
             query.prepare("UPDATE memberss SET books = :books WHERE username = :username");

             query.bindValue(":books", updateBooks);
             query.bindValue(":username", this->_username);

             if(query.exec()){
                   __updateBook(updateBooks, ad_mw_ui);
                   qDebug("sucess updating data ");
                   QMessageBox::information(this, "Saved","<FONT COLOR='green'>Sucess updating data</FONT>");

                }else{
                   QMessageBox::critical(this, " not Saved","<FONT COLOR='red'>Error updating data</FONT>");
                }
             qDebug() << query.lastError();
          }


          //if(!qry.exec(query)){
          //    qDebug("error creating table // it may already exxist");
          //}
          //members.close();

          qDebug("Db.closed");

          members.close();
          QSqlDatabase::removeDatabase("BIGYAN");



}

QString ad::getAllBooks(){
   if (!members.open()){
      return "_ERR_";
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT books FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        return query.value(0).toString();
      }else{
        return "_ERR_";
      }
   }
}

void __updateAssignment(QString assignments, Ui::MainWindow* __ui){
    string __assignments  = "1. " + assignments.toStdString();
    int i = 2;
    while(__assignments.find(",") != string::npos){
        __assignments.replace(__assignments.find(","), strlen(","), "\n" +to_string(i) + ". ");
        i++;
    }
    __ui->nameLabel_2->setText(QString::fromStdString(__assignments));
}

void __updateInternal(QString internals, Ui::MainWindow* __ui){
    string __internals  = "1. " + internals.toStdString();
    int i = 2;
    while(__internals.find(",") != string::npos){
        __internals.replace(__internals.find(","), strlen(","), "\n" +to_string(i) + ". ");
        i++;
    }
    __ui->nameLabel_1->setText(QString::fromStdString(__internals));
}

void __updateBook(QString books, Ui::MainWindow* __ui){
    string __books  = "1. " + books.toStdString();
    int i = 2;
    while(__books.find(",") != string::npos){
        __books.replace(__books.find(","), strlen(","), "\n" +to_string(i) + ". ");
        i++;
    }
    __ui->nameLabel_4->setText(QString::fromStdString(__books));
}















