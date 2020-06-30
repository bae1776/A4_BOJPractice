//https://www.acmicpc.net/problem/4963

//���� ����

//0�� �ٴ�, 1�� ���� ������ �迭 ������ �־�����.
//����, ����, �밢������ �����Ͽ� �ɾ �� �ִ� ���� ���� ���̶�� ����.

//������ �� ������ ����Ͻÿ�.

#include <map>
#include <utility>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int col, row;
		cin >> col >> row;

		if (col == 0 && row == 0)
			break;

		
		/*012
		  3 4    -> adjList Expression
		  567							*/
		vector<vector<bool>> myMap(row);
		vector<vector<bool>> visited(row);
		map<pair<int, int>, vector<int>> adjList;
		
		for (int i = 0; i < row; i++)
		{
			myMap[i].reserve(col + 1);
			visited[i] = vector<bool>(col, false);
			for (int j = 0; j < col; j++)
			{
				bool input;
				cin >> input;
				myMap[i].emplace_back(input);
			}
		}

		int x[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
		int y[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (myMap[i][j] == true)
				{
					for (int dir = 0; dir < 8; dir++)
					{
						bool isLand = false;
						try {
							isLand = myMap.at(i + y[dir]).at(j + x[dir]);
						}
						catch (out_of_range) {
							continue;
						}

						if (isLand == true)
						{
							adjList[make_pair(i, j)].push_back(dir);
						}
					}
				}
			}
		}

		function<void(int, int)> dfs =
			[&](int row, int col) -> void {
			visited[row][col] = true;

			auto listItr = adjList.find(make_pair(row, col));
			if (listItr != adjList.end())
			{
				for (int dir : listItr->second)
				{
					try {
						if (visited[row + y[dir]][col + x[dir]] == false)
							dfs(row + y[dir], col + x[dir]);
					}
					catch (out_of_range) {
						continue;
					}
				}
			}
		};

		int islands = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (myMap[i][j] == true && visited[i][j] == false)
				{
					islands++;
					dfs(i, j);
				}
			}
		}
		
		cout << islands << '\n';
	
	}

	return 0;
}