//https://www.acmicpc.net/problem/10816

//최대 50만 개의 숫자 카드가 주어진다.
//그리고 최대 50만 개의 찾을 숫자가 주어진다.
//찾을 숫자를 입력받았을 때, 카드 셋에 그 카드가 몇 장 있는지 출력하시오.

//풀이 : bSearch를 살짝 응용한 upper bound, lower bound가 필요.
//upper bound(t) : t보다 큰 수가 처음으로 존재하는 인덱스
//lower bound(t) : t 이상의 수가 시작되는 인덱스

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* arr;
int arrlen;

int upper_bound(int left, int right, int searchNum) {
	if (left > right) return right + 1;
	int middle = (left + right) / 2;
	if (arr[middle] <= searchNum)
		return upper_bound(middle + 1, right, searchNum);
	else {
		return upper_bound(left, middle - 1, searchNum);
	}
}

int lower_bound(int left, int right, int searchNum) {
	if (left > right) return right + 1;
	int middle = (left + right) / 2;
	if (arr[middle] >= searchNum)
		return lower_bound(left, middle - 1, searchNum);
	else {
		return lower_bound(middle + 1, right, searchNum);
	}
}


int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main(void) {
	scanf("%d", &arrlen);

	arr = (int*)malloc(sizeof(int) * arrlen);
	for (int i = 0; i < arrlen; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, arrlen, sizeof(int), cmp);


	int searchCount;
	scanf("%d", &searchCount);

	int searchNum;
	for (int i = 0; i < searchCount; i++)
	{
		scanf("%d", &searchNum);
		printf("%d ", upper_bound(0, arrlen-1, searchNum) - lower_bound(0, arrlen-1, searchNum));
	}

	free(arr);
	return 0;
}