#include "gpa.h"
#include "ui_gpa.h"
#include<iostream>

gpa::gpa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpa)
{
    ui->setupUi(this);
}

gpa::~gpa()
{
    delete ui;
}


    int subject[9];
    int i;
    for(i=0;i<=8;i++)
    {
    if(subject[i]>80)
    return 'A'
    else if(subject[i]>=75&&subject[i]<80)
    return'B+'
    }


void gpa::on_pushButton_clicked()
{
    //int subject1,subject2,subject3,subject4,subject5,subject6,subject7,subject8;
       subject[0] = ui->lineEdit->text().toInt();
       subject[1] = ui->lineEdit->text().toInt();
       subject[2] = ui->lineEdit->text().toInt();
       subject[3] = ui->lineEdit->text().toInt();
       subject[4] = ui->lineEdit->text().toInt();
       subject[5]= ui->lineEdit->text().toInt();
       subject[6]= ui->lineEdit->text().toInt();
       subject[7]= ui->lineEdit->text().toInt();




}

