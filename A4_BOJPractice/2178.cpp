//https://www.acmicpc.net/problem/2178

//N*M �̷ΰ� �ִ�.
//(1, 1)���� ����Ͽ� (N, M)���� �� �� �������ϴ� �ּ� ĭ ����?
//�� �� ���� ���� �־����� �ʴ´�.

#include <iostream>
#include <queue>
using namespace std;

typedef struct _mBlock
{
	int x;
	int y;
	int depth;

	_mBlock(int x, int y, int depth) : x(x), y(y), depth(depth) {};
} mazeBlock;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, col;
	cin >> row >> col;

	char** maze = new char* [row];

	for (int i = 0; i < row; i++)
	{
		maze[i] = new char[col + 1];
		cin >> maze[i];
	}
	


	queue<mazeBlock> mazeQueue;
	mazeQueue.emplace(0, 0, 1);

	while (1)
	{
		mazeBlock nowPos = mazeQueue.front();
		mazeQueue.pop();

		if (nowPos.x == col - 1 && nowPos.y == row - 1)
		{
			cout << nowPos.depth;
			break;
		}


		if (nowPos.x != 0 && maze[nowPos.y][nowPos.x - 1] == '1')
		{
			maze[nowPos.y][nowPos.x - 1] = '0';
			mazeQueue.emplace(nowPos.x - 1, nowPos.y, nowPos.depth + 1);
		}

		if (nowPos.x != col-1 && maze[nowPos.y][nowPos.x + 1] == '1')
		{
			maze[nowPos.y][nowPos.x + 1] = '0';
			mazeQueue.emplace(nowPos.x + 1, nowPos.y, nowPos.depth + 1);
		}

		if (nowPos.y != 0 && maze[nowPos.y - 1][nowPos.x] == '1')
		{
			maze[nowPos.y - 1][nowPos.x] = '0';
			mazeQueue.emplace(nowPos.x, nowPos.y - 1, nowPos.depth + 1);
		}

		if (nowPos.y != row - 1 && maze[nowPos.y + 1][nowPos.x] == '1')
		{
			maze[nowPos.y + 1][nowPos.x] = '0';
			mazeQueue.emplace(nowPos.x, nowPos.y + 1, nowPos.depth + 1);
		}
	}

	for (int i = 0; i < row; i++)
		delete[] maze[i];
	delete[] maze;

	return 0;
}