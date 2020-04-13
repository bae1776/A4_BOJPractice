//https://www.acmicpc.net/problem/11047

//������� ATM 1�⸦ ���� ���Ͽ� ���� ���� �ִ�.
//�� ����� ATM�� ���� �� �ɸ��� �ð��� �־��� ��, �� �ð� ���� ���� ATM�� ���� ���� ������� �ڿ��� ���� ���� ��ٸ� ���̴�.
//������� ATM�� ��ٸ��� ���� ������ �ɸ��� �ð� ������ �ּҸ� ���Ͻÿ�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main(void)
{
	int people;
	scanf("%d", &people);

	int* useTime = (int*)malloc(sizeof(int) * people);
	for (int i = 0; i < people; i++)
	{
		scanf("%d", &useTime[i]);
	}

	qsort(useTime, people, sizeof(int), cmp);

	int timesum = 0;
	for (int i = 0; i < people; i++)
	{
		timesum += (i + 1) * useTime[i];
	}

	printf("%d", timesum);

	free(useTime);

	return 0;
}