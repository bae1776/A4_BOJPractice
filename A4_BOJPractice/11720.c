#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//https://www.acmicpc.net/problem/11720

//숫자열의 자릿수와 숫자열을 입력하면 각 자리의 합이 나오도록 하는 프로그램입니다.

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