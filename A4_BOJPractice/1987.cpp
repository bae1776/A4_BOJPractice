//https://www.acmicpc.net/problem/1987

//N * M 크기의 보드가 있고 (최대 가로, 세로 각각 20칸)
//보드 칸마다 알파벳 대문자가 쓰여있다.
//1행 1열 칸부터 시작해서, 한 칸씩 움직이는 데,
//지금까지 지나온 알파벳과 똑같은 칸을 밟을 수 없다. (칸 경로 상에 쓰인 알파벳이 모두 달라야한다)
//이 때 움직일 수 있는 칸의 최대를 구하시오.


#include <iostream>
using namespace std;

int row, col, maxDepth;
bool alphabet_visited[26];
char** board;


void find_longestPath(int this_row, int this_col, int depth);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> col;

	board = new char* [row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new char[col + 1];
		cin >> board[i];
	}

	find_longestPath(0, 0, 1);

	cout << maxDepth;

	for (int i = 0; i < row; i++)
		delete[] board[i];
	delete[] board;


	return 0;
}



void find_longestPath(int this_row, int this_col, int depth)
{
	if (depth > maxDepth)
		maxDepth = depth;

	alphabet_visited[board[this_row][this_col] - 'A'] = true;

	//L
	if (this_col > 0 && alphabet_visited[board[this_row][this_col - 1] - 'A'] == false)
		find_longestPath(this_row, this_col - 1, depth + 1);

	//R
	if (this_col < col - 1 && alphabet_visited[board[this_row][this_col + 1] - 'A'] == false)
		find_longestPath(this_row, this_col + 1, depth + 1);

	//U
	if (this_row > 0 && alphabet_visited[board[this_row - 1][this_col] - 'A'] == false)
		find_longestPath(this_row - 1, this_col, depth + 1);

	//D
	if (this_row < row - 1 && alphabet_visited[board[this_row + 1][this_col] - 'A'] == false)
		find_longestPath(this_row + 1, this_col, depth + 1);

	alphabet_visited[board[this_row][this_col] - 'A'] = false;
}