//https://www.acmicpc.net/problem/2579

//계단 오르기
//지면으로부터 시작해서 도착 지점까지 계단을 한 칸 또는 두 칸씩 올라간다.
//단, 계단을 3개 연속으로 밟을 수는 없다.
//이 때, 도착 지점까지 최대 점수를 얻었을 때의 점수를 구하여라.

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
