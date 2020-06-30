//https://www.acmicpc.net/problem/2583

//���� ���ϱ�

//������ ���� ���ݿ� ���߾� k���� ���簢���� �׸��� �̵� K���� ���簢���� ���θ�
//������ ������ �κ��� �� ���� �и��� �������� ����������.

//���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������ ����ϰ�
//�׸��� �� �и��� ������ ���̸� ������������ ����Ͻÿ�.

#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct _rect {
	pair<int, int> LeftBottom;   //X, Y ��
	pair<int, int> RightTop;
} Rect;


bool** board;
bool** visited;
int row, col;


int searchBoard(int y, int x);


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int rectCount;
	cin >> row >> col >> rectCount;

	board = new bool*[row];
	visited = new bool* [row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new bool[col];
		visited[i] = new bool[col];
		memset(board[i], 0, sizeof(bool) * col);
		memset(visited[i], 0, sizeof(bool) * col);

	}


	Rect* rectList = new Rect[rectCount];

	for (int i = 0; i < rectCount; i++)
	{
		Rect& target = rectList[i];
		cin >> target.LeftBottom.first >> target.LeftBottom.second;
		cin >> target.RightTop.first >> target.RightTop.second;

		for (int y = target.LeftBottom.second; y < target.RightTop.second; y++)
		{
			for (int x = target.LeftBottom.first; x < target.RightTop.first; x++)
			{
				board[y][x] = 1;
			}
		}
	}


	int sector = 0;
	vector<int> sectorScale;

	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if (board[y][x] == 0 && visited[y][x] == 0)
			{
				sector++;
				int scale = searchBoard(y, x);
				sectorScale.push_back(scale);
			}
		}
	}

	sort(sectorScale.begin(), sectorScale.end());


	cout << sector << '\n';
	for (auto i = sectorScale.begin(); i != sectorScale.end(); i++)
	{
		cout << *i << ' ';
	}

	

	delete[] rectList;
	for (int i = 0; i < row; i++)
	{
		delete[] board[i];
		delete[] visited[i];
	}
	delete[] board;
	delete[] visited;

	return 0;
}



int searchBoard(int y, int x)
{
	visited[y][x] = true;
	int scale = 1;

	if (y != 0 && board[y - 1][x] == 0 && visited[y - 1][x] == false)
		scale += searchBoard(y - 1, x);

	if (y != row - 1 && board[y + 1][x] == 0 && visited[y + 1][x] == false)
		scale += searchBoard(y + 1, x);

	if (x != 0 && board[y][x - 1] == 0 && visited[y][x-1] == false)
		scale += searchBoard(y, x - 1);

	if (x != col - 1 && board[y][x + 1] == 0 && visited[y][x + 1] == false)
		scale += searchBoard(y, x + 1);

	return scale;
}
