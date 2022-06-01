//https://www.acmicpc.net/problem/12100

/* 2048 (Easy)  인데 골드2냐?

블럭을 밀어합쳐 2048을 만드는 게임에서
블럭판 상태가 주어질 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하시오.
(이동할 때 새로 생기는 블럭은 없다고 가정한다.)

보드는 정사각이며 최대 크기는 20x20이다.
블럭에 쓰여있는 수는 모두 2 이상 1024 이하의 2의 제곱꼴이다.
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
	//보드의 숫자 위치를 적절하게 뒤집으면 
	//왼쪽으로 미는 작업을 수행하는 함수만으로도 해당 방향으로 민 것과 같은 결과를 내게 할 수 있다.
	const int curBoardSize = currentBoard.size();

	vector<vector<int>> leftSlidedBoard(currentBoard);	//그대로

	vector<vector<int>> rightSlidedBoard(currentBoard);	//세로축 뒤집기
	for (auto& boardRow : rightSlidedBoard)
	{
		for (int i = 0; i < curBoardSize / 2; i++)
			swap(boardRow[i], boardRow[curBoardSize - 1 - i]);
	}

	vector<vector<int>> upSlidedBoard(currentBoard);		//좌로 45도 기울어진 사선을 축으로 뒤집기
	for (int index1 = 0; index1 < curBoardSize; index1++)
		for (int index2 = index1 + 1; index2 < curBoardSize; index2++)
			swap(upSlidedBoard[index1][index2], upSlidedBoard[index2][index1]);

	vector<vector<int>> downSlidedBoard(currentBoard);	//우로 45도 기울어진 사선을 축으로 뒤집기
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

	//뒤집은거 원상복귀
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
		//마지막으로 합쳐진 블록의 블록 행/열 상 인덱스를 저장한다. (이미 합쳐진 블록은 또 합쳐져서는 안된다.)
		//예를 들어 블록 행이 2 2 4 이고 왼쪽으로 밀었을 때,
		//4 0 4 상태가 되었을 때 위 값에 0을 넣는다.
		//이후 4 4 0 그리고 다시 밀기를 시전할 때 위 값이 0임을 보고 더 이상 합치지 않게 한다. 

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
