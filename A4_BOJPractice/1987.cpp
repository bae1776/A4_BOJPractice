//https://www.acmicpc.net/problem/1987

//N * M ũ���� ���尡 �ְ� (�ִ� ����, ���� ���� 20ĭ)
//���� ĭ���� ���ĺ� �빮�ڰ� �����ִ�.
//1�� 1�� ĭ���� �����ؼ�, �� ĭ�� �����̴� ��,
//���ݱ��� ������ ���ĺ��� �Ȱ��� ĭ�� ���� �� ����. (ĭ ��� �� ���� ���ĺ��� ��� �޶���Ѵ�)
//�� �� ������ �� �ִ� ĭ�� �ִ븦 ���Ͻÿ�.


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