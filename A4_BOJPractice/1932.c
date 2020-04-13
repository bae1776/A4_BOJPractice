//https://www.acmicpc.net/problem/1904

//�Ľ�Į �ﰢ�� ó�� �Ƕ�̵� ���� �ﰢ���� �־�����.
//�� �������� �����ؼ� ������ �Ʒ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, �������� ���õ� ���� ����
//�ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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