//https://www.acmicpc.net/problem/1149

//첫째 줄에 집 갯수가 주어진다.
//각각의 집은 R, G, B 중 한 색으로 집을 칠하려고 한다.
//그런데 이웃한 집끼리는 같은 색으로 칠하지 않기로 했다.
//각각의 집에서 R, G, B로 칠할 때의 비용이 주어질 때, 최소 비용을 구하시오. 

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