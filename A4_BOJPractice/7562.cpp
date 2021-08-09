//https://www.acmicpc.net/problem/7562

/*나이트의 이동

대각선 2-1로 움직일 수 있는 나이트가 체스판에서 특정 위치로 이동하려 할 때, 
이동해야할 최소 횟수를 구하시오.
체스판의 크기는 최대 300 * 300 이다.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int boardSize;
		cin >> boardSize;
		
		vector<vector<bool>> board(boardSize, vector<bool>(boardSize, false));
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		queue<tuple<int, int, int>> bfsQueue;
		bfsQueue.emplace(startX, startY, 0);
		board[startX][startY] = true;

		int x, y, move;
		while (true)
		{
			tie(x, y, move) = bfsQueue.front();
			bfsQueue.pop();

			if (x == endX && y == endY)
			{
				cout << move << '\n';
				break;
			}

			const static int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
			const static int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

			for (int i = 0; i < 8; i++)
				if (0 <= x + dx[i] && x + dx[i] < boardSize && 0 <= y + dy[i] && y + dy[i] < boardSize && 
					board[x + dx[i]][y + dy[i]] == false)
				{
					bfsQueue.emplace(x + dx[i], y + dy[i], move + 1);
					board[x + dx[i]][y + dy[i]] = true;
				}
		}
	}

	
	return 0;
}
