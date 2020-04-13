//https://www.acmicpc.net/problem/1992

//흑백 영상 (흰점 0, 검은 점 1)을 쿼드트리로 압축하시오.
//영상의 크기는 2^N * 2^N  (N 0~6)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct quadTree {
	char color; //2->more depth
	struct quadTree* next[4];
	int depth;
} qTree;

qTree* head;
char** board;

void compress(qTree* root, int x, int y, int depth, int nowsize) {
	int firstBlock = board[y][x];

	int sameChecker = 1;
	for (int i = y; i < y + nowsize; i++) {
		for (int j = x; j < x + nowsize; j++) {
			if (firstBlock != board[i][j]) {
				sameChecker = 0;
				break;
			}
		}
	}

	if (sameChecker == 1) {
		root->color = firstBlock;
		root->depth = depth;
	}
	else /*sameChecker == 0*/{
		root->color = 2;
		root->depth = depth;
		for (int i = 0; i < 4; i++) {
			root->next[i] = (qTree*)malloc(sizeof(qTree));
		}
		compress(root->next[0], x, y, depth + 1, nowsize / 2);
		compress(root->next[1], x+nowsize/2, y, depth + 1, nowsize / 2);
		compress(root->next[2], x, y+nowsize/2, depth + 1, nowsize / 2);
		compress(root->next[3], x+nowsize/2, y+nowsize/2, depth + 1, nowsize / 2);

	}
}

void printQTree(qTree* root) {
	if (root->color == 2) { //more Depth
		printf("(");
		for (int i = 0; i < 4; i++)
			printQTree(root->next[i]);
		printf(")");
	}
	else {
		printf("%d", root->color);
		//free(root);
	}
}

int main(void) {
	int size;
	scanf("%d", &size);

	board = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		board[i] = (char*)malloc(sizeof(char) * size);
		for (int j = 0; j < size; j++) {
			scanf("%1hhd", &board[i][j]);
		}
	}
	

	head = (qTree*)malloc(sizeof(qTree));
	
	compress(head, 0, 0, 0, size);
	printQTree(head);


	return 0;
}
