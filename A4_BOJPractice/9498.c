//https://www.acmicpc.net/problem/9498

//������ �Է¹޾� ��ũ�� ��¹޴� ���α׷��̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);
	switch (input / 10) {
	case 10:
	case 9:
		printf("A"); break;
	case 8:
		printf("B"); break;
	case 7:
		printf("C"); break;
	case 6:
		printf("D"); break;
	default:
		printf("F");
	}
}


