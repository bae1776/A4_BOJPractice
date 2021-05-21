//https://www.acmicpc.net/problem/12865

//����� �賶
//�ؼ��� N���� ���� �� ������ �Ѵ�.
//�� ������ ���� W�� ��ġ V�� �����µ�, �ش� ������ �賶�� �־ ���� �ؼ��� V��ŭ ��� �� �ִ�.
//�ؼ��� �ִ� K���Ա����� �賶�� ��� �ٴ� �� �ִ�.
//�ؼ��� �ִ��� ��ſ� ������ �ϱ� ���� �賶�� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͽ���.

//�������� ���� �����̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int weight;
	int value;
} Good;


int main(void)
{
	int good_count, maxWeight;
	scanf("%d %d", &good_count, &maxWeight);

	Good* goodList = (Good*)malloc(sizeof(Good) * (good_count+1));
	int** DP = (int**)malloc(sizeof(int*) * (good_count + 1));
	DP[0] = (int*)calloc(maxWeight + 1, sizeof(int));

	for (int i = 1; i <= good_count; i++)
	{
		DP[i] = (int*)calloc(maxWeight + 1, sizeof(int));
		scanf("%d %d", &goodList[i].weight, &goodList[i].value);
	}

	int max = 0;

	for (int i = 1; i <= good_count; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (goodList[i].weight > j) DP[i][j] = DP[i - 1][j];
			else {
				DP[i][j] = DP[i - 1][j - goodList[i].weight] + goodList[i].value > DP[i - 1][j] ? 
					DP[i - 1][j - goodList[i].weight] + goodList[i].value : DP[i - 1][j];
			}
			if (DP[i][j] > max) max = DP[i][j];
		}
	}

	printf("%d", max);

}
