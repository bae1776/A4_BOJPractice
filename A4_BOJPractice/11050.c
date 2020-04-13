//https://www.acmicpc.net/problem/11050

//N, K가 주어질 때 nCk를 구하시오.
//n은 10 이하의 자연수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int num) {
	if (num <= 1) return 1;
	else return factorial(num - 1) * num;
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", factorial(n) / factorial(n - k) / factorial(k));
}