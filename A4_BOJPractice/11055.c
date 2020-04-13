//https://www.acmicpc.net/problem/11052

//가장 큰 증가 부분 수열
//수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구해
//그 합을 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sum;
	int nowLast;
} dpData;


int main(void)
{
	int arrsize;
	scanf("%d", &arrsize);

	int* arr = (int*)malloc(sizeof(int) * arrsize);
	dpData* DP = (dpData*)malloc(sizeof(dpData) * arrsize);

	for (int i = 0; i < arrsize; i++)
		scanf("%d", &arr[i]);

	DP[0].nowLast = DP[0].sum = arr[0];

	for (int i = 1; i < arrsize; i++)
	{
		DP[i].sum = DP[i].nowLast = arr[i];
		int validSumMax = 0;
		for (int j = 0; j < i; j++)
		{
			if (DP[j].nowLast < DP[i].nowLast && DP[j].sum > validSumMax) 
			{
				validSumMax = DP[j].sum;
			}
		}
		DP[i].sum += validSumMax;
	
	}

	int DPMax = 0;
	for (int i = 0; i < arrsize; i++)
	{
		if (DPMax < DP[i].sum) DPMax = DP[i].sum;
	}

	printf("%d", DPMax);

	free(arr);
	free(DP);


	return 0;
}


