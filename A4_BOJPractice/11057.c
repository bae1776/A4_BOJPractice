//https://www.acmicpc.net/problem/11057

//������ ��
//���� �ڸ��� ���������� �̷�� ���� ������ ����� �Ѵ�.
//���� ��� 11112, 1256 ������ ���Ѵ�.

//���� ���̰� �־�����, ������ ���� ���� % 10007 �� ���Ͻÿ�.
//���� 0���� ������ �� �ִ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int digitNum;
	scanf("%d", &digitNum);

	int** upSlopeCount = (int**)malloc(sizeof(int*) * (digitNum + 1));
	for (int i = 1; i <= digitNum; i++) {
		upSlopeCount[i] = (int*)malloc(sizeof(int) * 10);
	}
	for (int j = 0; j < 10; j++) {
		upSlopeCount[1][j] = 1;
	}

	for (int i = 2; i <= digitNum; i++) {
		for (int j = 0; j < 10; j++) {
			int temp = 0;
			for (int k = 0; k <= j; k++) {
				temp += upSlopeCount[i - 1][k];
			}
			upSlopeCount[i][j] = temp % 10007;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += upSlopeCount[digitNum][i];
	}

	printf("%d", result % 10007);

	for (int i = 1; i <= digitNum; i++)
		free(upSlopeCount[i]);
	free(upSlopeCount);


	return 0;
}