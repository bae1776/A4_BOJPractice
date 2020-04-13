//https://www.acmicpc.net/problem/1850

//최대공약수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
		long long int a, b;
		scanf("%lld %lld", &a, &b);

		while (b != 0) {
			if (a < b)
			{
				long long int temp = a;
				a = b;
				b = temp;
			}

			long long int rest = a % b;
			a = b;
			b = rest;
		}

		for (int i = 0; i < a; i++)
		{
			printf("1");
		}
		printf("\n");

}