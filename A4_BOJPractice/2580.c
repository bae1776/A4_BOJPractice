//https://www.acmicpc.net/problem/2580

//몇 곳이 0으로 비어 있는 스도쿠판이 주어질 때 스도쿠를 풀어주는 프로그램을 작성하시오.
//가능한 답이 여러 개이면 그 중 하나만 출력하면 되고, 답이 없는 입력은 주어지지 않는다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct block
{
	int x_pos;
	int y_pos;
	int number;
} Block;

Block blockStack[90];
int top = -1;
int puzzle[9][9];
int zeroCount = 0;

char isValid(int guess, int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		if (puzzle[row][i] == guess) return 0;
		if (puzzle[i][col] == guess) return 0;
	}

	int bigBlock_x = col / 3 * 3;
	int bigBlock_y = row / 3 * 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (puzzle[bigBlock_y + i][bigBlock_x + j] == guess) return 0;

	return 1;
}

void solvePuzzle()
{
	if (zeroCount == top) return;

	Block popBlock = blockStack[top];

	for (int i = popBlock.y_pos; i < 9; i++)
	{
		int guess = 0;
		for (int j = 0; j < 9; j++)
		{
			if (puzzle[i][j] == 0)
			{
				for (guess = 1; guess <= 9; guess++)
					if (isValid(guess, i, j))
					{
						puzzle[i][j] = guess;
						Block pushBlock = { j, i, guess };
						blockStack[++top] = pushBlock;
						
						solvePuzzle();
						if (zeroCount == top) return;
						top--;
						puzzle[pushBlock.y_pos][pushBlock.x_pos] = 0;
					}
				break;
			}
		}
		if (guess == 10) break;
		
	}
}



int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &puzzle[i][j]);
			if (puzzle[i][j] == 0) zeroCount++;
		}
	}

	Block initBlock = { 0, 0, 0 };
	blockStack[++top] = initBlock;
	solvePuzzle();


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", puzzle[i][j]);
		printf("\n");
	}


	return 0;
}


/*
Testinput

고난도 스도쿠
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

일반 난도 스도쿠
5 4 0 0 2 0 8 0 6
0 1 9 0 0 7 0 0 3
0 0 0 3 0 0 2 1 0
9 0 0 4 0 5 0 2 0
0 0 1 0 0 0 6 0 4
6 0 4 0 3 2 0 8 0
0 6 0 0 0 0 1 9 0
4 0 2 0 0 9 0 0 5
0 9 0 0 7 0 4 0 2

*/