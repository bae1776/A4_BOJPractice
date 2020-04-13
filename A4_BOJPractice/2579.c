//https://www.acmicpc.net/problem/2579

//��� ������
//�������κ��� �����ؼ� ���� �������� ����� �� ĭ �Ǵ� �� ĭ�� �ö󰣴�.
//��, ����� 3�� �������� ���� ���� ����.
//�� ��, ���� �������� �ִ� ������ ����� ���� ������ ���Ͽ���.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int midScore;

int main(void)
{
	int stairNum;
	scanf("%d", &stairNum);

	int* stairScore = (int*)malloc(sizeof(int) * stairNum);
	for (int i = 0; i < stairNum; i++)
	{
		scanf("%d", &stairScore[i]);
	}

	midScore* nDoubleStep = (midScore*)malloc(sizeof(midScore) * stairNum);
	midScore* doubleStep = (midScore*)malloc(sizeof(midScore) * stairNum);
	
	nDoubleStep[0] = stairScore[0];
	doubleStep[0] = 0;

	if (stairNum >= 2)
	{
		nDoubleStep[1] = stairScore[1];
		doubleStep[1] = stairScore[0] + stairScore[1];
	}

	for (int i = 2; i < stairNum; i++)
	{
		nDoubleStep[i] = (doubleStep[i-2] > nDoubleStep[i-2] ? 
			doubleStep[i-2] : nDoubleStep[i-2]) + stairScore[i];
		doubleStep[i] = nDoubleStep[i - 1] + stairScore[i];
	}

	printf("%d", doubleStep[stairNum - 1] > nDoubleStep[stairNum - 1] ? doubleStep[stairNum - 1] : nDoubleStep[stairNum - 1]);

	free(stairScore);
	free(nDoubleStep);
	free(doubleStep);

	return 0;
}
