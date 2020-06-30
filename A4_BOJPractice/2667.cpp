//https://www.acmicpc.net/problem/2667

//NxN���� �̷���� ������ �ִ�.
//1�� ���� �ִ� ��, 0�� ���� ���� ���̴�.

//������ ���� �����¿�� �����ϴ�(������ �´���) ���ִ� ������ ������� ����.
//������ ���� ������ ��������, ����� ���� ������ �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����Ͻÿ�.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int mapSize;
bool** map;
int** bindMap;
int bindOrder = 0;


int binding(const int& bindNum, int row, int col);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> mapSize;
	map = new bool* [mapSize];
	bindMap = new int* [mapSize];


	for (int i = 0; i < mapSize; i++)
	{
		map[i] = new bool[mapSize];
		bindMap[i] = new int[mapSize];

		for (int j = 0; j < mapSize; j++)
		{
			char ch;
			cin >> ch;
			map[i][j] = ch - '0';

			bindMap[i][j] = 0;
		}
	}

	vector<int> bindsArray;

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
			if (map[i][j] == true && bindMap[i][j] == 0) 
			{
				int bindCount = binding(++bindOrder, i, j);
				bindsArray.push_back(bindCount);
			}
	}

	sort(bindsArray.begin(), bindsArray.end());

	cout << bindsArray.size() << '\n';
	for (int& i : bindsArray)
		cout << i << '\n';

	for (int i = 0; i < mapSize; i++)
	{
		delete[] map[i];
		delete[] bindMap[i];
	}
	delete[] map;
	delete[] bindMap;

	return 0;
}



int binding(const int& bindNum, int row, int col)
{
	int bindCount = 1;
	bindMap[row][col] = bindNum;


	if (row > 0 && map[row-1][col] == 1 && bindMap[row-1][col] == 0)
		bindCount += binding(bindNum, row - 1, col);
	
	if (row < mapSize - 1 && map[row + 1][col] == 1 && bindMap[row + 1][col] == 0)
		bindCount += binding(bindNum, row + 1, col);

	if (col > 0 && map[row][col - 1] == 1 && bindMap[row][col - 1] == 0)
		bindCount += binding(bindNum, row, col - 1);

	if (col < mapSize - 1 && map[row][col + 1] == 1 && bindMap[row][col + 1] == 0)
		bindCount += binding(bindNum, row, col + 1);

	return bindCount;
}
