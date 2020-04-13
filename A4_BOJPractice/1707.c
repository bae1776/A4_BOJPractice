//https://www.acmicpc.net/problem/1707

//그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 
//분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

//그래프가 입력으로 주어졌을 때, 
//이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED -1
#define BLUE 1

typedef struct _Llist {
	int value;
	struct _Llist* next;
} LinkedList;

typedef struct _vertex {
	char vertexColor;
	LinkedList* adjList;
} Vertex;

bool* isVisited;

void add(Vertex* target, int value)
{
	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
	newList->value = value;
	newList->next = target->adjList;
	target->adjList = newList;
}


bool isBipartite_BFS(Vertex* Graph, int vertexCount, int start_pos)
{
	
	int now_pos = start_pos;
	Graph[now_pos].vertexColor = BLUE;
	LinkedList* front = NULL, *rear = NULL;

	while (1)
	{
		isVisited[now_pos] = true;

		LinkedList* temp = Graph[now_pos].adjList;

		while (temp != NULL)
		{
			if (isVisited[temp->value] == false)
			{
				LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
				newList->value = temp->value;
				newList->next = NULL;

				if (front == NULL)
					front = rear = newList;
				else {
					newList->next = front;
					front = newList;
				}
			}


			if (Graph[temp->value].vertexColor == 0) {
				if (Graph[now_pos].vertexColor == BLUE)
					Graph[temp->value].vertexColor = RED;
				else
					Graph[temp->value].vertexColor = BLUE;
			}
			else {
				if (Graph[now_pos].vertexColor == Graph[temp->value].vertexColor)
				{
					while (front != NULL)
					{
						LinkedList* first = front;
						front = front->next;
						free(first);
					}
					return false;
				}
			}
			temp = temp->next;
		}

		while (1)
		{
			if (front == NULL)
			{
				return true;
			}
			LinkedList* first = front;
			front = front->next;
			if (isVisited[first->value] == true)
			{
				free(first);
				continue;
			}
			else {
				now_pos = first->value;
				free(first);
				break;
			}
		}

	}
	

}



int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int vertexCount, edgeCount;
		scanf("%d %d", &vertexCount, &edgeCount);

		Vertex* allVertex = (Vertex*)malloc(sizeof(Vertex) * (vertexCount + 1));

		for (int j = 1; j <= vertexCount; j++)
		{
			allVertex[j].vertexColor = 0;
			allVertex[j].adjList = NULL;
		}

		for (int j = 0; j < edgeCount; j++)
		{
			int leftEnd, rightEnd;
			scanf("%d %d", &leftEnd, &rightEnd);

			add(&allVertex[leftEnd], rightEnd);
			add(&allVertex[rightEnd], leftEnd);
		} 

		bool validity = true;
		isVisited = (bool*)calloc(vertexCount + 1, sizeof(bool));

		for (int j = 1; j <= vertexCount; j++)
		{
			if (isVisited[j] == false)
			{
				if (isBipartite_BFS(allVertex, vertexCount, j) == false)
				{
					validity = false;
					break;
				}
			}
		}
		printf("%s\n", validity ? "YES" : "NO");

		free(isVisited);
		free(allVertex);
	}
	
	return 0;
}