//https://www.acmicpc.net/problem/5430

//�����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������. 
//AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�.�� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.

//�Լ� R�� �迭�� �ִ� ������ ������ ������ �Լ��̰�, D�� ù ��° ���ڸ� ������ �Լ��̴�. 
//�迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.

//�Լ��� �����ؼ� �� ���� ����� �� �ִ�. ���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���ڸ� ������ �Լ��̴�.
//�迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
	
	if (temp == head) head = NULL; //��尡 1�� ���� ���.
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

		//��� ���
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