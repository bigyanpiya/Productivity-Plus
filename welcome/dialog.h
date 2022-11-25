#ifndef DIALOG_H
#define DIALOG_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_signup_2_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase members;
};

#endif // DIALOG_H
