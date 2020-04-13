//https://www.acmicpc.net/problem/10814

//����� �� �׸��� �� ����� �̸��� ���̰� �־��� ��
//���� ������ ����� �����Ͻÿ�. ���̰� ���� ��� ���� �� ������� ����Ͻÿ�. (stable sort �ʿ�)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list {
	int age;
	char name[101];
} regisList;

void merge(regisList* arr, int arrsize)
{
	int left = 0;
	int right = arrsize / 2;
	regisList* sorted = (regisList*)malloc(sizeof(regisList) * arrsize);
	int cursor = 0;

	while (left != arrsize / 2 && right != arrsize)
	{
		if (arr[left].age <= arr[right].age)
		{
			sorted[cursor].age = arr[left].age;
			strcpy(sorted[cursor].name, arr[left].name);
			left++;
		}
		else {
			sorted[cursor].age = arr[right].age;
			strcpy(sorted[cursor].name, arr[right].name);
			right++;
		}
		cursor++;
	}

	while (left != arrsize / 2)
	{
		sorted[cursor].age = arr[left].age;
		strcpy(sorted[cursor].name, arr[left].name);
		left++; cursor++;
	}

	while (right != arrsize)
	{
		sorted[cursor].age = arr[right].age;
		strcpy(sorted[cursor].name, arr[right].name);
		right++; cursor++;
	}

	memcpy(arr, sorted, sizeof(regisList) * arrsize);
	free(sorted);
}


void mergeSort(regisList* arr, int arrsize)
{
	if (arrsize <= 1) return;
	mergeSort(arr, arrsize / 2);
	mergeSort(arr + arrsize / 2, arrsize - arrsize / 2);
	merge(arr, arrsize);
}

int main(void)
{
	int number;
	scanf("%d", &number);

	regisList* bojList = (regisList*)malloc(sizeof(regisList) * number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d %s", &bojList[i].age, bojList[i].name);
	}

	mergeSort(bojList, number);

	for (int i = 0; i < number; i++)
	{
		printf("%d %s\n", bojList[i].age, bojList[i].name);
	}

	return 0;
}