#ifndef AD_H
#define AD_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QDialog>
#include "ui_mainwindow.h"

namespace Ui {
class ad;
}

class ad : public QDialog
{
    Q_OBJECT

public:
//    Ui::MainWindow* mw;
   // void updateInternal(QString internals){
   //     while(internals.contains(',')){
   //         internals.replace(',', '\n');
   //     }
   // }

    Ui::MainWindow *ad_mw_ui;

    QString _username;
    explicit ad(QWidget *parent = nullptr, QString __username = "", Ui::MainWindow* _ui = nullptr);
    QString getAllInternals();
    QString getAllAssignments();
    QString getAllBooks();
    ~ad();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ad *ui;
    QSqlDatabase members;
};

#endif // AD_H
