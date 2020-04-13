//https://www.acmicpc.net/problem/1934

//최소공배수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) 
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) 
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int orga = a;
		int orgb = b;

		while (b != 0) {
			if (a < b)
			{
				int temp = a;
				a = b;
				b = temp;
			}

			int rest = a % b;
			a = b;
			b = rest;
		}

		printf("%d\n", orga * orgb / a);

	}
}