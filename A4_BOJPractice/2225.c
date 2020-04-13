//https://www.acmicpc.net/problem/2225

//합분해
//정수 N을 0 또는 양의 정수 K개의 합 꼴로 나타내는 경우의 수 % 10억 을 구하시오.
//덧셈의 순서가 바뀌면 다른 경우로 취급한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	int** DP = (int**)malloc(sizeof(int*) * (N + 1));
	for (int i = 0; i <= N; i++) {
		DP[i] = (int*)calloc(K + 1, sizeof(int));
		DP[i][1] = 1;
	}

	for (int j = 2; j <= K; j++) {
		for (int i = 0; i <= N; i++) {
			long long int result = 0;
			for (int k = 0; k <= i; k++) {
				result += DP[k][j - 1];
			}
			result %= 1000000000;
			DP[i][j] = (int)result;
		}
	}

	printf("%d", DP[N][K]);


	for (int i = 0; i <= N; i++)
		free(DP[i]);
	free(DP);
}
