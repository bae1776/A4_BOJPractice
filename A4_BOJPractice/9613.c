//https://www.acmicpc.net/problem/9613

//GCDÇÕ


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {
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

	return a;
}


int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int numCount;
		scanf("%d", &numCount);
		int* tempArr = (int*)malloc(sizeof(int) * numCount);

		for (int j = 0; j < numCount; j++)
		{
			scanf("%d", &tempArr[j]);
		}

		long long int answer = 0;

		for (int j = 0; j < numCount; j++)
		{
			for (int k = j + 1; k < numCount; k++)
			{
				answer += GCD(tempArr[j], tempArr[k]);
			}
		}
		printf("%lld\n", answer);

		free(tempArr);


	}
}