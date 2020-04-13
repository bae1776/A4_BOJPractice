//https://www.acmicpc.net/problem/11005

//진법 변환 2
//변환할 10진수 N 값과 정수 P(2~36)가 주어질때,
//N값을 P진수로 변환하세요.
//10 이상의 수는 알파벳 대문자 순으로 표시하십시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char digits[36];
char stack[100];
int top = -1;

int main(void)
{
	for (int i = 0; i < 10; i++) {
		digits[i] = '0' + i;
	}
	for (int i = 10; i < 36; i++) {
		digits[i] = 'A' - 10 + i;
	}

	int num, radix;
	scanf("%d %d", &num, &radix);

	while (num != 0) {
		stack[++top] = num % radix;
		num /= radix;
	}

	while (top >= 0) {
		printf("%c", digits[stack[top--]]);
	}

}
