#include "credit.h"
#include "ui_credit.h"

credit::credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(credit_calc()));
}

credit::~credit()
{
    delete ui;
}


void credit:: credit_calc() {
    credit_opt credi = {0,0,0,0,0,0,0};
    credi.sum_credit = ui->b_sum_credit->value();
    credi.time = ui->b_time->value();
    credi.proc = ui->b_proc->value();
    if (ui->type_1->isChecked()) {
        credi.type = 1;
    } else if (ui->type_0->isChecked()) {
        credi.type = 0;
    }
    int err = Credit_Calc(&credi);
    if (err == -1) {
    } else {
        ui->b_pay_month->setText(QString::number(credi.pay_month, 'g', 15));
        ui->b_over_sum->setText(QString::number(credi.over_sum, 'g', 15));
        ui->b_sum->setText(QString::number(credi.sum, 'g', 15));
    }
}
