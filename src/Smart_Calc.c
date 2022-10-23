#include "./Smart_Calc.h"

int check_x(char*str) {
    int error = 0;
    int slip = 1;
    str++;
    if (*str != '\0') {
        if (!strrchr("+-*/^m)", *str)) error = -1;
    }
    return error == 0 ? slip : error;
}

int num_check(char *str) {
    int error = 0;
    int slip = 0;
    int check = 0;
    while ((*str >= '0' && *str <= '9') || *str == '.') {
        if (*str == '.') {
            if (check == 1) error = -1;
            check = 1;
            str++;
            if (*str >= '0' && *str <= '9') {
            } else {
                error = -1;
            }
            str--;
        }
        slip++;
        str++;
    }
    if (*str != '\0') {
        if (!strrchr("+-*/^m)", *str)) error = -1;
    }
    return error == 0 ? slip : error;
}

int bracket_check(char *str) {
    int error = 0;
    int bracket = 0;
    while (*str && error != -1) {
        if (*str == '(') {
            str++;
            if (!strrchr("+-0123456789cstal(x", *str)) error = -1;
            str--;
            bracket += 1;
        } else if (*str == ')') {
            str++;
            if (*str != '\0') {
                if (!strrchr("+-*/^m)", *str)) error = -1;
            }
            str--;
            bracket -= 1;
            if (bracket < 0) error = -1;
        }
        str++;
    }
    if (bracket != 0) error = -1;
    return error;
}

void delete_space(char *str) {
    char buf[300] = {0};
    char *s = str;
    int i = 0;
    while (*str) {
        if (*str == ' ') {
        } else {
            buf[i] = *str;
            i++;
        }
        str++;
    }
    int j = 0;
    while (j < i) {
        *s = buf[j];
        j++;
        s++;
    }
    *s = '\0';
}

int mod_check(char *str) {
    int error = 3;
    if (!strncmp(str, "mod", 3)) {
        str += 3;
        if (!strrchr("+-0123456789cstal(x", *str)) error = -1;
        if (*str == '\0') error = -1;
    } else {
        error = -1;
    }
    return error;
}

int sign_check(char *str, int prev_char) {
    int error = 1;
    if (strrchr("*/^", *str)) {
        if (prev_char == 0) error = -1;
        str++;
        if (!strrchr("+-0123456789cstal(x", *str)) error = -1;
        if (*str == '\0') error = -1;
    } else if (strrchr("m", *str)) {
        error = mod_check(str);
        if (prev_char == 0) error = -1;
    } else if (strrchr("+-", *str)) {
        str++;
        if (!strrchr("0123456789cstal(x", *str)) error = -1;
        if (!strrchr("()1234567890x", prev_char) && prev_char != 0) error = -1;
        if (*str == '\0') error = -1;
    }
    return error;
}

int option_help(char *str) {
    int error = 0;
    if (!strrchr("(", *str)) error = -1;
    if (*str == '\0') error = -1;
    if (error != -1) {
        str += 1;
        if (!strrchr("+-0123456789cstalx", *str)) error = -1;
        if (strrchr("+-", *str)) {
            str += 1;
            if (!strrchr("0123456789cstal(x", *str)) error = -1;
            if (*str == '\0') error = -1;
        }
        if (*str == '\0') error = -1;
    }
    return error;
}

int option_check(char *str) {
    int error = 0;
    int slip = 0;
    if (!strncmp(str, "cos", 3) ||
        !strncmp(str, "sin", 3) ||
        !strncmp(str, "tan", 3) ||
        !strncmp(str, "log", 3)) {
        str += 3;
        error = option_help(str);
        slip = 3;
    } else if (!strncmp(str, "acos", 4) ||
               !strncmp(str, "asin", 4) ||
               !strncmp(str, "atan", 4) ||
               !strncmp(str, "sqrt", 4)) {
        str += 4;
        error = option_help(str);
        slip = 4;
    } else if (!strncmp(str, "ln", 2)) {
        str += 2;
        error = option_help(str);
        slip = 2;
    } else {
        error = -1;
    }
    return error == -1 ? error : slip;
}


