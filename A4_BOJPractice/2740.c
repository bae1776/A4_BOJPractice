//https://www.acmicpc.net/problem/2740

//행렬곱을 구현하세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** matrixMul(int** matrix1, int** matrix2, int firstrow, int middle, int secondcol) {
	int** resultMatrix = (int**)malloc(sizeof(int*) * firstrow);

	for (int i = 0; i < firstrow; i++) {
		resultMatrix[i] = (int*)calloc(secondcol, sizeof(int));
		for (int j = 0; j < secondcol; j++) {
			for (int k = 0; k < middle; k++) {
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return resultMatrix;
}

int main(void)
{
	int N, M, K;
	scanf("%d %d", &N, &M);

	int** matrix1 = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		matrix1[i] = (int*)malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &matrix1[i][j]);
		}
	}

	scanf("%d %d", &M, &K);

	int** matrix2 = (int**)malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++) {
		matrix2[i] = (int*)malloc(sizeof(int) * K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &matrix2[i][j]);
		}
	}

	int** resultMatrix = matrixMul(matrix1, matrix2, N, M, K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("%d ", resultMatrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		free(resultMatrix[i]);
	}
	free(resultMatrix);

	return 0;
}