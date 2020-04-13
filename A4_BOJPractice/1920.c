//https://www.acmicpc.net/problem/1920

//�ִ� 10�� ���� ���� �迭�� �־�����.
//�ִ� 10���������� �ٸ� �������� �־��� ��, �� ������ �����ϸ� 1, �������� ������ 0�� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int cmp(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

int search(int* arr, int left, int right, int input) {
	if (left > right) return 0;
	int middle = (left + right) / 2;

	if (arr[middle] > input) {
		return search(arr, left, middle - 1, input);
	}
	else if (arr[middle] == input) {
		return 1;
	}
	else {
		return search(arr, middle + 1, right, input);
	}
}


int main(void)
{
	int arrlen;
	scanf("%d", &arrlen);

	int* arr = (int*)malloc(sizeof(int) * arrlen);
	for (int i = 0; i < arrlen; i++)
		scanf("%d", &arr[i]);

	qsort(arr, arrlen, sizeof(int), cmp);

	int bfindCount;
	scanf("%d", &bfindCount);

	int input;
	for (int i = 0; i < bfindCount; i++) {
		scanf("%d", &input);
		printf("%d\n", search(arr, 0, arrlen - 1, input));
	}

}
