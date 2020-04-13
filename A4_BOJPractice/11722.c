//https://www.acmicpc.net/problem/11722

//수열이 주어질 때, 가장 긴 감소하는 부분 수열의 길이를 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int arrsize;
	scanf("%d", &arrsize);

	int* arr = (int*)malloc(sizeof(int) * arrsize);
	int* DP = (int*)malloc(sizeof(int) * arrsize);

	for (int i = 0; i < arrsize; i++)
		scanf("%d", &arr[i]);

	DP[0] = 1;
	
	for (int i = 1; i < arrsize; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && DP[j] > max) max = DP[j];
		}
		DP[i] = max + 1;
	}

	int max = 0;
	for (int i = 0; i < arrsize; i++) {
		if (DP[i] > max) max = DP[i];
	}

	printf("%d", max);

	free(arr);
	free(DP);


	return 0;
}