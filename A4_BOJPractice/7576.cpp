//https://www.acmicpc.net/problem/7576

//�丶�� ����
//�丶�並 �� ĭ�� �� ���� ���� �� �ִ� ���ڰ� M*N�� �̷�� ���ڰ� �ִ�.
//�Ϸ簡 ���� ������, ���� �丶����� ������ ��(4����)�� �ִ� ���� ���� �丶����� �Ͱ� �ȴ�.
//������ �� ĭ�� ���� (�� ĭ, ���� �丶��, ���� ���� �丶��)�� �־� ����,
//�ʹµ� �ɸ��� ���� ����Ͻÿ�.
//��� �丶�䰡 ���� �� ���ٸ� -1 ���.

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