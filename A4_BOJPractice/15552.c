//https://www.acmicpc.net/problem/15552

//�������� ����� �Է� �ް� �� �������� �Է��ؼ� �� ���� ����ϴ� ���α׷��̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int input, a, b;
	scanf("%d ", &input);
	for (int i = 1; i <= input; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
}
