//https://www.acmicpc.net/problem/8393

//1부터 n까지의 합은?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input, sum = 0;
	scanf("%d", &input);
	for (; input >= 1; input--) {
		sum += input;
	}
	printf("%d", sum);
}