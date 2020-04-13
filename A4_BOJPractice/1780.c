//https://www.acmicpc.net/problem/1780

//N×N크기의 행렬로 표현되는 종이가 있다.종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다.우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.
//N은 3^k(k : 0 ~ 7)

//1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
//2. 1이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해 1의 과정을 반복한다.
//이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.


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
