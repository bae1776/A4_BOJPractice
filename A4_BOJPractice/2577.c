//https://www.acmicpc.net/problem/2577 (문제 번호)

//세 수의 곱의 자릿수의 숫자가 몇 개 쓰였는가 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d ", &A);
	scanf("%d ", &B);
	scanf("%d", &C);

	int product = A * B * C;
	char digitnum[10] = { 0, };

	for (; product != 0; product /= 10) {
		char digit = product % 10;
		digitnum[digit]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", digitnum[i]);
	}
	return 0;
}