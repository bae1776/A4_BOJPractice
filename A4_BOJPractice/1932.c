//https://www.acmicpc.net/problem/1904

//파스칼 삼각형 처럼 피라미드 정수 삼각형이 주어진다.
//맨 위층에서 시작해서 인접한 아래 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이
//최대가 되는 경로를 구하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int height;
	scanf("%d", &height);

	int** tower = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++)
	{
		tower[i] = (int*)malloc(sizeof(int) * (i + 1));
		for (int j = 0; j <= i; j++)
			scanf("%d", &tower[i][j]);
	}


	int* pileValue = (int*)calloc(height, sizeof(int));
	pileValue[0] = tower[0][0];

	for (int i = 1; i < height; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (j == i)
			{
				pileValue[j] = pileValue[j - 1] + tower[i][j];
			}
			else if (j == 0)
			{
				pileValue[j] += tower[i][j];
			}
			else
			{
				pileValue[j] = (pileValue[j - 1] > pileValue[j] ? pileValue[j - 1] : pileValue[j]) + tower[i][j];
			}
		}
	}


	int max = pileValue[0];
	for (int i = 1; i < height; i++)
		if (max < pileValue[i]) max = pileValue[i];

	printf("%d", max);

}