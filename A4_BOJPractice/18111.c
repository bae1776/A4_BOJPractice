//https://www.acmicpc.net/problem/18111

//마인크래프트
//(문제가 너무 길어서 생략)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	int row, col, block;
	scanf("%d %d %d", &row, &col, &block);

	int maxHeight = 0, minHeight = 256;

	int** maps = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		maps[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &maps[i][j]);
			if (maps[i][j] > maxHeight) maxHeight = maps[i][j];
			if (maps[i][j] < minHeight) minHeight = maps[i][j];
		}
	}

	int result = 0x7FFFFFFF;
	int resHeight = 0x7FFFFFFF;

	for (int targetHeight = maxHeight; targetHeight >= minHeight; targetHeight--) 
	{
		int caseTime = 0, caseBlockUse = 0;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (maps[i][j] > targetHeight)
					//퍼내기 작업
				{
					caseTime += (maps[i][j] - targetHeight) * 2;
					caseBlockUse -= maps[i][j] - targetHeight;
				}
				else if (maps[i][j] < targetHeight)
					//블럭놓기 작업
				{
					caseTime += targetHeight - maps[i][j];
					caseBlockUse += targetHeight - maps[i][j];
				}
			}

		if (caseBlockUse > block) //블럭이 부족하므로 불가능한 경우임
			continue;
		else {
			if (caseTime < result)
			{
				result = caseTime;
				resHeight = targetHeight;
			}
		}
	}


	printf("%d %d", result, resHeight);

	for (int i = 0; i < row; i++)
		free(maps[i]);
	free(maps);


	return 0;
}