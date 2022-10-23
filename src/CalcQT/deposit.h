#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../Smart_Calc.h"
#ifdef __cpluplus
}
#endif

namespace Ui {
class deposit;
}

class deposit : public QDialog
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

private:
    Ui::deposit *ui;

private slots:
    void popol();
    void pay();
    void depos_calc();
};

#endif // DEPOSIT_H
