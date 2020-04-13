//https://www.acmicpc.net/problem/10992

//별 찍기 - 17
//input : 4
//   *
//  * *
// *   *
//*******

//이런 식으로 별을 찍어보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input - 1; i++) {
		for (int j = 0; j < input - i - 1; j++) {
			printf(" ");
		}
		printf("*");
		for (int j = 0; j < i * 2 - 1; j++) {
			printf(" ");
		}
		if (i != 0) printf("*");
		printf("\n");
	}

	for (int i = 0; i < input * 2 - 1; i++) {
		printf("*");
	}
}