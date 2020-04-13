//https://www.acmicpc.net/problem/9663

//�ڿ��� N�� �־��� ��, N*N ü���ǿ��� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ͻÿ�.
//���� �ѹ��� 4���� �Ǵ� �밢�� �������� ���� ĭ �̵� �����ϴ�. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int boardStack[16];
int top = 0;
int size;
int result = 0;


char isValid(int want_pos)
{
	for (int i = 0; i < top; i++)
	{
		if (boardStack[i] == want_pos) return 0;
		if (boardStack[i] + top - i == want_pos) return 0;
		if (boardStack[i] - top + i == want_pos) return 0;
	}

	return 1;
}


void findNQueen(int size, int depth)
{
	if (size == depth)
	{
		top--;
		result++;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (isValid(i))
		{
			boardStack[top++] = i;
			findNQueen(size, depth + 1);
		}
	}

	top--;
}




int main(void)
{
	scanf("%d", &size);

	findNQueen(size, 0);

	printf("%d", result);

	return 0;
}


//typedef struct queen {
//	int x;
//	int y;
//} Queen;
//
//typedef struct chessStack {
//	char chessBoard[MAXSIZE][MAXSIZE];
//	Queen befQueenLoc;
//} ChessStack;
//
//ChessStack queenStack[15];
//int top = 0;
//int size;
//int result = 0;
//
//
//
//
//void findNQueen(int size, int depth)
//{
//	if (depth == size)
//	{
//		top--;
//		result++;
//		return;
//	}
//
//
//	ChessStack popTemp = queenStack[top-1];
//
//	for (int i = popTemp.befQueenLoc.y; i < size; i++) {
//		for (int j = (i == popTemp.befQueenLoc.y) ? popTemp.befQueenLoc.x : 0; j < size; j++) {
//			if (popTemp.chessBoard[i][j] == 0) {
//				ChessStack pushTemp = popTemp;
//				pushTemp.chessBoard[i][j] = 1;
//				pushTemp.befQueenLoc.y = i;
//				pushTemp.befQueenLoc.x = j;
//
//				//���ο� ���� ����ǿ� ǥ���ϱ�.
//				for (int k = 0; k < size; k++)
//				{
//					pushTemp.chessBoard[i][k] = 1;
//					pushTemp.chessBoard[k][j] = 1;
//					if (i - k >= 0) {
//						if (j - k >= 0) pushTemp.chessBoard[i - k][j - k] = 1;
//						if (j + k < size) pushTemp.chessBoard[i - k][j + k] = 1;
//					}
//					if (i + k < size) {
//						if (j - k >= 0) pushTemp.chessBoard[i + k][j - k] = 1;
//						if (j + k < size) pushTemp.chessBoard[i + k][j + k] = 1;
//					}
//				}
//
//				queenStack[top++] = pushTemp;
//				findNQueen(size, depth + 1);
//			}
//		}
//	}
//
//	top--;
//}
//
//
//int main(void)
//{
//	scanf("%d", &size);
//
//
//	ChessStack initStack;
//	for (int i = 0; i < MAXSIZE; i++)
//		for (int j = 0; j < MAXSIZE; j++)
//			initStack.chessBoard[i][j] = 0;
//	initStack.befQueenLoc.x = 0;
//	initStack.befQueenLoc.y = 0;
//	queenStack[top++] = initStack;
//
//	findNQueen(size, 0);
//
//	printf("%d", result);
//

// ����� Ǯ���ε� �ð� �ʰ� ����
//}