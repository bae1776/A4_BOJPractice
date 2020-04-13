//https://www.acmicpc.net/problem/2805

//상근이에게 나무 M미터가 필요하다.
//나무의 갯수와, 각 나무의 높이가 주어질 때, 상근이는 특정 높이에서만 잘라 그 윗부분을 가져갈 것이다.
//이때, M미터 이상을 가져가기 위해서 설정할 수 있는 최대 높이를 구하시오.

//풀이 : upper_bound를 쓰자

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