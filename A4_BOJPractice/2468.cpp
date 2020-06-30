//https://www.acmicpc.net/problem/2468

//���� ����
//2���� �迭�� �� ������ ������ ���̰� �־�����.
//����� ���� �Ǹ� Ư�� ���� ������ ���ô� ���� ���� �Ǵµ�,
//���� ����� ���� �κ��� ���� ������ �� �� �ִ�.
//���� �����ϸ� ���� �������� ����, �������� �����ϸ� ���� �������� ���� �ʴ´�. 

//����� ���� �� ���� �� �ִ� ������ �ְ� ������ ���Ͻÿ�.
//(��, ����� ������ �ƹ� ���õ� ���� ����� �ʴ� ��쵵 �ִ�.)


#include <iostream>
#include <string.h>
using namespace std;


int boardLength;
int** board;
bool** visited;

void findSector(int y, int x, int height);



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> boardLength;

	int maxsector = 1;
	int minHeight = 101, maxHeight = 0;
	
	board = new int* [boardLength];
	visited = new bool* [boardLength];
	for (int i = 0; i < boardLength; i++)
	{
		board[i] = new int[boardLength];
		visited[i] = new bool[boardLength];
		
		memset(visited[i], false, sizeof(bool) * boardLength);

		for (int j = 0; j < boardLength; j++)
		{
			cin >> board[i][j];
			if (board[i][j] > maxHeight)
				maxHeight = board[i][j];
			if (board[i][j] < minHeight)
				minHeight = board[i][j];
		}
	}


	for (int height = minHeight; height < maxHeight; height++)
	{
		int sector = 0;
		for (int i = 0; i < boardLength; i++)
			for (int j = 0; j < boardLength; j++)
			{
				if (board[i][j] > height && visited[i][j] == false)
				{
					sector += 1;
					findSector(i, j, height);
				}
			}

		if (sector > maxsector)
			maxsector = sector;

		for (int i = 0; i < boardLength; i++)
			memset(visited[i], false, sizeof(bool) * boardLength);
	}


	cout << maxsector;



	for (int i = 0; i < boardLength; i++)
	{
		delete[] board[i];
		delete[] visited[i];
	}
	delete[] board;
	delete[] visited;


	return 0;
}


void findSector(int y, int x, int height)
{
	visited[y][x] = true;

	if (y != 0 && board[y - 1][x] > height && visited[y - 1][x] == false)
		findSector(y - 1, x, height);

	if (y != boardLength - 1 && board[y + 1][x] > height && visited[y + 1][x] == false)
		findSector(y + 1, x, height);

	if (x != 0 && board[y][x - 1] > height && visited[y][x - 1] == false)
		findSector(y, x - 1, height);

	if (x != boardLength - 1 && board[y][x + 1] > height && visited[y][x + 1] == false)
		findSector(y, x + 1, height);
}