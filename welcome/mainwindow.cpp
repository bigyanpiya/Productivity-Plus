#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ad.h"
#include<QMessageBox>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
     members=QSqlDatabase::addDatabase("QSQLITE");
          members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
           if( members.open())
                   ui->label_4->setText("Database Connected!");
           else
               ui->label->setText("Not");

    members.exec("PRAGMA locking_mode = EXCLUSIVE");
    QPixmap pix(":/img/photos/logo.png");
    ui->image->setPixmap(pix);
//    members.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enter_clicked() {
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
             updateBook(books);
             QString internal = qry.value(4).toString();
             updateInternal(internal);
             QString assignment = qry.value(5).toString();
               updateAssignment(assignment);
             QString project = qry.value(6).toString();
             updateproject(project);

          };

      }else{
          QMessageBox::critical(this,"ERROR", "<FONT COLOR='red'>Enter Correct username or password</FONT>");
      }
      members.close();
}






void MainWindow::on_pushButton_clicked()
{
              //ui->stackedWidget->setCurrentIndex(2);
    dial1=new Dialog;
    dial1->show();
}




void MainWindow::on_calendar_clicked(const QDate &qd) {
    dial=new calpop(this, qd, ui, ui->tabWidget->currentIndex());
    dial->show();
}



void MainWindow::on_pushButton_2_clicked()
{
                  ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked() {
    dial3 = new ad(nullptr, this->_username, ui);
    dial3->show();
}

// Push button 8 is for Assignments
void MainWindow::on_pushButton_8_clicked(){
    members= QSqlDatabase::addDatabase("QSQLITE", "ASSIGNMENTS");
    members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
    members.exec("PRAGMA locking_mode = EXCLUSIVE");

   try{
    string asgNotoDelete = ui->assignment_no_to_delete->text().toStdString();
    int assgnNo  = stoi(asgNotoDelete);
    vector<QString> allAssignments = getAllAssignments();
    int noOfAsgn = allAssignments.size();

    if(assgnNo < 1 || assgnNo > noOfAsgn){
    qDebug() << allAssignments ;
           QMessageBox::critical(this, "Err","<FONT COLOR='red'>Enter a valid number</FONT>");
    }else{
        allAssignments.erase(allAssignments.begin() + assgnNo - 1);
        putAssignmentsIntoDb(allAssignments);
    }
   }catch(exception& e){
           QMessageBox::critical(this, "Err","<FONT COLOR='red'>Please enter a number</FONT>");
    qDebug() << "The input data was not a number";
   }

   members.close();
   QSqlDatabase::removeDatabase("ASSIGNMENTS");

}

void MainWindow::putAssignmentsIntoDb(vector<QString>& assgs){
   QString assngs = "";
   for(QString i: assgs){
       assngs.append(i);
       assngs.append(",");
   }

   if(assgs.size() > 0){
       assngs.truncate(assngs.lastIndexOf(QChar(',')));
   }


   QSqlQuery query(members);
   query.prepare("UPDATE memberss SET assignment = :assignment WHERE username = :username");

   query.bindValue(":assignment", assngs);
   query.bindValue(":username", this->_username);

   qDebug() << assngs;
   if(query.exec()){
    updateAssignment(assngs);
   }
}
vector<QString> MainWindow::getAllAssignments(){
    vector<QString> allAss = vector<QString>();
   if (!members.open()){
       qDebug() << "CANT OPEN";
      return allAss;
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT assignment FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        // All cases for the CSV data that comes fromt the database
        // X,Y ✅
        // X ✅
        // Empty ✅
        string allAssg = query.value(0).toString().toStdString();
        if(allAssg.length() > 5){
            while(allAssg.find(',') != string::npos){
                QString assignment = QString::fromStdString(allAssg.substr(0, allAssg.find(',')));
                allAssg = allAssg.substr(allAssg.find(',') + 1);
                allAss.push_back(assignment);
            }
            allAss.push_back(QString::fromStdString(allAssg));
            qDebug() << QString::fromStdString(allAssg);
        }
        return allAss;

      }else{
        return allAss;
      }
   }
}

