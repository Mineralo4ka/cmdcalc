#include <stdio.h>
#include "function.h"

double solution(char *str, int start, int N)
{
	int i = 0, count_1, count_2, count_3, count_4, tmp = 0;

	if ((str[start] == '(') && (str[N] == ')')) {
		count_1 = 1;
		count_2 = 0;
		i++;
		while(!(count_1 == count_2)) {
			if (str[i] == '(')
				count_1++;
			if (str[i] == ')')
				count_2++;
			i++;
		}
		i--;
		if (i == N) {
			return solution(str, start + 1, N - 1);
		}
	}

	for (i = start; i <= N; i++) {
		switch (str[i])
		{
			case '+':
				return solution(str, start, (i - 1)) + solution(str, (i + 1), N);
			case '-':
				if (i > tmp) {
					tmp = i;
				}
				break;
			case '*': 
				if (tmp == 0) {
					tmp = i;
				}
				break;
			case '/':
				if ((tmp == 0) || (str[tmp] == '/')) {
					tmp = i;
				}
				break;
			case '(':
				count_3 = 1;
				count_4 = 0;
				i++;
				while(!(count_3 == count_4)) {
					if (str[i] == '(')
						count_3++;
					if (str[i] == ')')
						count_4++;
					i++;
				}
				i--;
				break;
		}
	}

	if (tmp > 0) {
		switch(str[tmp])
		{
			case '-': return solution(str, start, tmp - 1) - solution(str, tmp + 1, N);
			case '*': return solution(str, start, tmp - 1) * solution(str, tmp + 1, N);
			case '/': return solution(str, start, tmp - 1) / solution(str, tmp + 1, N);
		}
	}

	return charToDigit(str, start, N);
}

char check(char *string)
{
	int j = 0, i;
	
    for (i = 0; string[i] != '\0'; i++) {
        if (( (string[i] == '.')  ) && ((0 > i - 1) || (string[i + 1] == '\0'))) {
            printf("Ошибка ввода. Вещественная часть не введена\n");
            return 1;
        }

        if (chcmp(string[i], "+-*/") && ( (0 >= i) || (string[i + 1] == '\0') || ( (string[i - 1] == '(')) || string[i + 1] == ')' || (((0 < i) && chcmp(string[i - 1], "+-*/")) || chcmp(string[i + 1], "+-*/")))) {
            printf("Ошибка ввода. Ошибка расстановки знаков\n");
            return 1;
        }

        if (string[i] == '.') {
            if (chcmp(string[i + 1], "()") || chcmp(string[i - 1], "()")) {
                printf("Ошибка ввода. Точка до или после скобки\n");
                return 1;
            }

            for (j = i + 1; string[j] != '\0'; ++j) {
                if (chcmp(string[j], "+-*/")) {
                    break;
                } else {
                    if (string[j] == '.') {
                        printf("Ошибка ввода. Более одной точки в одном числе\n");
                        return 1;
                    }
                }
            }
        }

        if ((string[i] == '(') && (0 < i)) {
            if (chcmp(string[i - 1], "(+-*/") == 0) {
                printf("Ошибка ввода. Нет знака до скобки\n");
                return 1;
            }

            if (string[i + 1] == ')') {
                printf("Ошибка ввода. () не допускается\n");
                return 1;
            }
        }

        if ((string[i] == ')') && (string[i + 1] != '\0')) {
            if (chcmp(string[i + 1], ")+-*/") == 0) {
                printf("Ошибка ввода. Нет знака после скобки\n");
                return 1;
            }
        }
    }

    return 0;
}

double charToDigit(char *str, int x1, int x2)
{
	double Result = 0, doubles = 0;
	int i, d;

	for (i = x1; i <= x2; i++) {
		if (str[i] != '.') {
			Result = (Result + (str[i] - '0')) * 10;
		} else {
			break;
		}
	}

	Result = Result / 10;
	d = i;

	for (i = i + 1; i <= x2; i++) {
		if (str[i] != '.') {
			Result = Result + (doubles + (str[i] - '0')) / power(10, i - d);
		} else {
			break;
		}
	}

	return Result;
}

int power(int x, int n)
{
	if(n == 0) {
		return 1;
	}

	if(n < 0) {
		return 1 / (x * power (1 / x, n + 1));
	}

	return x * power(x, n - 1);
}

int chcmp(char ch, char *arr)
{
	int i;

	for (i = 0; arr[i] != '\0'; ++i)
	{
		if (ch == arr[i])
			return 1;
	}

	return 0;
}