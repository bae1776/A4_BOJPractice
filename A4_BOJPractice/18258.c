//https://www.acmicpc.net/problem/18258

//큐를 구현해보자.
//이때, 모든 명령의 시간복잡도는 O(1)이어야 한다.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
	int data;
	struct queue* next;
} Queue;

Queue* front = NULL, *rear = NULL;
int size = 0;

//F->...->R

int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	char* command[6] = { "push", "pop", "size", "empty", "front", "back" };

	for (int i = 0; i < testcase; i++)
	{
		char input[10];
		scanf("%s", input);

		if (!strcmp(command[0], input)) {
			int tempData;
			scanf("%d", &tempData);
			Queue* newQueue = (Queue*)malloc(sizeof(Queue));
			newQueue->data = tempData;
			newQueue->next = NULL;
			size++;
			if (front == NULL) {
				front = rear = newQueue;
			}
			else {
				rear->next = newQueue;
				rear = newQueue;
			}
		}
		else if (!strcmp(command[1], input)) {
			if (front == NULL) {
				printf("-1\n");
			}
			else if (front == rear) {
				printf("%d\n", front->data);
				free(front);
				size--;
				front = rear = NULL;
			}
			else {
				printf("%d\n", front->data);
				Queue* temp = front;
				front = front->next;
				free(temp);
				size--;
			}
		}
		else if (!strcmp(command[2], input)) {
			printf("%d\n", size);
		}
		else if (!strcmp(command[3], input)) {
			if (size == 0) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(command[4], input)) {
			if (size == 0) printf("-1\n");
			else {
				printf("%d\n", front->data);
			}
		}
		else if (!strcmp(command[5], input)) {
			if (size == 0) printf("-1\n");
			else {
				printf("%d\n", rear->data);
			}
		}
	}


	return 0;
}