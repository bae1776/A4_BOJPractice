//https://www.acmicpc.net/problem/1149

//ù° �ٿ� �� ������ �־�����.
//������ ���� R, G, B �� �� ������ ���� ĥ�Ϸ��� �Ѵ�.
//�׷��� �̿��� �������� ���� ������ ĥ���� �ʱ�� �ߴ�.
//������ ������ R, G, B�� ĥ�� ���� ����� �־��� ��, �ּ� ����� ���Ͻÿ�. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int house;
	scanf("%d", &house);

	int(*paintCost)[3] = (int(*)[3])malloc(sizeof(int[3]) * house);
	
	for (int i = 0; i < house; i++)
	{
		scanf("%d %d %d", &paintCost[i][0], &paintCost[i][1], &paintCost[i][2]);
	}

	int lapCost[3] = { paintCost[0][0], paintCost[0][1], paintCost[0][2] };

	for (int i = 1; i < house; i++)
	{
		int tempCost[3];
		tempCost[0] = (lapCost[1] < lapCost[2] ? lapCost[1] : lapCost[2]) + paintCost[i][0];
		tempCost[1] = (lapCost[0] < lapCost[2] ? lapCost[0] : lapCost[2]) + paintCost[i][1];
		tempCost[2] = (lapCost[0] < lapCost[1] ? lapCost[0] : lapCost[1]) + paintCost[i][2];
		lapCost[0] = tempCost[0];
		lapCost[1] = tempCost[1];
		lapCost[2] = tempCost[2];
	}


	int min = lapCost[0];
	for (int i = 1; i < 3; i++)
	{
		if (lapCost[i] < min) min = lapCost[i];
	}

	printf("%d", min);
	free(paintCost);

	return 0;
}