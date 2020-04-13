//https://www.acmicpc.net/problem/9465

//스티커

//상냥이는 문방구에서 스티커 2n개를 구매했다. 
//스티커는 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

//상냥이가 구매한 스티커의 품질은 매우 좋지 않다.
//스티커 한 장을 떼면, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없다.
//어쩔 수 없이 상냥이는 각 스티커에 점수를 매기고, 
//점수의 합이 최대가 되도록 스티커를 떼내려 한다. 

//테스트 케이스 수와 각 테스트 케이스에 대한
//스티커 열 길이 n(~100000), 각 스티커의 점수(~100)가 주어질 때, 점수 합의 최대를 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TOPSELECT 0
#define TOP 0
#define BTMSELECT 1
#define BTM 1
#define NONSELECT 2

int MAX(int a, int b) {
	return a > b ? a : b;
}

int MAX3(int a, int b, int c) {
	if (a > b) {
		return MAX(a, c);
	}
	else return MAX(b, c);
}


int main(void)
{
	int testcase;
	int(*DP)[3];
	int(*stickerScore)[2];

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int col;
		scanf("%d", &col);

		//DP[colNum][state]
		DP = (int(*)[3])malloc(sizeof(int) * 3 * (col + 1));
		stickerScore = (int(*)[2])malloc(sizeof(int) * 2 * (col + 1));
		DP[0][TOPSELECT] = DP[0][BTMSELECT] = DP[0][NONSELECT] = 0;

		for (int j = 1; j <= col; j++)
			scanf("%d", &stickerScore[j][TOP]);
		for (int j = 1; j <= col; j++)
			scanf("%d", &stickerScore[j][BTM]);

		for (int j = 1; j <= col; j++)
		{
			DP[j][TOPSELECT] =
				MAX(DP[j - 1][BTMSELECT], DP[j - 1][NONSELECT]) + stickerScore[j][TOP];
			DP[j][BTMSELECT] =
				MAX(DP[j - 1][TOPSELECT], DP[j - 1][NONSELECT]) + stickerScore[j][BTM];
			DP[j][NONSELECT] =
				MAX3(DP[j - 1][BTMSELECT], DP[j - 1][NONSELECT], DP[j - 1][TOPSELECT]);
		}

		printf("%d\n", MAX3(DP[col][BTMSELECT], DP[col][NONSELECT], DP[col][TOPSELECT]));

		free(DP);
		free(stickerScore);
	}

	return 0;
}

