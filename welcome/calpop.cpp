#include "calpop.h"
#include "ui_calpop.h"


calpop::calpop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calpop)
{
    ui->setupUi(this);
}

calpop::~calpop()
{
    delete ui;
}
