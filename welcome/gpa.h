#ifndef GPA_H
#define GPA_H

#include <QDialog>

namespace Ui {
class gpa;
}

class gpa : public QDialog
{
    Q_OBJECT

public:
    explicit gpa(QWidget *parent = nullptr);
    ~gpa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gpa *ui;
};

#endif // GPA_H
