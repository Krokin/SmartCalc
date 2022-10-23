#include "./Smart_Calc.h"

int Credit_Calc(credit_opt *calc) {
    int err = 0;
    if (calc->proc <= 0 || calc->time <= 0 || calc->sum_credit <= 0) {
        err = -1;
    } else {
        if (calc->type == 1) {
            double proc_mes = ((double)calc->proc/100)/12;
            double per = (1. + pow((1. + proc_mes), (double)calc->time)) - 1;
            calc->pay_month = round_rub(calc->sum_credit * ((proc_mes*per)/(per-1)));
            calc->over_sum = round_rub((calc->pay_month * calc->time) - calc->sum_credit);
            calc->sum = round_rub(calc->pay_month * calc->time);
        } else if (calc->type == 0) {
            double OD = calc->sum_credit/calc->time;
            for (int i = 0; i < calc->time; i++) {
                calc->sum += round_rub(OD + ((calc->sum_credit-OD*i)*(double)calc->proc/100)/12);
            }
            calc->pay_month = round_rub(calc->sum/calc->time);
            calc->over_sum = round_rub(calc->sum - calc->sum_credit);
        } else {
            err = -1;
        }
    }
    return err;
}
