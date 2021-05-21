//https://www.acmicpc.net/problem/12865

//평범한 배낭
//준서가 N개의 물건 중 고르려고 한다.
//각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다.
//준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다.
//준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 출력하는 프로그램을 작성하여라.

//전형적인 냅색 문제이다.

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
