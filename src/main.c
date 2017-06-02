#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    char *string;
    string = malloc(sizeof(char) * 300);
    int z = 0, i = 0, a = 0;

    for (i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] == ' ') {
            continue;
        }
        if (chcmp(argv[1][i], "()+-*/,.0123456789")) {   
            if (argv[1][i] != ',') {
                string[z] = argv[1][i];
            } else {
                string[z] = '.';
            }
            z++;

            if (argv[1][i] == '(') {
                a++;
            } else if (argv[1][i] == ')' && --a < 0) {
                    printf("Ошибка ввода. Скобка закрыта до открытия\n");
                    return 1;
                }
        } else {
            printf("Ошибка ввода. Запрещенный символ\n");
            return 1;
        }
    }

    if (a != 0) {
        printf("Ошибка ввода. Нарушен баланс скобок\n");
        return 1;
    }

    if (check(string) == 0){
        double result = solution(string, 0, z - 1);
        printf("\t%s = %.3lf\n", string, result);
    }
    
    return 0;
}