int err_station(char *str, int error) {
    int err = 0;
    if (*str != '\0') {
        char *s = str;
        int prev_char = 0;
        delete_space(str);
        err = bracket_check(str);
        while (*str && err != -1) {
            if (*str >= '0' && *str <= '9') {
                err = num_check(str);
            } else if (strrchr("+-*/^m", *str)) {
                err = sign_check(str, prev_char);
            } else if (strrchr("cstal", *str)) {
                err = option_check(str);
            } else if (*str == '(' || *str == ')') {
                err = 1;
            } else if (*str == 'x') {
                if (error == 0) {
                    err = check_x(str);
                } else {
                    err = -1;
                }
            } else {
                err = -1;
            }
            prev_char = *str;
            if (err != -1) {
                str += err;
            }
        }
        delim_str(s);
    } else {
        err = -1;
    }
    return err;
}

void delim_str(char *str) {
    char buf[700] = {0};
    char *s = str;
    buf[0] = '$';
    int i = 1;
    while (*str) {
        if ((*str >= '0' && *str <= '9') || *str == '.') {
            while ((*str >= '0' && *str <= '9') || *str == '.') {
                buf[i] = *str;
                str++;
                i++;
            }
            buf[i] = '$';
            i++;
        } else if (strrchr("+-*/^x", *str)) {
            buf[i] = *str;
            str++;
            i++;
            buf[i] = '$';
            i++;
        } else if (strrchr("cstalm", *str)) {
            if (strrchr("l", *str)) {
                for (int j = 2; j > 0; j--) {
                    buf[i] = *str;
                    str++;
                    i++;
                }
            } else if (strrchr("oia", *(str+1))) {
                for (int j = 3; j > 0; j--) {
                    buf[i] = *str;
                    str++;
                    i++;
                }
            } else if (strrchr("as", *str)) {
                for (int j = 4; j > 0; j--) {
                    buf[i] = *str;
                    str++;
                    i++;
                }
            } else {
                str++;
            }
            buf[i] = '$';
            i++;
        } else if (*str == '(' || *str == ')') {
            buf[i] = *str;
            str++;
            i++;
            buf[i] = '$';
            i++;
        } else {
            str++;
        }
    }
    int j = 0;
    while (j < i) {
        *s = buf[j];
        j++;
        s++;
    }
    *s = '\0';
}


/*_________________________________________________________________________________________________
______________________________________ПАРСЕР ОШИБOК ВВЕРХУ_______________________________________________*/



/*_________________________________________________________________________________________________
______________________________________STACK!_______________________________________________*/
void push(stack **head, double value, int priority, typel type) {
    stack *tmp = (stack*) malloc(sizeof(stack));
    tmp->value = value;
    tmp->priority = priority;
    tmp->type = type;
    tmp->next = *head;
    *head = tmp;
}

int insert(stack *head, int count, double value, int priority, typel type) {
    int err = 0;
    int i = 0;
    while (i < count && head) {
        head = head->next;
        i++;
    }
    if (head != NULL) {
        stack *tmp = (stack*) malloc(sizeof(stack));
        tmp->value = value;
        tmp->priority = priority;
        tmp->type = type;
        if (head->next) {
            tmp->next = head->next;
        } else {
            tmp->next = NULL;
        }
        head->next = tmp;
    }
    return err;
}

int pop(stack **head, double *value, int *priority, typel *type) {
    stack* prev = NULL;
    int err = 0;
    if ((*head) != NULL) {
        prev = (*head);
        if (value != NULL) *value = prev->value;
        if (priority != NULL) *priority = prev->priority;
        if (type != NULL) *type = prev->type;
        *head = (*head)->next;
        free(prev);
    } else {
        err = 1;
    }
    return err;
}

