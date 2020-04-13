//https://www.acmicpc.net/problem/9498

//점수를 입력받아 랭크를 출력받는 프로그램이다.

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


