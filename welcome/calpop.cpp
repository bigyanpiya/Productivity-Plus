#include "calpop.h"
#include "ui_calpop.h"

const QString ASSIGNMENT = "Assignment";
const QString INTERNAL = "Internal";
const QString LIBRARY = "Library";

using namespace std;

calpop::calpop(QWidget *parent, const QDate &qd, Ui::MainWindow* mw_ui, int index) :  QDialog(parent), ui(new Ui::calpop) {
    ui->setupUi(this);
    if(index >= 0 && index <= 2){
        ui->comboBox->setCurrentIndex(index);
    }

    QString currentSelection = ui->comboBox->currentText();
    qDebug() << currentSelection;
    if(index == 0){
        string assignments = mw_ui->nameLabel_2->text().toStdString();
        vector<QString> allAssignments = vector<QString>();

        if(assignments.length() > 5){
            while(assignments.find("\n") != string::npos){
                QString assignment = QString::fromStdString(assignments.substr(0, assignments.find("\n")));
                assignments = assignments.substr(assignments.find("\n") + 1);
                allAssignments.push_back(assignment);
            }
            allAssignments.push_back(QString::fromStdString(assignments));
            qDebug()<< allAssignments;

        string output("");
        bool contains = false;
        QString currentDate = qd.toString();
        int i = 0;
        for(i = 0; i < (int)allAssignments.size(); i++){
           if(allAssignments[i].contains(currentDate)){
            bool contains = true;
               output.append(allAssignments[i].toStdString());
               output.append("\n");
           }
        }

        if(contains){
            output.pop_back();
        }

        ui->label->setText(QString::fromStdString(output));

    }
    }else if(index == 1){
                string assignments = mw_ui->nameLabel_1->text().toStdString();
        vector<QString> allAssignments = vector<QString>();

        if(assignments.length() > 5){
            while(assignments.find("\n") != string::npos){
                QString assignment = QString::fromStdString(assignments.substr(0, assignments.find("\n")));
                assignments = assignments.substr(assignments.find("\n") + 1);
                allAssignments.push_back(assignment);
            }
            allAssignments.push_back(QString::fromStdString(assignments));
            qDebug()<< allAssignments;

        string output("");
        bool contains = false;
        QString currentDate = qd.toString();
        int i = 0;
        for(i = 0; i < (int)allAssignments.size(); i++){
           if(allAssignments[i].contains(currentDate)){
            bool contains = true;
               output.append(allAssignments[i].toStdString());
               output.append("\n");
           }
        }

        if(contains){
            output.pop_back();
        }

        ui->label->setText(QString::fromStdString(output));

    }

    }else if(index == 2){
        string assignments = mw_ui->nameLabel->text().toStdString();
        vector<QString> allAssignments = vector<QString>();

        if(assignments.length() > 5){
            while(assignments.find("\n") != string::npos){
                QString assignment = QString::fromStdString(assignments.substr(0, assignments.find("\n")));
                assignments = assignments.substr(assignments.find("\n") + 1);
                allAssignments.push_back(assignment);
            }
            allAssignments.push_back(QString::fromStdString(assignments));
            qDebug()<< allAssignments;

        string output("");
        bool contains = false;
        QString currentDate = qd.toString();
        int i = 0;
        for(i = 0; i < (int)allAssignments.size(); i++){
           if(allAssignments[i].contains(currentDate)){
            bool contains = true;
               output.append(allAssignments[i].toStdString());
               output.append("\n");
           }
        }

        if(contains){
            output.pop_back();
        }

        ui->label->setText(QString::fromStdString(output));

    }
    }

    }

calpop::~calpop(){
    delete ui;
}

