//https://www.acmicpc.net/problem/10830

//(행렬)^N 을 구하세요. 행렬을 당연히 Square Matrix이며 크기는 2~5이고 N은 1000억 이하의 자연수.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixLen;

int** matrixExp(int** matrix, long long int exp) {

	if (exp == 1) return matrix;
	else {
		int** half = matrixExp(matrix, exp / 2);

		int** newMatrix = (int**)malloc(sizeof(int*) * matrixLen);
		for (int i = 0; i < matrixLen; i++) {
			newMatrix[i] = (int*)calloc(matrixLen, sizeof(int));
			for (int j = 0; j < matrixLen; j++) {
				for (int k = 0; k < matrixLen; k++) {
					newMatrix[i][j] += half[i][k] * half[k][j];
				}
				newMatrix[i][j] %= 1000;
			}
		}

		if (exp % 2 == 1) {
			int** copyMatrix = (int**)malloc(sizeof(int*) * matrixLen);
			for (int i = 0; i < matrixLen; i++) {
				copyMatrix[i] = (int*)malloc(sizeof(int) * matrixLen);
				for (int j = 0; j < matrixLen; j++) {
					copyMatrix[i][j] = newMatrix[i][j];
				}
			}

			for (int i = 0; i < matrixLen; i++) {
				for (int j = 0; j < matrixLen; j++) {
					newMatrix[i][j] = 0;
					for (int k = 0; k < matrixLen; k++) {
						newMatrix[i][j] += copyMatrix[i][k] * matrix[k][j];
					}
					newMatrix[i][j] %= 1000;
				}
			}

			for (int i = 0; i < matrixLen; i++) {
				free(copyMatrix[i]);
			}
			free(copyMatrix);
		}

		if (exp >= 4) {
			for (int i = 0; i < matrixLen; i++) {
				free(half[i]);
			}
			free(half);
		}

		return newMatrix;
	}
}


int main(void) {
	long long int exp;
	scanf("%d %lld", &matrixLen, &exp);

	int** matrix = (int**)malloc(sizeof(int*) * matrixLen);
	for (int i = 0; i < matrixLen; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * matrixLen);
		for (int j = 0; j < matrixLen; j++) {
			scanf("%d", &matrix[i][j]);
			matrix[i][j] %= 1000;
		}
	}

	int** resultMatrix = matrixExp(matrix, exp);

	for (int i = 0; i < matrixLen; i++) {
		for (int j = 0; j < matrixLen; j++) {
			printf("%d ", resultMatrix[i][j]);
		}
		free(resultMatrix[i]);
		printf("\n");
	}
	free(resultMatrix);


	return 0;
}