//https://www.acmicpc.net/problem/1912

//n개의 정수로 이루어진 임의의 수열이 주어진다.
//우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
//단, 수는 한 개 이상 선택해야 한다.
//예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12 + 21인 33이 정답이 된다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);
	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);

	int* dp = (int*)malloc(sizeof(int) * arrlen);
	dp[0] = arr[0];

	int max = dp[0];

	for (int i = 1; i < arrlen; i++)
	{
		if (dp[i - 1] > 0)
			dp[i] = arr[i] + dp[i - 1];
		else
			dp[i] = arr[i];
		if (dp[i] > max) max = dp[i];
	}
	
	printf("%d", max);

	return 0;
}
