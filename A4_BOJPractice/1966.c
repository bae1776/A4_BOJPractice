//https://www.acmicpc.net/problem/1966

//�����ʹ� ���� �μ��ϰ��� �ϴ� ������ �μ� ����� ���� ������� ó���ϴµ�,
//����̴� ������ �߿䵵 ��Ҹ� ���� ���� ���ο� ������ ����Ʈ��� ������� �Ѵ�.
//�� ����Ʈ�����..
//1. ���� Queue�� ���� �տ� �ִ� ������ �߿䵵�� Ȯ���ϰ�
//2. ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ������ʰ� Queue�� ���� �ڿ� ���ġ�Ѵ�.
// �׷��� �ʴٸ� �μ��Ѵ�.

//������ ����(~100), �������� �ϴ� ������ ��ġ, �� ������ �߿䵵(0~9)�� �־�����, �������� �ϴ� ������ �� ��°�� ����� �Ǵ��� ���Ͻÿ�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char isTargeted;
	int priority;
} Document;

void gotoBack(Document* Queue, int* frontptr, int* backptr, int maxsize) {
	Document temp = Queue[(*frontptr)++];
	if (*frontptr == maxsize) *frontptr = 0;
	if (++(*backptr) == maxsize) *backptr = 0;
	Queue[*backptr] = temp;
}

int main(void) {
	
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		int documentCount, targetLoc;
		scanf("%d %d", &documentCount, &targetLoc);
		Document* doc = (Document*)malloc(sizeof(Document) * documentCount);
		for (int j = 0; j < documentCount; j++) {
			scanf("%d", &doc[j].priority);
			if (j == targetLoc) doc[j].isTargeted = 1;
			else doc[j].isTargeted = 0;
		}

		int popOrder = 1;
		int front = 0;
		int back = documentCount - 1;
		while (1) {
			int priorityMax = -1;
			for (int j = front; ;) {
				if (doc[j].priority > priorityMax) priorityMax = doc[j].priority;
				if (j == back) break;
				j++;
				if (j == documentCount) j = 0;
			}

			while (doc[front].priority != priorityMax)
				gotoBack(doc, &front, &back, documentCount);

			Document popTemp = doc[front++];
			if (popTemp.isTargeted == 1) break;
			else popOrder++;
			if (front == documentCount) front = 0;
		}
		printf("%d\n", popOrder);
		
		free(doc);
	}


	return 0;
}