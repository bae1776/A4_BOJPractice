//https://www.acmicpc.net/problem/11047

//준규가 가지고 있는 동전의 종류가 주어지고, 각 종류의 동전을 충분히 많이 가지고 있다고 할 때
//동전을 적절히 사용하여 K원으로 만들려고 할 때, 필요한 동전 개수의 최소는?

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
