//https://www.acmicpc.net/problem/2004

//nCm의 끝자리 0의 개수는?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int getfactor(int factorial, int factor) {
	long long int sum = 0;
	for (long long int i = factor; ; i *= factor)
	{
		long long int temp = factorial / i;
		if (temp == 0) break;
		else sum += temp;
	}

	return sum;
}


int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	long long int factor2 = getfactor(n, 2) - getfactor(n-m, 2) - getfactor(m, 2);
	long long int factor5 = getfactor(n, 5) - getfactor(n - m, 5) - getfactor(m, 5);

	printf("%lld", factor2 > factor5 ? factor5 : factor2);

	return 0;
}