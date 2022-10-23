#include "./Smart_Calc.h"

double round_rub(double x) {
    for (int i = 0; i < 3; i++) {
        x *= 10;
    }
    int count = 0;
    double rez_x = x;
    while (rez_x > 0) {
        rez_x/=10;
        count++;
    }
    x = (x / 10);
    x = round(x);
    for (int i = 0; i < 2; i++) {
        x /= 10;
    }
    return x;
}

void depos_nocap(deposit_opt *calc) {
    double bet = calc->proc/100;
    int count = 0;
    while (count != calc->time) {
        for (int j = 0; calc->day_depos[j][0] != 0; j++) {
            if ((calc->day_depos[j][0]) == count) {
                calc->sum_deposit += round_rub(calc->day_depos[j][1]);
            }
        }
        for (int j = 0; calc->day_pay[j][0] != 0; j++) {
            if ((calc->day_pay[j][0]) == count) {
                calc->sum_deposit -= round_rub(calc->day_pay[j][1]);
            }
        }
        calc->pay_proc += round_rub((((calc->sum_deposit * bet * calc->time)/365)/calc->time));
        count++;
    }
    calc->pay_proc = round_rub(calc->pay_proc);
    calc->sum_nalog = round_rub(calc->pay_proc * (calc->nalog/100));
    calc->deposit_last = round_rub(calc->sum_deposit + calc->pay_proc);
}

void depos_cap_day(deposit_opt *calc) {
    double bet = calc->proc/100;
    int count = 0;
    while (count != calc->time) {
        for (int j = 0; calc->day_depos[j][0] != 0; j++) {
            if ((calc->day_depos[j][0]) == count) {
                calc->sum_deposit += round_rub(calc->day_depos[j][1]);
            }
        }
        for (int j = 0; calc->day_pay[j][0] != 0; j++) {
            if ((calc->day_pay[j][0]) == count) {
                calc->sum_deposit -= round_rub(calc->day_pay[j][1]);
            }
        }
        calc->pay_proc += round_rub((((calc->sum_deposit * bet * calc->time)/365)/calc->time));
        calc->sum_deposit += round_rub((((calc->sum_deposit * bet * calc->time)/365)/calc->time));
        count++;
    }
    calc->pay_proc = round_rub(calc->pay_proc);
    calc->sum_nalog = round_rub(calc->pay_proc * (calc->nalog/100));
    calc->deposit_last = round_rub(calc->sum_deposit);
}


void depos_cap_another(deposit_opt *calc) {
    int days = 0;
    if (calc->type_pay == 2) { days = 31;
    } else if (calc->type_pay == 3) { days = 91;
    } else if (calc->type_pay == 4) { days = 183;
    } else if (calc->type_pay == 5) { days = 364;
    }
    double bet = calc->proc/100;
    int count = 0;
    double rez_proc = 0;
    while (count != calc->time) {
        if (count % days == 0 && count != 0) {
            calc->sum_deposit += round_rub(calc->pay_proc);
            rez_proc += round_rub(calc->pay_proc);
            calc->pay_proc = 0;
        }
        for (int j = 0; calc->day_depos[j][0] != 0; j++) {
            if ((calc->day_depos[j][0]) == count) {
                calc->sum_deposit += round_rub(calc->day_depos[j][1]);
            }
        }
        for (int j = 0; calc->day_pay[j][0] != 0; j++) {
            if ((calc->day_pay[j][0]) == count) {
                calc->sum_deposit -= round_rub(calc->day_pay[j][1]);
            }
        }
        calc->pay_proc += ((((calc->sum_deposit * bet * calc->time)/365)/calc->time));
        count++;
    }
    calc->deposit_last = round_rub(calc->sum_deposit + calc->pay_proc);
    calc->pay_proc = rez_proc + round_rub(calc->pay_proc);
    calc->sum_nalog = round_rub(calc->pay_proc * (calc->nalog/100));
}

int check_err(deposit_opt *calc) {
    int err = 0;
    if (calc->cap_proc < 0 || calc->cap_proc > 1) err = -1;
    if (calc->sum_deposit <= 0) err = -1;
    if (calc->time <= 0) err = -1;
    if (calc->nalog < 0) err = -1;
    if (calc->cap_proc == 1) {
        if (calc->type_pay <= 0 || calc->type_pay > 5) err = -1;
    }
    return err;
}

int Deposit_Calc(deposit_opt *calc) {
    int err = check_err(calc);
    if (err == 0) {
        if (calc->cap_proc == 0) {
            depos_nocap(calc);
        } else {
            if (calc->type_pay == 1) {
                depos_cap_day(calc);
            } else {
                depos_cap_another(calc);
            }
        }
    }
    return err == 0 ? err : -1;
}

int check_list(char *str, deposit_opt *dep) {
    int slip = 0;
    char num[100] = {0};
    int i = 0;
    int j = 0;
    int check = 0;
    int pay_dep = 0;
    while (*str) {
        if (*str == 'p' && *(str+1) == 'a') {
            pay_dep = 1;
        } else if (*str == 'd' && *(str+1) == 'e') {
            pay_dep = 2;
        }
        if (strrchr("0123456789", *str)) {
            char *stp = str;
            while (strrchr("0123456789", *str)) {
                str++;
                slip++;
            }
            strncpy(num, stp, slip);
            if (pay_dep == 1) {
                if (check == 0) {
                    check = 1;
                    sscanf(num, "%d", &dep->day_pay[i][0]);
                } else if (check == 1) {
                    check = 0;
                    sscanf(num, "%d", &dep->day_pay[i][1]);
                    i++;
                }
            } else {
                    if (check == 0) {
                    check = 1;
                    sscanf(num, "%d", &dep->day_depos[j][0]);
                } else if (check == 1) {
                    check = 0;
                    sscanf(num, "%d", &dep->day_depos[j][1]);
                    j++;
                }
            }
        }
        str++;
    }
    return 0;
}
