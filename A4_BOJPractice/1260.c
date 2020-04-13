//https://www.acmicpc.net/problem/1260


//그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
//단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
//정점 번호는 1~N 까지이다.

//매 줄 간선이 주어 질탠데, 항상 양방향이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _node {
	int* adjList;
	int adjListMax;
	int adjListnowSize;
} Node;


typedef struct lList {
	int val;
	struct lList* next;
} linkedList;


int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}



void addAdjList(Node* target, int value) 
{
	if (target->adjListnowSize == target->adjListMax)
	{
		int* newadjList = (int*)malloc(sizeof(int) * target->adjListMax * 4);
		for (int i = 0; i < target->adjListnowSize; i++)
			newadjList[i] = target->adjList[i];

		free(target->adjList);
		target->adjList = newadjList;
		target->adjListMax *= 4;
	}

	target->adjList[target->adjListnowSize++] = value;
}



int main(void)
{
	int node, edge, start_pos;
	scanf("%d %d %d", &node, &edge, &start_pos);

	Node* allNodes = (Node*)malloc(sizeof(Node) * node);
	for (int i = 0; i < node; i++) 
	{
		allNodes[i].adjListMax = 20;
		allNodes[i].adjList = (int*)malloc(sizeof(int) * 20);
		allNodes[i].adjListnowSize = 0;
	}


	for (int i = 0; i < edge; i++)
	{
		int tip1, tip2;
		scanf("%d %d", &tip1, &tip2);

		addAdjList(&allNodes[tip1 - 1], tip2);
		addAdjList(&allNodes[tip2 - 1], tip1);
	}

	for (int i = 0; i < node; i++)
	{
		qsort(allNodes[i].adjList, allNodes[i].adjListnowSize, sizeof(int), cmp);
	}

	//DFS
	bool DFSend = false;
	bool* isVisited = (bool*)calloc(node, sizeof(bool));
	linkedList* stack = (linkedList*)malloc(sizeof(linkedList));
	stack->val = start_pos;
	stack->next = NULL;
	int now_pos;

	while (1)
	{
		while (1)
		{
			if (stack == NULL)
			{
				DFSend = true;
				break;
			}
			int pop = stack->val;
			linkedList* temp = stack;
			stack = stack->next;
			free(temp);
			if (isVisited[pop - 1] == true) continue;
			else {
				now_pos = pop; break;
			}
		}
		if (DFSend == true) break;

		printf("%d ", now_pos);
		isVisited[now_pos - 1] = true;

		int* temp = allNodes[now_pos - 1].adjList;
		int adjListCursor = allNodes[now_pos - 1].adjListnowSize;

		while (adjListCursor > 0) {
			adjListCursor--;
			if (isVisited[temp[adjListCursor] - 1] == false)
			{
				linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
				newNode->val = temp[adjListCursor];
				newNode->next = stack;
				stack = newNode;
			}
		}

	}

	while (stack != NULL)
	{
		linkedList* temp = stack;
		stack = stack->next;
		free(temp);
	}
	printf("\n");
	free(isVisited);

	//BFS
	bool BFSend = false;
	isVisited = (bool*)calloc(node, sizeof(bool));
	linkedList* queue = (linkedList*)malloc(sizeof(linkedList));
	queue->val = start_pos;
	queue->next = NULL;
	linkedList* rear = queue;

	while (1)
	{
		while (1)
		{
			if (queue == NULL) {
				BFSend = true;
				break;
			}
			int deq = queue->val;
			linkedList* temp = queue;
			queue = queue->next;
			free(temp);
			if (queue == NULL) rear = NULL;
			if (isVisited[deq - 1] == true) continue;
			else {
				now_pos = deq; break;
			}
		}
		if (BFSend == true) break;

		printf("%d ", now_pos);
		isVisited[now_pos - 1] = true;

		Node* temp = &allNodes[now_pos - 1];

		for (int i = 0; i < temp->adjListnowSize; i++)
		{
			if (isVisited[temp->adjList[i] - 1] == false)
			{
				linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
				newNode->val = temp->adjList[i];
				newNode->next = NULL;
				if (rear != NULL)
				{
					rear->next = newNode;
				}
				else {
					queue = newNode;
				}

				rear = newNode;
			}
		}
	}

	while (queue != NULL)
	{
		linkedList* temp = stack;
		queue = queue->next;
		free(temp);
	}
	free(isVisited);
	free(allNodes);

	return 0;
}
