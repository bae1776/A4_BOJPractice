//https://www.acmicpc.net/problem/11004

//최대 5백만개의 배열을 오름차순 정렬하고 K번째 수를 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int left, int right);
void merge(int left, int right);

long long* arr, *copyArr;

int main(void)
{
	int arrlen, K;
	scanf("%d %d", &arrlen, &K);

	arr = (long long*)malloc(sizeof(long long) * arrlen);
	copyArr = (long long*)malloc(sizeof(long long) * arrlen);
	for (int i = 0; i < arrlen; i++)
	{
		scanf("%lld", &copyArr[i]);
	}

	mergeSort(0, arrlen - 1);

	printf("%lld", arr[K - 1]);

	free(arr);
	free(copyArr);
	return 0;
}



void mergeSort(int left, int right)
{
	if (left >= right) return;
	int middle = (left + right) / 2;

	mergeSort(left, middle);
	mergeSort(middle + 1, right);
	merge(left, right);
	
}



void merge(int left, int right)
{
	int middle = (left + right) / 2;

	int lidx = left;
	int ridx = middle + 1;
	int idx = left;
	while (lidx <= middle && ridx <= right)
	{
		if (copyArr[lidx] < copyArr[ridx])
			arr[idx++] = copyArr[lidx++];
		else
			arr[idx++] = copyArr[ridx++];
	}

	if (lidx > middle) {
		while (ridx <= right)
			arr[idx++] = copyArr[ridx++];
	}
	else /*ridx > right*/ {
		while (lidx <= middle)
			arr[idx++] = copyArr[lidx++];
	}

	for (int i = left; i <= right; i++)
		copyArr[i] = arr[i];
}
