//https://www.acmicpc.net/problem/18111

//����ũ����Ʈ
//(������ �ʹ� �� ����)

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
					//�۳��� �۾�
				{
					caseTime += (maps[i][j] - targetHeight) * 2;
					caseBlockUse -= maps[i][j] - targetHeight;
				}
				else if (maps[i][j] < targetHeight)
					//������ �۾�
				{
					caseTime += targetHeight - maps[i][j];
					caseBlockUse += targetHeight - maps[i][j];
				}
			}

		if (caseBlockUse > block) //���� �����ϹǷ� �Ұ����� �����
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