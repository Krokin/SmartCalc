#ifndef CREDIT_H
#define CREDIT_H

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
class credit;
}

class credit : public QDialog
{
    Q_OBJECT

public:
    explicit credit(QWidget *parent = nullptr);
    ~credit();

private:
    Ui::credit *ui;

private slots:
    void credit_calc();
};

#endif // CREDIT_H
