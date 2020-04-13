//https://www.acmicpc.net/problem/5430

//선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. 
//AC는 정수 배열에 연산을 하기 위해 만든 언어이다.이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

//함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 
//배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

//함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.
//배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	struct node* right;
	struct node* left;
} Node;

Node* head = NULL;

void createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	if (head == NULL) {
		head = newNode;
		newNode->right = head;
		newNode->left = head;
	}
	else {
		newNode->right = head;
		newNode->left = head->left;
		head->left->right = newNode;
		head->left = newNode;
	}
}

void deleteNode(char dir) {
	
	Node* temp = head;
	head->left->right = head->right;
	head->right->left = head->left;
	
	if (dir == 'R')
		head = head->right;
	else if (dir == 'L')
		head = head->left;
	
	if (temp == head) head = NULL; //노드가 1개 뿐인 경우.
	free(temp);	
}

int main(void) {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		char ftQueue[100001];
		scanf("%s", ftQueue);

		int arrsize;
		scanf("%d\n", &arrsize);

		if (arrsize >= 1) {
			int arrnum;
			scanf("[%d", &arrnum);
			createNode(arrnum);
			for (int j = 1; j < arrsize; j++) {
				scanf(",%d", &arrnum);
				createNode(arrnum);
			}
			char endbracket;
			scanf("%c", &endbracket);
		}
		else {
			char trash[10];
			scanf("%s", trash);
		}

		char errorChecker = 0;
		char dir = 'R';
		int length = strlen(ftQueue);
		for (int j = 0; j < length && arrsize >= 0; j++) {
			switch (ftQueue[j]) {
			case 'R':
				if (dir == 'R') {
					dir = 'L';
					if (head) head = head->left;
				}
				else if (dir == 'L') {
					dir = 'R';
					if (head) head = head->right;
				}
				break;
			case 'D':
				if (arrsize == 0) {
					errorChecker = 1;
					break;
				}
				deleteNode(dir);
				arrsize--;
			}
			if (errorChecker == 1) break;
		}

		//결과 출력
		if (errorChecker == 1) {
			printf("error\n");
		}
		else {
			printf("[");
			if (head != NULL) {
				printf("%d", head->value);
				deleteNode(dir);
				while (head != NULL) {
					printf(",%d", head->value);
					deleteNode(dir);
				}
			}
			printf("]\n");
		}
	}

	
	return 0;
}