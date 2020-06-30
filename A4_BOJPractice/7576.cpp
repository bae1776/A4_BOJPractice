//https://www.acmicpc.net/problem/7576

//토마토 상자
//토마토를 각 칸에 한 개씩 담을 수 있는 격자가 M*N을 이루는 상자가 있다.
//하루가 지날 때마다, 익은 토마토들의 인접한 곳(4방향)에 있는 익지 않은 토마토들이 익게 된다.
//상자의 각 칸의 상태 (빈 칸, 익은 토마토, 익지 않은 토마토)가 주어 질때,
//익는데 걸리는 날을 출력하시오.
//모든 토마토가 익을 수 없다면 -1 출력.

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int col, row;
	cin >> col >> row;

	int day = 0;
	int ripen = 0;
	int unripen = 0;
	
	queue<pair<int, int>> ripeTomato_coord; // <row, col>
	vector<vector<short>> tomatoBox(row, vector<short>(col));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cin >> tomatoBox[i][j];
			
			switch (tomatoBox[i][j])
			{
			case 0:
				unripen++;
				break;
			case 1:
				ripen++;
				ripeTomato_coord.emplace(i, j);
				break;
			}
		}
	

	while (unripen != 0 && ripeTomato_coord.empty() == false)
	{
		day++;

		int queueSize = ripeTomato_coord.size();
		for (int i = 0; i < queueSize; i++)
		{
			pair<int, int> ripeTomato = ripeTomato_coord.front();
			ripeTomato_coord.pop();


			if (ripeTomato.first != 0 && tomatoBox[ripeTomato.first - 1][ripeTomato.second] == 0)
			{
				unripen--; ripen++;
				tomatoBox[ripeTomato.first - 1][ripeTomato.second] = 1;
				ripeTomato_coord.emplace(ripeTomato.first - 1, ripeTomato.second);
			}

			if (ripeTomato.first != row - 1 && tomatoBox[ripeTomato.first + 1][ripeTomato.second] == 0)
			{
				unripen--; ripen++;
				tomatoBox[ripeTomato.first + 1][ripeTomato.second] = 1;
				ripeTomato_coord.emplace(ripeTomato.first + 1, ripeTomato.second);
			}

			if (ripeTomato.second != 0 && tomatoBox[ripeTomato.first][ripeTomato.second - 1] == 0)
			{
				unripen--; ripen++;
				tomatoBox[ripeTomato.first][ripeTomato.second - 1] = 1;
				ripeTomato_coord.emplace(ripeTomato.first, ripeTomato.second - 1);
			}

			if (ripeTomato.second != col - 1 && tomatoBox[ripeTomato.first][ripeTomato.second + 1] == 0)
			{
				unripen--; ripen++;
				tomatoBox[ripeTomato.first][ripeTomato.second + 1] = 1;
				ripeTomato_coord.emplace(ripeTomato.first, ripeTomato.second + 1);
			}

		}
	}

	if (unripen == 0)
		cout << day;
	else
		cout << "-1";




	return 0;
}