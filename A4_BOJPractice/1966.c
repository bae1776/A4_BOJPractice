//https://www.acmicpc.net/problem/1966

//프린터는 보통 인쇄하고자 하는 문서를 인쇄 명령을 받은 순서대로 처리하는데,
//상근이는 문서에 중요도 요소를 집어 넣은 새로운 프린터 소프트웨어를 만드려고 한다.
//이 소프트웨어는..
//1. 먼저 Queue의 가장 앞에 있는 문서의 중요도를 확인하고
//2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서는 인쇄하지않고 Queue의 가장 뒤에 재배치한다.
// 그렇지 않다면 인쇄한다.

//문서의 수와(~100), 뽑으려고 하는 문서의 위치, 각 문서의 중요도(0~9)가 주어질때, 뽑으려고 하는 문서는 몇 번째로 출력이 되는지 구하시오.


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