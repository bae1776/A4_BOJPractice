//https://www.acmicpc.net/problem/2217

//����
//�ִ� 10������ �� ������ ��ƿ �� �ִ� �߷��� �־��� ��, �ִ�� �� �� �ִ� ������ ���Ը� ���Ͻÿ�.
//N�� ������ ����ؼ� K ������ ������ ��� �� �������� K/N�� ������ �־�����.


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