//https://www.acmicpc.net/problem/1065

//�Է��� ���� ������ "�Ѽ�"�� ������ ����ϴ� �����̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hansu(int input) {
	int output = 0;
	for (int i = 1; i <= input; i++) {
		if (i >= 100) {
			int dary[3] = { i / 100, i / 10 % 10, i % 10 };
			if (dary[0] + dary[2] == 2*dary[1]) output++;
		}
		else output++;
	}
	return output;
}

int main() {
	int input;
	scanf("%d", &input);
	printf("%d", hansu(input));
	return 0;
}
