//https://www.acmicpc.net/problem/10817

//�� ���� �Է¹ް� �� �� �ι�°�� ū ���� ����ϴ� ���α׷��̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int Mid = (a > b) ? ((a > c) ? ((b > c) ? b : c) : a) : ((b > c) ? ((a > c) ? a : c) : b);
	//���� ����̴�. ���ش� �˾Ƽ� �ض�
	printf("%d", Mid);
}