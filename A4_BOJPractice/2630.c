//https://www.acmicpc.net/problem/2630

//�����̰� �Ķ����� ��� ĭ���� �̷���� ���� �� �����̸� ���� �����θ� �̷��� ������ 4���� 1����� ���簢������ �ڸ����� �Ѵ�.
//�������� �� �ٿ� ���� �� �ִ� ���� ĭ ���� 2^N (N<=7)�̴�.

//���� �����θ� �̷���� �ִ� �����̰� ������ ������ �Ͼ��\n�Ķ��� ������ ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define BLUE 1

char** board;
int white = 0;
int blue = 0;

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
		if (firstBlock == WHITE) {
			white++;
		}
		else //(firstBlock == BLUE) 
			blue++;
		return;
	}
	else {
		lookAndCut(start_x, start_y, lookSize / 2);
		lookAndCut(start_x + lookSize / 2, start_y, lookSize / 2);
		lookAndCut(start_x, start_y + lookSize / 2, lookSize / 2);
		lookAndCut(start_x+lookSize / 2, start_y+lookSize / 2, lookSize / 2);
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

	printf("%d\n%d", white, blue);

	return 0;

	
}

