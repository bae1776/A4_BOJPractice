//https://www.acmicpc.net/problem/1780

//N��Nũ���� ��ķ� ǥ���Ǵ� ���̰� �ִ�.������ �� ĭ���� -1, 0, 1�� �� �� �� �ϳ��� ����Ǿ� �ִ�.�츮�� �� ����� ������ ũ��� �ڸ����� �ϴµ�, �̶� ������ ��Ģ�� ���� �ڸ����� �Ѵ�.
//N�� 3^k(k : 0 ~ 7)

//1. ���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���̸� �״�� ����Ѵ�.
//2. 1�� �ƴ� ��쿡�� ���̸� ���� ũ���� 9���� ���̷� �ڸ���, ������ �߸� ���̿� ���� 1�� ������ �ݺ��Ѵ�.
//�̿� ���� ���̸� �߶��� ��, -1�θ� ä���� ������ ����, 0���θ� ä���� ������ ����, 1�θ� ä���� ������ ������ ���س��� ���α׷��� �ۼ��Ͻÿ�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char** board;
int minus = 0;
int zero = 0;
int plus = 0;

void lookAndCut(int start_x, int start_y, int lookSize) {
	char firstBlock = board[start_x][start_y];

	int lookedisSame = 1;
	for (int i = start_y; i < start_y + lookSize; i++) {
		for (int j = start_x; j < start_x + lookSize; j++) {
			if (board[j][i] != firstBlock)
			{
				lookedisSame = 0;
				break;
			}
		}
	}



	if (lookedisSame == 1) {
		if (firstBlock == -1) {
			minus++;
		}
		else if (firstBlock == 0) {
			zero++;
		}
		else //(firstBlock == 1) 
			plus++;
		return;
	}
	else {
		int pieceSize = lookSize / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				lookAndCut(start_x + pieceSize * j, start_y + pieceSize * i, pieceSize);
			}
		}
	}
}


int main(void) {
	int size;
	scanf("%d", &size);

	board = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		board[i] = (char*)malloc(sizeof(char) * size);
		for (int j = 0; j < size; j++) {
			scanf("%hhd", &board[i][j]);
		}
	}

	lookAndCut(0, 0, size);

	printf("%d\n%d\n%d", minus, zero, plus);

	for (int i = 0; i < size; i++) {
		free(board[i]);
	}
	free(board);

	return 0;


}
