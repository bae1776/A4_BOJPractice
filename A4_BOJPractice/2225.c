//https://www.acmicpc.net/problem/2225

//�պ���
//���� N�� 0 �Ǵ� ���� ���� K���� �� �÷� ��Ÿ���� ����� �� % 10�� �� ���Ͻÿ�.
//������ ������ �ٲ�� �ٸ� ���� ����Ѵ�.

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
