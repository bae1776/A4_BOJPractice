//https://www.acmicpc.net/problem/11051

//N, K가 주어질 때 nCk % 10007을 구하시오
//n은 1000 이하의 자연수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void rcDiv(int* arr, int arrlen, int div) {
	char flag = 0;
	for (int i = 0; i < arrlen; i++) {
		if (arr[i] % div == 0) {
			arr[i] /= div;
			flag = 1;
			break;
		}
	}

	if (flag) return;
	else {
		for (int i = 2; i <= div; i++) {
			if (div % i == 0) {
				rcDiv(arr, arrlen, i);
				rcDiv(arr, arrlen, div / i);
				return;
			}
		}
	}

	
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	
	int* mulArr = (int*)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++) {
		mulArr[i] = n - i;
	}

	for (int i = k; i >= 2; i--) {
		rcDiv(mulArr, k, i);
	}

	int sum = 1;
	for (int i = 0; i < k; i++) {
		sum *= mulArr[i];
		if (sum >= 10007) sum %= 10007;
	}

	printf("%d", sum);
}