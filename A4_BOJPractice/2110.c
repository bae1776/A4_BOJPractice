//https://www.acmicpc.net/problem/2110

//���� �����⸦ ��ġ�Ϸ��ϴµ�, ������ ���� �ִܰŸ��� �ִ밡 �ǵ����Ϸ��� �Ѵ�.
//�� ����, ��ǥ, �������� ������ �־��� �� �� ���� ���Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int isValid(int* coordSet, int coords, int interval, int wifi)
{
	int lptr = 0, rptr = 1;
	wifi--;

	while (rptr < coords) {
		if (coordSet[rptr] - coordSet[lptr] >= interval)
		{
			wifi--;
			lptr = rptr;
			rptr++;
		}
		else rptr++;
	}


	if (wifi <= 0)
		return 1;
	else
		return 0;
}


int main(void)
{
	int house, wifi;
	scanf("%d %d", &house, &wifi);

	int* houseCoord = (int*)malloc(sizeof(int) * house);
	for (int i = 0; i < house; i++)
		scanf("%d", &houseCoord[i]);

	qsort(houseCoord, house, sizeof(int), cmp);

	int maxDist = (houseCoord[house - 1] - houseCoord[0]) / (wifi - 1);
	int minDist = 1;

	while (minDist <= maxDist)
	{
		int middle = (minDist + maxDist) / 2;

		if (isValid(houseCoord, house, middle, wifi))
		{
			minDist = middle + 1;
		}
		else {
			maxDist = middle - 1;
		}

	}


	printf("%d", maxDist); //Answer




	return 0;
}