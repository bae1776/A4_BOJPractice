//https://www.acmicpc.net/problem/2667

//NxN으로 이루어진 지도가 있다.
//1은 집이 있는 곳, 0은 집이 없는 곳이다.

//집들이 서로 상하좌우로 인접하는(변으로 맞닿은) 모여있는 구역을 단지라고 하자.
//지도를 단지 단위로 묶었을때, 생기는 단지 갯수와 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하시오.


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
