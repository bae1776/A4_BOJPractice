//https://www.acmicpc.net/problem/2805

//����̿��� ���� M���Ͱ� �ʿ��ϴ�.
//������ ������, �� ������ ���̰� �־��� ��, ����̴� Ư�� ���̿����� �߶� �� ���κ��� ������ ���̴�.
//�̶�, M���� �̻��� �������� ���ؼ� ������ �� �ִ� �ִ� ���̸� ���Ͻÿ�.

//Ǯ�� : upper_bound�� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

int upper_bound(int* arr, int left, int right, int key)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] > key)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return left;
}


int main(void)
{
	int treeCount, needs;
	scanf("%d %d", &treeCount, &needs);

	int* treeHeight = (int*)malloc(sizeof(int) * treeCount);
	for (int i = 0; i < treeCount; i++)
		scanf("%d", &treeHeight[i]);

	qsort(treeHeight, treeCount, sizeof(int), cmp);

	int left = 0, right = treeHeight[treeCount - 1];

	while (left <= right)
	{
		long long int woodSum = 0;
		int middle = (left + right) / 2;

		for (int i = upper_bound(treeHeight, 0, treeCount - 1, middle);
			i < treeCount; i++)
		{
			woodSum += treeHeight[i] - middle;
		}

		if (woodSum >= needs)
			left = middle + 1;
		else
			right = middle - 1;
	}

	printf("%d", right);

	free(treeHeight);

	return 0;
}