//https://www.acmicpc.net/problem/2239

//스도쿠
//스도쿠 문제가 주어질 때, 이를 푸시오.
//답이 여러 개이면, 스도쿠의 81자리를 숫자로 바꾸었을 때 가장 작은 답만 출력하시오.

//재귀 안쓰려다가 코드 망함 ㅠㅠ..
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

char board[10][10];
stack<pair<int, int>> emptyBlocks;
stack<pair<int, int>> fillBlocks;


inline bool promising(const pair<int, int>& loc);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
		cin >> board[i];

	for (int i = 8; i >= 0; i--)
		for (int j = 8; j >= 0; j--)
		{
			if (board[i][j] == '0')
				emptyBlocks.emplace(i, j);
		}


	while (!emptyBlocks.empty())
	{
		pair<int, int> now_loc = emptyBlocks.top();
		emptyBlocks.pop();
		
		char& emptyBlock = board[now_loc.first][now_loc.second];
		emptyBlock = '0' - emptyBlock + '1';


		if (promising(now_loc))
		{	//Go next empty Block
			fillBlocks.push(now_loc);
			continue;
		}
		else {
			//Backtracking
			emptyBlocks.push(now_loc);

			
			if (emptyBlock == '9')
			{
				emptyBlock = '0';
				pair<int, int> prev_loc = fillBlocks.top();
				fillBlocks.pop();

				//repeated Backtracking
				while (board[prev_loc.first][prev_loc.second] == '9')
				{
					board[prev_loc.first][prev_loc.second] = '0';
					emptyBlocks.push(prev_loc);
					prev_loc = fillBlocks.top();
					fillBlocks.pop();
				}

				board[prev_loc.first][prev_loc.second] 
					= '0' - (board[prev_loc.first][prev_loc.second] - '0');
				emptyBlocks.push(prev_loc);
			}
			emptyBlock = '0' - (emptyBlock - '0');
		}
	}


	for (int row = 0; row < 9; row++)
	{
		cout << board[row] << '\n';
	}


	return 0;
}



inline bool promising(const pair<int, int>& loc)
{
	//1. row
	bool visited[10] = { false };

	for (int col = 0; col < 9; col++)
	{
		const char& target = board[loc.first][col] - '0';
		if (target == 0) continue;
		if (visited[target] == true)
			return false;
		else
			visited[target] = true;
	}

	//2. col
	fill(visited, visited + 10, false);
	for (int row = 0; row < 9; row++)
	{
		const char& target = board[row][loc.second] - '0';
		if (target == 0) continue;
		if (visited[target] == true)
			return false;
		else
			visited[target] = true;
	}

	//3. 3x3 board
	fill(visited, visited + 10, false);
	int startrow = loc.first / 3 * 3;
	int startcol = loc.second / 3 * 3;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
		{
			const char& target = board[startrow + row][startcol + col] - '0';
			if (target == 0) continue;
			if (visited[target] == true)
				return false;
			else
				visited[target] = true;
		}

	return true;
}
