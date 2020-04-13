//https://www.acmicpc.net/problem/11047

//�ر԰� ������ �ִ� ������ ������ �־�����, �� ������ ������ ����� ���� ������ �ִٰ� �� ��
//������ ������ ����Ͽ� K������ ������� �� ��, �ʿ��� ���� ������ �ּҴ�?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int coin_count, total;
	scanf("%d %d", &coin_count, &total);

	int* coins = (int*)malloc(sizeof(int) * coin_count);
	for (int i = 0; i < coin_count; i++)
		scanf("%d", &coins[i]);

	int minCoin = 0;
	for (int i = coin_count - 1; i >= 0; i--) {
		while (total >= coins[i]) {
			total -= coins[i];
			minCoin++;
		}
	}

	printf("%d", minCoin);
	free(coins);
}
