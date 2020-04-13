//https://www.acmicpc.net/problem/10816

//�ִ� 50�� ���� ���� ī�尡 �־�����.
//�׸��� �ִ� 50�� ���� ã�� ���ڰ� �־�����.
//ã�� ���ڸ� �Է¹޾��� ��, ī�� �¿� �� ī�尡 �� �� �ִ��� ����Ͻÿ�.

//Ǯ�� : bSearch�� ��¦ ������ upper bound, lower bound�� �ʿ�.
//upper bound(t) : t���� ū ���� ó������ �����ϴ� �ε���
//lower bound(t) : t �̻��� ���� ���۵Ǵ� �ε���

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