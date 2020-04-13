//https://www.acmicpc.net/problem/2748

//n을 입력받아 n의 피보나치 수를 구하시오.
//fib(0) = 0, fib(1) = 1임.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long getFib(long long* dyArr, int n)
{
	for (int i = 2; i <= n; i++)
		dyArr[i] = dyArr[i - 1] + dyArr[i - 2];

	return dyArr[n];
}

int main(void)
{
	int n;
	scanf("%d", &n);

	if (n <= 1)
		printf("%d", n);
	else {
		long long* tempFib = (long long*)malloc(sizeof(long long) * (n+1));
		tempFib[0] = 0;
		tempFib[1] = 1;
		printf("%lld", getFib(tempFib, n));
		free(tempFib);
	}

	
}