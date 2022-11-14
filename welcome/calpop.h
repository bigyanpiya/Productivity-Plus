#ifndef CALPOP_H
#define CALPOP_H

#include <QDialog>

namespace Ui {
class calpop;
}

class calpop : public QDialog
{
    Q_OBJECT

public:
    explicit calpop(QWidget *parent = nullptr);
    ~calpop();

private:
    Ui::calpop *ui;
};

#endif // CALPOP_H
