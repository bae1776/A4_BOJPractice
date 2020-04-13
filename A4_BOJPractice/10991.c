//https://www.acmicpc.net/problem/10991

//별 찍기 - 16
//input : 4
//   *
//  * *
// * * *
//* * * *

//이런 식으로 별을 찍어보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - i - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			printf("%c", j % 2 == 0 ? '*' : ' ');
		}
		printf("\n");
	}
}