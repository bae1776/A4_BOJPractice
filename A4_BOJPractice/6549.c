//https://www.acmicpc.net/problem/6549

//막대가 서로서로 붙어있는 히스토그램(막대그래프)가 주어질 때,
//그 도형에서 만들 수 있는 가장 큰 직사각형의 넓이를 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct lListNode {
	int start_idx;
	int height;
	struct lListNode* next;
} Node;

//height DOWN Order
Node* front = NULL, *rear = NULL;
int* rects;

long long int calNode(int now_index) {
	if (now_index == 0) {
		//init
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->start_idx = now_index;
		newNode->height = rects[now_index];
		newNode->next = NULL;
		front = rear = newNode;
	}
	else {
		if (rects[now_index - 1] < rects[now_index])
		{

			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->start_idx = now_index;
			newNode->height = rects[now_index];
			newNode->next = front;
			front = newNode;
		}
		else if (rects[now_index - 1] == rects[now_index])
		{
			//Nothing to do
		}
		else {
			long long int max = 0;
			int lowest_idx = 0;

			if (front != NULL)
			{
				while (front && front->height > rects[now_index])
				{
					int length = now_index - front->start_idx;
					long long scale = (long long)length * (long long)front->height;
					if (scale > max) max = scale;
					lowest_idx = front->start_idx;
					Node* temp = front;
					front = front->next;
					free(temp);
				}

				Node* newNode = (Node*)malloc(sizeof(Node));
				newNode->start_idx = lowest_idx;
				newNode->height = rects[now_index];
				newNode->next = front;
				front = newNode;

			}
			return max;
		}
	}

	return 0;
}


int main(void) {

	int rectCount;
	scanf("%d", &rectCount);

	while (rectCount != 0) {
		long long int maxScale = 0;

		rects = (int*)malloc(sizeof(int) * rectCount);
		for (int i = 0; i < rectCount; i++) {
			scanf("%d", &rects[i]);
			long long int temp = calNode(i);
			if (temp > maxScale) maxScale = temp;
		}

		while (front != NULL) {
			Node* temp = front;
			front = temp->next;
			int length = rectCount - temp->start_idx;
			long long int scale = (long long)temp->height * (long long)length;
			if (scale > maxScale) maxScale = scale;
			free(temp);
		}
		front = rear = NULL;
		printf("%lld\n", maxScale);

		scanf("%d", &rectCount);
	}

	
	return 0;
}