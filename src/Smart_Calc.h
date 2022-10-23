#ifndef SRC_SMART_CALC_H_
#define SRC_SMART_CALC_H_

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


typedef int typel;

typedef struct stack {
    double value;
    // X и Число = 0, +- = 1, */mod = 2, ^ = 3, scatl = 4, () = -1;
    int priority;
    // number - 1;
    // x - 2;
    // plus - 3;
    // minus - 4;
    // * - 5;
    // / - 6;
    // mod - 7;
    // ^ - 8;
    // ( - 9;
    // ) - 10;
    // sin - 11;
    // cos - 12;
    // tan - 13;
    // acos - 14;
    // asin - 15;
    // atan - 16;
    // sqrt - 17;
    // ln - 18
    // log - 19;
    typel type;
    struct stack *next;
} stack;

typedef struct credit_opt {
    double sum_credit;
    int time;
    double proc;
    int type;
    double over_sum;
    double sum;
    double pay_month;
} credit_opt;

typedef struct deposit_opt {
    double sum_deposit;
    int time;
    double proc;
    double nalog;
    int type_pay;  // !1 дневная/ 2 месячная/ 3квартальная / 4полугод/ 5год
    int cap_proc;
    int day_depos[100][2];
    int day_pay[100][2];
    double pay_proc;
    double sum_nalog;
    double deposit_last;
} deposit_opt;


int num_check(char *str);
int bracket_check(char *str);
void delete_space(char *str);
int mod_check(char *str);
int sign_check(char *str, int prev_char);
int option_help(char *str);
int option_check(char *str);
int err_station(char *str, int error);
void delim_str(char *str);
void push(stack **head, double value, int priority, typel type);
int insert(stack *head, int count, double value, int priority, typel type);
int pop(stack **head, double *value, int *priority, typel *type);
int peek(stack *head, int count, double *value, int *priority, typel *type);
void peek_last(stack *head, double *value, int *priority, typel *type);
void insert_del(stack **head, int count, double *value, int *priority, typel *type);
void parse_leksOPT(char *str, stack **head, double x, int error);
int parse_leks(char *str, stack **head, double x, int error);
void reverse_stack(stack **head, stack **reverse_s);
stack* RPN(stack **head);
void func_calculate(stack **head, int count, typel type);
double calculate(stack **head);
double base(char *str, double x, int error);
int Smart_Calc(char *str, char *strx, double *res);

int Credit_Calc(credit_opt *calc);

int Deposit_Calc(deposit_opt *calc);

double round_rub(double x);
int check_list(char *str, deposit_opt *dep);
#endif  // SRC_SMART_CALC_H_