int peek(stack *head, int count, double *value, int *priority, typel *type) {
    int i = 0;
    int err = 0;
    while (i < count && head) {
        head = head->next;
        i++;
    }
    if (i == count && head) {
        if (value != NULL) *value = head->value;
        if (priority != NULL) *priority = head->priority;
        if (type != NULL) *type = head->type;
    } else {
        err = 1;
    }
    return err;
}

void peek_last(stack *head, double *value, int *priority, typel *type) {
    if (value != NULL) *value = head->value;
    if (priority != NULL) *priority = head->priority;
    if (type != NULL) *type = head->type;
}

void insert_del(stack **head, int count, double *value, int *priority, typel *type) {
    if (count == 0) {
        pop(head, NULL, NULL, NULL);
    } else {
        if (head) {
            stack *elem = *head;
            int i = 0;
            while (i < count-1 && elem) {
                elem = elem->next;
                i++;
            }
            if (elem) {
                stack *del_elem = elem->next;
                if (value != NULL) *value = del_elem->value;
                if (priority != NULL) *priority = del_elem->priority;
                if (type != NULL) *type = del_elem->type;
                elem->next = del_elem->next;
                free(del_elem);
            }
        }
    }
}

/*_________________________________________________________________________________________________
______________________________________PARSE!_______________________________________________*/

void parse_leksOPT(char *str, stack **head, double x, int error) {
    typel type = 0;
    int t = 0;
    if (*str >= '0' && *str <= '9') {
        char buf[100] = {0};
        int i = 0;
        while (*str) {
            buf[i] = *str;
            str++;
            i++;
        }
        buf[i] = '\0';
        double chisl = 0;
        sscanf(buf, "%lf", &chisl);
        push(head, chisl, 0, 1);
    } else if (*str == '+' || *str == '-') {
        if (*head) peek_last(*head, &x, &t, &type);
        if (type == 0 || type == 9) push(head, 0, 0, 1);
        if (*str == '+') push(head, 0, 1, 3);
        if (*str == '-') push(head, 0, 1, 4);
    } else if (*str == '*') { push(head, 0, 2, 5);
    } else if (*str == 'x' && error == 0) { push(head, x, 0, 1);
    } else if (*str == '/') { push(head, 0, 2, 6);
    } else if (*str == 'm') { push(head, 0, 2, 7);
    } else if (*str == '^') { push(head, 0, 3, 8);
    } else if (*str == '(') { push(head, 0, -1, 9);
    } else if (*str == ')') { push(head, 0, -1, 10);
    } else if (*str == 'c') { push(head, 0, 4, 12);
    } else if (*str == 't') { push(head, 0, 4, 13);
    } else if (*str == 's' || *str == 'l' || *str == 'a') {
        str++;
        if (*str == 'i') push(head, 0, 4, 11);
        if (*str == 'q') push(head, 0, 4, 17);
        if (*str == 'n') push(head, 0, 4, 18);
        if (*str == 'o') push(head, 0, 4, 19);
        if (*str == 'c') push(head, 0, 4, 14);
        if (*str == 's') push(head, 0, 4, 15);
        if (*str == 't') push(head, 0, 4, 16);
    }
}

int parse_leks(char *str, stack **head, double x, int error) {
    char *saveptr1;
    char *leks = strtok_r(str, "$", &saveptr1);
    while (leks != NULL) {
        parse_leksOPT(leks, head, x, error);
        leks = strtok_r(NULL, "$", &saveptr1);
    }
    return 0;
}

void reverse_stack(stack **head, stack **reverse_s) {
    double value = 0;
    int priority = 0;
    typel type = 0;
    while (!pop(head, &value, &priority, &type)) {
        push(reverse_s, value, priority, type);
    }
}

/*_________________________________________________________________________________________________
______________________________________RPN!_______________________________________________*/

