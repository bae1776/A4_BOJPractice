//https://www.acmicpc.net/problem/11047

//사람들이 ATM 1기를 쓰기 위하여 줄을 서고 있다.
//각 사람이 ATM을 쓰는 데 걸리는 시간이 주어질 때, 그 시간 동안 아직 ATM을 쓰지 못한 사람들은 뒤에서 줄을 서서 기다릴 것이다.
//사람들이 ATM을 기다리고 쓰는 데까지 걸리는 시간 총합의 최소를 구하시오.


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