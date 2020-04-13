//https://www.acmicpc.net/problem/2522

//별 찍기 - 12
//input : 4
//   *
//  **
// ***
//****
// ***
//  **
//   *

//이런 식으로 별을 찍어보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - 1 - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = input - 2; i >= 0; i--) {
		for (int j = 0; j < input - 1 - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}