//https://www.acmicpc.net/problem/12100

/* 2048 (Easy)  �ε� ���2��?

���� �о����� 2048�� ����� ���ӿ���
���� ���°� �־��� ��, �ִ� 5�� �̵��ؼ� ���� �� �ִ� ���� ū ����� ���� ���Ͻÿ�.
(�̵��� �� ���� ����� ���� ���ٰ� �����Ѵ�.)

����� ���簢�̸� �ִ� ũ��� 20x20�̴�.
���� �����ִ� ���� ��� 2 �̻� 1024 ������ 2�� �������̴�.
*/


#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int MAX = 2;

void slideBoard(int slideCount, vector<vector<int>> currentBoard);
void slideLeft(vector<vector<int>>& currentBoard);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int boardSize;
	cin >> boardSize;

	vector<vector<int>> board(boardSize, vector<int>(boardSize));

	for (auto& boardRow : board)
		for (int& blockValue : boardRow)
			cin >> blockValue;

	if (boardSize != 1)
		slideBoard(0, board);
	else
		MAX = board[0][0];

	cout << MAX;
	

	return 0;
}


void slideBoard(int slideCount, vector<vector<int>> currentBoard)
{
	//������ ���� ��ġ�� �����ϰ� �������� 
	//�������� �̴� �۾��� �����ϴ� �Լ������ε� �ش� �������� �� �Ͱ� ���� ����� ���� �� �� �ִ�.
	const int curBoardSize = currentBoard.size();

	vector<vector<int>> leftSlidedBoard(currentBoard);	//�״��

	vector<vector<int>> rightSlidedBoard(currentBoard);	//������ ������
	for (auto& boardRow : rightSlidedBoard)
	{
		for (int i = 0; i < curBoardSize / 2; i++)
			swap(boardRow[i], boardRow[curBoardSize - 1 - i]);
	}

	vector<vector<int>> upSlidedBoard(currentBoard);		//�·� 45�� ������ �缱�� ������ ������
	for (int index1 = 0; index1 < curBoardSize; index1++)
		for (int index2 = index1 + 1; index2 < curBoardSize; index2++)
			swap(upSlidedBoard[index1][index2], upSlidedBoard[index2][index1]);

	vector<vector<int>> downSlidedBoard(currentBoard);	//��� 45�� ������ �缱�� ������ ������
	for (int index1 = 0; index1 < curBoardSize - 1; index1++)
		for (int index2 = 0; index2 < curBoardSize - 1 - index1; index2++)
		{
			int indexAdder = curBoardSize - 1 - index1 - index2;
			swap(downSlidedBoard[index1][index2], downSlidedBoard[index1 + indexAdder][index2 + indexAdder]);
		}

	slideLeft(leftSlidedBoard);
	slideLeft(rightSlidedBoard);
	slideLeft(upSlidedBoard);
	slideLeft(downSlidedBoard);
	slideCount++;

	//�������� ���󺹱�
	for (auto& boardRow : rightSlidedBoard)
	{
		for (int i = 0; i < curBoardSize / 2; i++)
			swap(boardRow[i], boardRow[curBoardSize - 1 - i]);
	}

	for (int index1 = 0; index1 < curBoardSize; index1++)
		for (int index2 = index1 + 1; index2 < curBoardSize; index2++)
			swap(upSlidedBoard[index1][index2], upSlidedBoard[index2][index1]);

	for (int index1 = 0; index1 < curBoardSize - 1; index1++)
		for (int index2 = 0; index2 < curBoardSize - 1 - index1; index2++)
		{
			int indexAdder = curBoardSize - 1 - index1 - index2;
			swap(downSlidedBoard[index1][index2], downSlidedBoard[index1 + indexAdder][index2 + indexAdder]);
		}

	if (slideCount == 5)
	{
		for (int i = 0; i < curBoardSize; i++)
			for (int j = 0; j < curBoardSize; j++)
			{
				MAX = max(MAX, leftSlidedBoard[i][j]);
				MAX = max(MAX, rightSlidedBoard[i][j]);
				MAX = max(MAX, upSlidedBoard[i][j]);
				MAX = max(MAX, downSlidedBoard[i][j]);
			}
	}
	else {
		slideBoard(slideCount, leftSlidedBoard);
		slideBoard(slideCount, rightSlidedBoard);
		slideBoard(slideCount, upSlidedBoard);
		slideBoard(slideCount, downSlidedBoard);
	}

}


void slideLeft(vector<vector<int>>& currentBoard)
{

	for (vector<int>& boardRow : currentBoard)
	{

		int alreadyCombinedIndex = -1;
		//���������� ������ ����� ��� ��/�� �� �ε����� �����Ѵ�. (�̹� ������ ����� �� ���������� �ȵȴ�.)
		//���� ��� ��� ���� 2 2 4 �̰� �������� �о��� ��,
		//4 0 4 ���°� �Ǿ��� �� �� ���� 0�� �ִ´�.
		//���� 4 4 0 �׸��� �ٽ� �б⸦ ������ �� �� ���� 0���� ���� �� �̻� ��ġ�� �ʰ� �Ѵ�. 

		for (int movedBlockIndex = 1; movedBlockIndex < boardRow.size(); movedBlockIndex++)
		{
			if (boardRow[movedBlockIndex] == 0)
				continue;
			else
			{
				int movingBlockIndex = movedBlockIndex;
				while (movingBlockIndex != 0)
				{
					if (boardRow[movingBlockIndex - 1] == 0)
					{
						boardRow[movingBlockIndex - 1] = boardRow[movingBlockIndex];
						boardRow[movingBlockIndex] = 0;
					}
					else if (boardRow[movingBlockIndex - 1] == boardRow[movingBlockIndex] && movingBlockIndex - 1 > alreadyCombinedIndex)
					{
						boardRow[movingBlockIndex - 1] *= 2;
						boardRow[movingBlockIndex] = 0;
						alreadyCombinedIndex = movingBlockIndex - 1;
					}
					else break;
					movingBlockIndex--;
				}
			}

		}

	}
}
