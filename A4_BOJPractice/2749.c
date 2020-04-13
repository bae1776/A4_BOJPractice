//https://www.acmicpc.net/problem/2749

//N번째 피보나치 수 % 1000000 을 구하시오.
//그런데 N이 1,000,000,000,000,000,000 이하의 자연수이므로.
//O(logN) 알고리즘이 있어야 풀 수 있을 것이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int** matExpon(long long int** matTwo, long long int exp) {
	if (exp <= 1) return matTwo;

	long long int** half = matExpon(matTwo, exp / 2);


	long long int** newMat = (long long int**)malloc(sizeof(long long int*) * 2);
	for (int i = 0; i < 2; i++) {
		newMat[i] = (long long int*)calloc(2, sizeof(long long int));
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				newMat[i][j] += half[i][k] * half[k][j];
			}
			newMat[i][j] %= 1000000;
		}
	}

	if (exp % 2 == 1) {
		long long int** copyMat = (long long int**)malloc(sizeof(long long int*) * 2);
		for (int i = 0; i < 2; i++) {
			copyMat[i] = (long long int*)malloc(sizeof(long long int) * 2);
			for (int j = 0; j < 2; j++) {
				copyMat[i][j] = newMat[i][j];
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				newMat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					newMat[i][j] += copyMat[i][k] * matTwo[k][j];
				}
				newMat[i][j] %= 1000000;
			}
		}


		for (int i = 0; i < 2; i++) {
			free(copyMat[i]);
		}
		free(copyMat);
	}

	if (exp >= 4) {
		for (int i = 0; i < 2; i++) {
			free(half[i]);
		}
		free(half);
	}

	return newMat;
}


int main(void)
{
	long long int input;
	scanf("%lld", &input);
	//[1, 1; 1, 0]^n 으로 구할 수 있다.
	long long int** matTwo = (long long int**)malloc(sizeof(long long int*) * 2);
	for (int i = 0; i < 2; i++) {
		matTwo[i] = (long long int*)malloc(sizeof(long long int) * 2);
		for (int j = 0; j < 2; j++) {
			matTwo[i][j] = 1;
		}
	}
	matTwo[1][1] = 0;

	long long int** result = matExpon(matTwo, input - 1);

	printf("%lld", result[0][0]);
	return 0;
}