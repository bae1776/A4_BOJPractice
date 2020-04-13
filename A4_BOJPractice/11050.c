//https://www.acmicpc.net/problem/11050

//N, K�� �־��� �� nCk�� ���Ͻÿ�.
//n�� 10 ������ �ڿ���

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