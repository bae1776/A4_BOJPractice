#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//https://www.acmicpc.net/problem/11720

//���ڿ��� �ڸ����� ���ڿ��� �Է��ϸ� �� �ڸ��� ���� �������� �ϴ� ���α׷��Դϴ�.

int main() {
	int input1;
	char input2[101];
	scanf("%d ", &input1);
	scanf("%s", &input2);
	int sum = 0;
	for (; input1 >= 1; input1--) {
		sum += input2[input1 - 1] - 48;
	}
	printf("%d", sum);
}