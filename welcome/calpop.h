#ifndef CALPOP_H
#define CALPOP_H

#include <QDialog>
#include <QDate>
#include <QSqlDatabase>
#include "ui_mainwindow.h"

namespace Ui {
class calpop;
}

class calpop : public QDialog {
    Q_OBJECT

public:
    QSqlDatabase db;
    std::vector<QString> getAssignments();


    explicit calpop(QWidget *parent = nullptr, const QDate &qd = QDate::currentDate(), Ui::MainWindow* mw_ui = nullptr, int index = 0);
    ~calpop();

private:
    Ui::calpop *ui;
};

#endif // CALPOP_H
