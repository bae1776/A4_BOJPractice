//https://www.acmicpc.net/problem/2442

//�� ��� - 5
//input : 4
//   *
//  ***
// *****
//*******

//�̷� ������ ���� ����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		for (int j = i + 1; j < input; j++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}