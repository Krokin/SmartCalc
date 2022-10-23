#include "deposit.h"
#include "ui_deposit.h"

deposit::deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deposit)
{
    ui->setupUi(this);
    connect(ui->b_popol,SIGNAL(clicked()),this,SLOT(popol()));
    connect(ui->b_pay,SIGNAL(clicked()),this,SLOT(pay()));
     connect(ui->go,SIGNAL(clicked()),this,SLOT(depos_calc()));

}

deposit::~deposit()
{
    delete ui;
}

void deposit:: pay() {
    QString res = ui->list->toPlainText();
    ui->list->setPlainText(res+"Day pay: " + QString::number(ui->b_day_pay->value())+ " | sum " + QString::number(ui->b_sum_day_pay->value())+"\n");
}

void deposit:: popol() {
    QString res = ui->list->toPlainText();
    ui->list->setPlainText(res+"Day deposit: " + QString::number(ui->b_day_depos->value())+ " | sum " + QString::number(ui->b_sum_day_depos->value())+"\n");
}

void deposit:: depos_calc() {
    deposit_opt depo = {};
    char str[10000] = {};
    QByteArray barr1 = ui->list->toPlainText().toLatin1();
    strlcpy(str, barr1, ui->list->toPlainText().length() + 1);
    check_list(str, &depo);

    depo.sum_deposit = ui->b_sum_depos->value();
    depo.time = ui->b_time->value();
    depo.proc = ui->b_proc->value();
    depo.nalog = ui->b_nalog->value();
    if (ui->b_cap->isChecked()) {
        depo.cap_proc = 1;
    }
    if (ui->b_type_pay->currentText() == "Каждый день") {
        depo.type_pay = 1;
    } else if (ui->b_type_pay->currentText() == "Раз в месяц") {
        depo.type_pay = 2;
    } else if (ui->b_type_pay->currentText() == "Раз в квартал") {
        depo.type_pay = 3;
    } else if (ui->b_type_pay->currentText() == "Раз в полгода") {
        depo.type_pay = 4;
    } else if (ui->b_type_pay->currentText() == "Ежегодно") {
        depo.type_pay = 5;
    }
    int err = Deposit_Calc(&depo);
    if (err == -1) {
    } else {
        ui->b_pay_proc->setText(QString::number(depo.pay_proc, 'g', 15));
        ui->b_sum_nalog->setText(QString::number(depo.sum_nalog, 'g', 15));
        ui->sum_deposit_last->setText(QString::number(depo.deposit_last,'g', 15));
    }
}
