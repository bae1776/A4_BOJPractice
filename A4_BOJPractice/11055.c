//https://www.acmicpc.net/problem/11052

//���� ū ���� �κ� ����
//���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ����
//�� ���� ����Ͻÿ�.

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


