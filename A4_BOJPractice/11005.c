//https://www.acmicpc.net/problem/11005

//���� ��ȯ 2
//��ȯ�� 10���� N ���� ���� P(2~36)�� �־�����,
//N���� P������ ��ȯ�ϼ���.
//10 �̻��� ���� ���ĺ� �빮�� ������ ǥ���Ͻʽÿ�.

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
