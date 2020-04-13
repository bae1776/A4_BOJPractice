//https://www.acmicpc.net/problem/11724

//정점과 간선이 주어질 때, 생기는 연결요소의 갯수를 구하시오. (서로 분리 된 그래프의 갯수)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** adjList;
bool* isVisited;


//recursion DFS
void DFS(int start_pos)
{
	isVisited[start_pos] = true;
	
	int* nowAdjList = adjList[start_pos];

	for (int i = 1; i <= (adjList[start_pos][0] & 0xFFFF); i++)
	{
		if (isVisited[adjList[start_pos][i]] == false)
			DFS(adjList[start_pos][i]);
	}
}


void add(int start, int end)
{
	int* vector = adjList[start];
	if ((vector[0] >> 16) == (vector[0] & 0xFFFF)) //최대 갯수 == 현재 갯수
	{
		int updateSize = (vector[0] >> 16) * 4;
		int* newList = (int*)malloc(sizeof(int) * (updateSize + 1));
		newList[0] = (updateSize << 16) + (updateSize / 4);

		for (int i = 1; i <= updateSize / 4; i++) {
			newList[i] = vector[i];
		}

		free(vector);
		vector = adjList[start] = newList;
	}

	vector[(vector[0]++ & 0xFFFF) + 1] = end;

}

int main(void)
{
	int vertexCount, edgeCount;
	scanf("%d %d", &vertexCount, &edgeCount);

	adjList = (int**)malloc(sizeof(int*) * (vertexCount + 1));
	for (int i = 1; i <= vertexCount; i++)
	{
		adjList[i] = (int*)malloc(sizeof(int) * 9);
		adjList[i][0] = (8 << 16) + 0; // 최대 갯수 << 현재 갯수
	}


	for (int i = 1; i <= edgeCount; i++)
	{
		int leftEnd, rightEnd;
		scanf("%d %d", &leftEnd, &rightEnd);

		add(leftEnd, rightEnd);
		add(rightEnd, leftEnd);
	}

	int conComponent = 0;
	isVisited = (bool*)calloc(vertexCount + 1, sizeof(bool));

	for (int i = 1; i <= vertexCount; i++)
	{
		if (isVisited[i] == false) {
			DFS(i);
			conComponent++;
		}
	}

	printf("%d", conComponent);

	for (int i = 1; i <= vertexCount; i++)
		free(adjList[i]);
	free(adjList);
	free(isVisited);

	return 0;
}