stack* RPN(stack **head) {
    stack *support = NULL;
    stack *ready = NULL;
    double value = 0;
    int priority = 0;
    typel type = 0;
    int prior_sup = 0;
    while (!pop(head, &value, &priority, &type)) {
        if (priority == 0) push(&ready, value, priority, type);
        if (priority > 0 && priority < 5) {
            if (support != NULL) peek_last(support, NULL, &prior_sup, NULL);
            double buf_value = value;
            int buf_priority = priority;
            typel buf_type = type;
                while (prior_sup >= priority) {
                    pop(&support, &value, &priority, &type);
                    push(&ready, value, priority, type);
                    if (support != NULL) {
                        peek_last(support, NULL, &prior_sup, NULL);
                        priority = buf_priority;
                    } else {
                        prior_sup = -2;
                    }
                }
                push(&support, buf_value, buf_priority, buf_type);
        }
        if (priority == -1) {
            if (type == 9) push(&support, value, priority, type);
            if (type == 10) {
                while (type != 9) {
                    pop(&support, &value, &priority, &type);
                    if (type != 9) push(&ready, value, priority, type);
                }
            }
        }
    }
    while (!pop(&support, &value, &priority, &type)) {
        push(&ready, value, priority, type);
    }
    return ready;
}

/*_________________________________________________________________________________________________
______________________________________CALCULATE!_______________________________________________*/
void func_calculate(stack **head, int count, typel type) {
    double value = 0;
    double res = 0;
    peek(*head, (count-1), &value, NULL, NULL);
    if (type == 11) res = sin(value);
    if (type == 12) res = cos(value);
    if (type == 13) res = tan(value);
    if (type == 14) res = acos(value);
    if (type == 15) res = asin(value);
    if (type == 16) res = atan(value);
    if (type == 17) res = sqrt(value);
    if (type == 18) res = log(value);
    if (type == 19) res = log10(value);
    for (int j = 2; j > 0; j--) {
        insert_del(head, count, NULL, NULL, NULL);
        count--;
    }
    if (count < 0) {
        push(head, res, 0, 1);
    } else {
        insert(*head, count, res, 0, 1);
    }
}

double calculate(stack **head) {
    while (!peek(*head, 1, NULL, NULL, NULL)) {
        double value = 0;
        int priority = 0;
        typel type = 0;
        double buf_value = 0;
        int count = 0;
        while (priority == 0) {
            peek(*head, count, &value, &priority, &type);
            count++;
        }
        count--;
        if (priority > 0 && priority < 5) {
            if (type >= 3 && type <= 8) {
                double res = 0;
                peek(*head, (count-1), &buf_value, NULL, NULL);
                peek(*head, (count-2), &value, NULL, NULL);
                if (type == 3) res = value + buf_value;
                if (type == 4) res = value - buf_value;
                if (type == 5) res = value * buf_value;
                if (type == 6) res = value / buf_value;
                if (type == 7) res = fmod(value, buf_value);
                if (type == 8) res = pow(value, buf_value);
                for (int j = 3; j > 0; j--) {
                    insert_del(head, count, NULL, NULL, NULL);
                    count--;
                }
                if (count < 0) {
                    push(head, res, 0, 1);
                } else {
                    insert(*head, count, res, 0, 1);
                }
            } else {
                func_calculate(head, count, type);
            }
        }
    }
    double result = 0;
    pop(head, &result, NULL, NULL);
    return result;
}

double base(char *str, double x, int error) {
    stack *head = NULL;
    parse_leks(str, &head, x, error);
    stack *reverse_s = NULL;
    reverse_stack(&head, &reverse_s);
    stack *ready = RPN(&reverse_s);
    stack *reverse_RPN = NULL;
    reverse_stack(&ready, &reverse_RPN);
    double ok = calculate(&reverse_RPN);
    return ok;
}

int Smart_Calc(char *str, char *strx, double *res) {
    int err = -1;
    int error = 0;
    if (strx == NULL || *strx == '\0') {
        error = -1;
    }
    if (err_station(str, error) != -1) {
        int check = -1;
        double x = 0;
        if (error != -1) {
            if (err_station(strx, 1) != -1) {
                if (error == 0) {
                    check = 0;
                    x = base(strx, x, 1);
                }
            }
        }
        *res = base(str, x, check);
        err = 0;
    }
    return err;
}
