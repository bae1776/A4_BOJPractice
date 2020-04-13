//https://www.acmicpc.net/problem/1018

//체스판 다시 칠하기
//검은색, 흰색 정사각형이 아무렇게나 그려진 큰 보드에서 
//8x8을 잘라 체스판으로 다시 색칠할 때 색칠할 정사각형 수의 최소를 구하는 문제

#include <stdio.h>
#include <stdlib.h>

char board1[8][8] = {
	"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"
};

int makeChessBoard(char** board, int start_row, int start_col)
{
	int toboard1 = 0;

	//반대로 색칠된 보드의 색칠 횟수는 64-toboard1

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board1[i][j] != board[start_row + i][start_col + j]) toboard1++;
		}
	}

	return toboard1 >= 32 ? 64 - toboard1 : toboard1;
}

int main(void)
{
	int row, col;
	scanf("%d %d", &row, &col);

	char** board = (char**)malloc(sizeof(char*) * row);
	for (int i = 0; i < row; i++)
	{
		board[i] = (char*)malloc(sizeof(char) * (col+1));
		scanf("%s", board[i]);
	}

	
	int result = 64;
	for (int i = 0; i <= row - 8; i++)
	{
		int temp;
		for (int j = 0; j <= col - 8; j++)
			if ((temp = makeChessBoard(board, i, j)) < result) result = temp;
	}

	printf("%d", result);
}