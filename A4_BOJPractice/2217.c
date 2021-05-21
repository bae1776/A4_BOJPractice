//https://www.acmicpc.net/problem/2217

//로프
//최대 10만개의 각 로프가 버틸 수 있는 중량이 주어질 때, 최대로 들 수 있는 물건의 무게를 구하시오.
//N개 로프를 사용해서 K 무게의 물건을 들면 각 로프에는 K/N의 하중이 주어진다.


#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}



int main(void)
{
	int ropeCount;
	scanf("%d", &ropeCount);

	int* ropeList = (int*)malloc(sizeof(int) * ropeCount);
	for (int i = 0; i < ropeCount; i++)
	{
		scanf("%d", &ropeList[i]);
	}

	qsort(ropeList, ropeCount, sizeof(int), compare);


	int maxWeight = -1;
	
	for (int i = 0; i < ropeCount; i++)
	{
		int nowWeight = (ropeCount - i) * ropeList[i];

		if (nowWeight > maxWeight)
			maxWeight = nowWeight;
	}

	printf("%d", maxWeight);

	free(ropeList);
	
	return 0;
}