//https://www.acmicpc.net/problem/2588

//(���ڸ���)*(���ڸ���) ���� Ǯ��

//������ �� �� ��Ǯ�� �������� ����ϴ� �� ���� ���� ������ ������ ���� ����Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int digit[4] = { b % 10, b / 10 % 10, b / 100, b };

	for (int i = 0; i < 4; i++) {
		printf("%d\n", a * digit[i]);
	}
}