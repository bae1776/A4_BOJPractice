//https://www.acmicpc.net/problem/2981

//주어진 2 ~ 100개의 숫자들에 대하여 나누었을 때 나머지가 모두 같은
//특정 수들을 오름차순으로 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}


int main(void)
{
	int amount;
	scanf("%d", &amount);

	int* arr = (int*)malloc(sizeof(int) * amount);
	for (int i = 0; i < amount; i++)
		scanf("%d", &arr[i]);

	qsort(arr, amount, sizeof(int), cmp);

	int* gapArr = (int*)malloc(sizeof(int) * (amount - 1));
	int gapArrMin = 0x7FFFFFFF;
	int gapArrMinidx = 0;
	for (int i = 0; i < amount - 1; i++)
	{
		gapArr[i] = arr[i] > arr[i + 1] ? arr[i] - arr[i + 1] : arr[i + 1] - arr[i];
		if (gapArrMin > gapArr[i])
		{
			gapArrMin = gapArr[i];
			gapArrMinidx = i;
		}
	}

	int temp = gapArr[0];
	gapArr[0] = gapArr[gapArrMinidx];
	gapArr[gapArrMinidx] = temp;

	int maxCofactor = 1;

	for (int i = gapArr[0]; i >= 2; i--) {
		char flag = 1;
		for (int j = 0; j < amount - 1; j++) {
			if (gapArr[j] % i) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			maxCofactor = i;
			break;
		}
	}

	for (int i = 2; i <= maxCofactor / 2; i++) {
		if (maxCofactor % i == 0) printf("%d ", i);
	}
	printf("%d", maxCofactor);



	return 0;
}