void MainWindow::on_pushButton_9_clicked()
{
    members= QSqlDatabase::addDatabase("QSQLITE", "INTERNALS");
    members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
    members.exec("PRAGMA locking_mode = EXCLUSIVE");

    try{
     string intrNotoDelete = ui->internal_no_to_delete->text().toStdString();
     int intrNo  = stoi(intrNotoDelete);
     vector<QString> allInternals = getAllInternals();
     int noOfIntr = allInternals.size();

     if(intrNo < 1 || intrNo > noOfIntr){
     qDebug() << allInternals ;
            QMessageBox::critical(this, "Err","<FONT COLOR='red'>Enter a valid number</FONT>");
     }else{
         allInternals.erase(allInternals.begin() + intrNo - 1);
         putInternalsIntoDb(allInternals);
     }
    }catch(exception& e){
            QMessageBox::critical(this, "Err","<FONT COLOR='red'>Please enter a number</FONT>");
     qDebug() << "The input data was not a number";
    }

    members.close();
    QSqlDatabase::removeDatabase("INTERNALS");

}
void MainWindow::putInternalsIntoDb(vector<QString>& inter){
    QString interr = "";
    for(QString i: inter){
        interr.append(i);
        interr.append(",");
    }

    if(inter.size() > 0){
        interr.truncate(interr.lastIndexOf(QChar(',')));
    }


    QSqlQuery query(members);
    query.prepare("UPDATE memberss SET internal = :internal WHERE username = :username");

    query.bindValue(":internal", interr);
    query.bindValue(":username", this->_username);

    qDebug() << interr;
    if(query.exec()){
     updateInternal(interr);
    }
}
vector<QString> MainWindow::getAllInternals(){
    vector<QString> allInter = vector<QString>();
   if (!members.open()){
       qDebug() << "CANT OPEN";
      return allInter;
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT internal FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        // All cases for the CSV data that comes fromt the database
        // X,Y ✅
        // X ✅
        // Empty ✅
        string allInterr = query.value(0).toString().toStdString();
        if(allInterr.length() > 5){
            while(allInterr.find(',') != string::npos){
                QString internal = QString::fromStdString(allInterr.substr(0, allInterr.find(',')));
                allInterr = allInterr.substr(allInterr.find(',') + 1);
                allInter.push_back(internal);
            }
            allInter.push_back(QString::fromStdString(allInterr));
            qDebug() << QString::fromStdString(allInterr);
        }
        return allInter;

      }else{
        return allInter;
      }
   }
}



void MainWindow::on_calendar_activated(const QDate &qd){
    //QString date = qd->date().toString();
}




void MainWindow::putBooksIntoDb(vector<QString>& bok){
   QString boks = "";
   for(QString i: bok){
       boks.append(i);
       boks.append(",");
   }

   if(bok.size() > 0){
       boks.truncate(boks.lastIndexOf(QChar(',')));
   }


   QSqlQuery query(members);
   query.prepare("UPDATE memberss SET books = :books WHERE username = :username");

   query.bindValue(":books", boks);
   query.bindValue(":username", this->_username);

   qDebug() << boks;
   if(query.exec()){
    updateBook(boks);
   }
}
vector<QString> MainWindow::getAllBooks(){
    vector<QString> allBok = vector<QString>();
   if (!members.open()){
       qDebug() << "CANT OPEN";
      return allBok;
   }else{
      QSqlQuery query = QSqlQuery(members);
      query.prepare("SELECT books FROM memberss where username = :username;");
      query.bindValue(":username", _username);
      if(query.exec()){
        qDebug() << "SEEMS TO WORK HERE";
        qDebug() << query.first();
        // All cases for the CSV data that comes fromt the database
        // X,Y ✅
        // X ✅
        // Empty ✅
        string allBoks = query.value(0).toString().toStdString();
        if(allBoks.length() > 5){
            while(allBoks.find(',') != string::npos){
                QString book = QString::fromStdString(allBoks.substr(0, allBoks.find(',')));
                allBoks = allBoks.substr(allBoks.find(',') + 1);
                allBok.push_back(book);
            }
            allBok.push_back(QString::fromStdString(allBoks));
            qDebug() << QString::fromStdString(allBoks);
        }
        return allBok;

      }else{
        return allBok;
      }
   }
}


void MainWindow::on_pushButton_10_clicked()
{

members= QSqlDatabase::addDatabase("QSQLITE", "BOOKS");
members.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/Project/Productivity-Plus/welcome/time.db");
members.exec("PRAGMA locking_mode = EXCLUSIVE");

try{
 string bokNotoDelete = ui->lineEdit_9->text().toStdString();
 int bokNo  = stoi(bokNotoDelete);
 vector<QString> allBooks = getAllBooks();
 int noOfBok = allBooks.size();

 if(bokNo < 1 || bokNo > noOfBok){
 qDebug() << allBooks ;
        QMessageBox::critical(this, "Err","<FONT COLOR='red'>Enter a valid number</FONT>");
 }else{
     allBooks.erase(allBooks.begin() + bokNo - 1);
     putBooksIntoDb(allBooks);
 }
}catch(exception& e){
        QMessageBox::critical(this, "Err","<FONT COLOR='red'>Please enter a number</FONT>");
 qDebug() << "The input data was not a number";
}

members.close();
QSqlDatabase::removeDatabase("BOOKS");
}
