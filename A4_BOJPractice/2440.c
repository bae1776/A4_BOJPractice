//https://www.acmicpc.net/problem/2440

//별 찍기 - 3
//input : 5
//*****
//****
//***
//**
//*

//이런 식으로 별을 찍어보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}