#ifndef AD_H
#define AD_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>

#include <QDialog>

namespace Ui {
class ad;
}

class ad : public QDialog
{
    Q_OBJECT

public:
    QString _username;
    explicit ad(QWidget *parent = nullptr, QString __username = "");
    ~ad();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ad *ui;
    QSqlDatabase members;
};

#endif // AD_H
