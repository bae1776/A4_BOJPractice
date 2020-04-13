//https://www.acmicpc.net/problem/9465

//��ƼĿ

//����̴� ���汸���� ��ƼĿ 2n���� �����ߴ�. 
//��ƼĿ�� 2�� n���� ��ġ�Ǿ� �ִ�. ����̴� ��ƼĿ�� �̿��� å���� �ٹ̷��� �Ѵ�.

//����̰� ������ ��ƼĿ�� ǰ���� �ſ� ���� �ʴ�.
//��ƼĿ �� ���� ����, �� ��ƼĿ�� ����, ������, ��, �Ʒ��� �ִ� ��ƼĿ�� ����� �� ����.
//��¿ �� ���� ����̴� �� ��ƼĿ�� ������ �ű��, 
//������ ���� �ִ밡 �ǵ��� ��ƼĿ�� ������ �Ѵ�. 

//�׽�Ʈ ���̽� ���� �� �׽�Ʈ ���̽��� ����
//��ƼĿ �� ���� n(~100000), �� ��ƼĿ�� ����(~100)�� �־��� ��, ���� ���� �ִ븦 ���Ͻÿ�.

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

