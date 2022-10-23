#include <check.h>
#include "Smart_Calc.h"

START_TEST(calc_test_plus) {
    double result = 0.0;
    double answer = 1.25+3.45;
    char expr[100] = "1.25+3.45";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_minus) {
    double result = 0.0;
    double answer = 0.003-15.34;
    char expr[100] = "0.003-15.34";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_mult) {
    double result = 0.0;
    double answer = 0.25*5;
    char expr[100] = "0.25*5";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_div) {
    double result = 0.0;
    double answer = 0.2/5;
    char expr[100] = "0.2/5";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_mod) {
    double result = 0.0;
    double answer = fmod(60, 3.5);
    char expr[100] = "60mod3.5";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_pow) {
    double result = 0.0;
    double answer = pow(5, 3.45);
    char expr[100] = "5^3.45";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_brackets) {
    double result = 0.0;
    double answer = (5.23+1.25)*(0.25+0.001);
    char expr[100] = "(5.23+1.25)*(0.25+0.001)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_sin) {
    double result = 0.0;
    double answer = sin(0.3*0.6);
    char expr[100] = "sin(0.3*0.6)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_cos) {
    double result = 0.0;
    double answer = cos(0.6-0.1+0.2/0.5);
    char expr[100] = "cos(0.6-0.1+0.2/0.5)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_tan) {
    double result = 0.0;
    double answer = tan(0.8/2);
    char expr[100] = "tan(0.8/2)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_sqrt) {
    double result = 0.0;
    double answer = sqrt(97.3456);
    char expr[100] = "sqrt(97.3456)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_ln) {
    double result = 0.0;
    double answer = log(2.5+99);
    char expr[100] = "ln(2.5+99)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_log) {
    double result = 0.0;
    double answer = log10(1.8+256.34);
    char expr[100] = "log(1.8+256.34)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_asin) {
    double result = 0.0;
    double answer = asin(0.34);
    char expr[100] = "asin(0.34)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_acos) {
    double result = 0.0;
    double answer = acos(-0.83);
    char expr[100] = "acos(-0.83)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_atan) {
    double result = 0.0;
    double answer = atan(-0.669);
    char expr[100] = "atan(-0.669)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_1) {
    double result = 0.0;
    double answer = 0.0;
    char expr[100] = "1-1";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_2) {
    double result = 0.0;
    double answer = 1 - 2 - 3;
    char expr[100] = "1-2-3";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_3) {
    double result = 0.0;
    double answer = 4*(-5)+2.01/sin(0.01);
    char expr[100] = "4*(-5)+2.01/sin(0.01)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_4) {
    double result = 0.0;
    double answer = sin(0.1);
    char expr[100] = "sin(0.1)";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_5) {
    double result = 0.0;
    double answer = cos(sin(tan(-0.005)));
    char expr[100] = "cos(sin(tan(-0.005)))";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_inf) {
    double result = 0.0;
    double zero = 0.0;
    double answer = 125/zero;
    char expr[100] = "125/0";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_big) {
    double result = 0.0;
    double answer = log10(32+1)*7/11*432*(sin(2)*12-45+4)/2;
    char expr[100] = "log(32+1)*7/11*432*(sin(2)*12-45+4)/2";
    Smart_Calc(expr, NULL, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_ezx) {
    double result = 0.0;
    double answer = 2+1;
    char expr[100] = "2+x";
    char expr1[100] = "1";
    Smart_Calc(expr, expr1, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_hardx) {
    double result = 0.0;
    double answer = log10(32+1)*7/11*432*(sin(2)*12-45+4)/2;
    char expr[100] = "log(32+1)*7/x*432*(sin(2)*12-45+4)/2";
    char expr1[100] = "11";
    Smart_Calc(expr, expr1, &result);
    ck_assert_float_eq(answer, result);
}
END_TEST

START_TEST(calc_test_invalid_expr) {
    int ret = 0;
    double result = 0.0;
    char expr[100] = "log(32+1)*7/11*432*(sin(2)*12-45+4/2";
    ret = Smart_Calc(expr, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str0[10] = {0};
    ret = Smart_Calc(str0, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str1[10] = "+";
    ret = Smart_Calc(str1, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str2[10] = "++";
    ret = Smart_Calc(str2, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str3[10] = ".";
    ret = Smart_Calc(str3, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str4[10] = "2q";
    ret = Smart_Calc(str4, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str5[10] = "1..";
    ret = Smart_Calc(str5, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str6[10] = "()";
    ret = Smart_Calc(str6, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str7[10] = "m.^";
    ret = Smart_Calc(str7, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str8[10] = "$m";
    ret = Smart_Calc(str8, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str9[10] = "5mp";
    ret = Smart_Calc(str9, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str10[10] = ")Q";
    ret = Smart_Calc(str10, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str11[10] = "+-";
    ret = Smart_Calc(str11, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str12[10] = "cos)";
    ret = Smart_Calc(str12, NULL, &result);
    ck_assert_int_eq(ret, -1);

    char str13[10] = "mod+";
    ret = Smart_Calc(str13, NULL, &result);
    ck_assert_int_eq(ret, -1);
}
END_TEST

START_TEST(calc_credit) {
    credit_opt result = {50000, 12, 6, 1, 0, 0, 0};
    Credit_Calc(&result);
    ck_assert_int_eq(51639, (int)result.sum);
    ck_assert_int_eq(1639, (int)result.over_sum);
    ck_assert_int_eq(4303, (int)result.pay_month);

    credit_opt result1 = {168500, 8, 11, 0, 0, 0, 0};
    Credit_Calc(&result1);
    ck_assert_int_eq(175450, (int)result1.sum);
    ck_assert_int_eq(6950, (int)result1.over_sum);
    ck_assert_int_eq(21931, (int)result1.pay_month);
}
END_TEST

START_TEST(calc_deposit) {
    deposit_opt result = {0};
    result.sum_deposit = 600000;
    result.time = 60;
    result.proc = 5;
    result.nalog = 0;
    result.cap_proc = 0;
    result.type_pay = 2;
    Deposit_Calc(&result);
    ck_assert_int_eq(0, (int)result.sum_nalog);
    ck_assert_int_eq(4931, (int)result.pay_proc);
    ck_assert_int_eq(604931, (int)result.deposit_last);

    deposit_opt result1 = {0};
    result1.sum_deposit = 350000;
    result1.time = 320;
    result1.proc = 15;
    result1.nalog = 5;
    result1.cap_proc = 1;
    result1.type_pay = 4;
    Deposit_Calc(&result1);
    ck_assert_int_eq(2375, (int)result1.sum_nalog);
    ck_assert_int_eq(47509, (int)result1.pay_proc);
    ck_assert_int_eq(397509, (int)result1.deposit_last);

    deposit_opt result2 = {0};
    result2.sum_deposit = 1000000;
    result2.time = 500;
    result2.proc = 2.2;
    result2.nalog = 5;
    result2.cap_proc = 1;
    result2.type_pay = 2;
    Deposit_Calc(&result2);
    ck_assert_int_eq(1528, (int)result2.sum_nalog);
    ck_assert_int_eq(30566, (int)result2.pay_proc);
    ck_assert_int_eq(1030566, (int)result2.deposit_last);

    deposit_opt result3 = {0};
    result3.sum_deposit = 1000000;
    result3.time = 500;
    result3.proc = 2.2;
    result3.nalog = 5;
    result3.cap_proc = 1;
    result3.type_pay = 1;
    Deposit_Calc(&result3);
    ck_assert_int_eq(1529, (int)result3.sum_nalog);
    ck_assert_int_eq(30594, (int)result3.pay_proc);
    ck_assert_int_eq(1030594, (int)result3.deposit_last);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, calc_test_plus);
    tcase_add_test(tc1_1, calc_test_minus);
    tcase_add_test(tc1_1, calc_test_mult);
    tcase_add_test(tc1_1, calc_test_div);
    tcase_add_test(tc1_1, calc_test_mod);
    tcase_add_test(tc1_1, calc_test_pow);
    tcase_add_test(tc1_1, calc_test_brackets);
    tcase_add_test(tc1_1, calc_test_sin);
    tcase_add_test(tc1_1, calc_test_cos);
    tcase_add_test(tc1_1, calc_test_tan);
    tcase_add_test(tc1_1, calc_test_sqrt);
    tcase_add_test(tc1_1, calc_test_ln);
    tcase_add_test(tc1_1, calc_test_log);
    tcase_add_test(tc1_1, calc_test_asin);
    tcase_add_test(tc1_1, calc_test_acos);
    tcase_add_test(tc1_1, calc_test_atan);
    tcase_add_test(tc1_1, calc_test_1);
    tcase_add_test(tc1_1, calc_test_2);
    tcase_add_test(tc1_1, calc_test_3);
    tcase_add_test(tc1_1, calc_test_4);
    tcase_add_test(tc1_1, calc_test_5);
    tcase_add_test(tc1_1, calc_test_inf);
    tcase_add_test(tc1_1, calc_test_big);
    tcase_add_test(tc1_1, calc_test_ezx);
    tcase_add_test(tc1_1, calc_test_hardx);
    tcase_add_test(tc1_1, calc_test_invalid_expr);
    tcase_add_test(tc1_1, calc_credit);
    tcase_add_test(tc1_1, calc_deposit);

    srunner_run_all(sr, CK_ENV);
    srunner_ntests_failed(sr);
    srunner_free(sr);

    return (0);
}
