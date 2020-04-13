//https://www.acmicpc.net/problem/11053

//가장 긴 부분 수열의 길이를 구하시오.
//10 20 10 30 20 50
//에서 가장 긴 부분 수열은
//10 20    30    50 이다.
//수열의 길이는 1000개 이하다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);
	
	int* arr = (int*)malloc(sizeof(int) * arrlen);
	int* dp = (int*)calloc(arrlen, sizeof(int));
	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);
	dp[0] = 1;

	for (int i = 1; i < arrlen; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (dp[j] > max && arr[j] < arr[i]) max = dp[j];
		}
		dp[i] = max + 1;
	}

	int dpmax = 0;
	for (int i = 0; i < arrlen; i++)
	{
		if (dp[i] > dpmax) dpmax = dp[i];
	}

	printf("%d", dpmax);
}


 