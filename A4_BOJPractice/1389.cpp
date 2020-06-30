//https://www.acmicpc.net/problem/1389

//�ɺ� �������� 6�ܰ� ��Ģ

//�� ��Ģ�� ������ ������ ��� ������� ���� �ٸ� �̳��� ���� �ƴ� ������� ����� �� �ִٰ� �Ѵ�.
//����� ��(��� ��)�� ģ�� ������ ��(���� ��),
//�׸��� ģ�� ���� ������/������ �־��� ��(�������)

//�ɺ� ������ ���� ��� ���� ��� ����� �̾��� ������ ��ģ �ٸ� ���� ���� ���´´�.
//���� ��� A, B, C�� �ִµ� B�� A�� ģ���̰�, C�� B�� ģ���� ��
//A�� �ɺ� ������ ���� 1+2=3�� �ȴ�.

//�̶� ��� ����� �� �ɺ� ������ ���� �ּҸ� ���Ͻÿ�.


#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;


int cavinBacon_number(const vector<vector<bool>>& adjMatrix, int start, int user);


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int user, edge;
	cin >> user >> edge;

	vector<vector<bool>> adjMatrix(user, vector<bool>(user, false));

	for (int i = 0; i < edge; i++)
	{
		int start, end;
		cin >> start >> end;

		adjMatrix[start - 1][end - 1] = true;
		adjMatrix[end - 1][start - 1] = true;
	}


	int minNumber = 0x7FFFFFFF, minUser = 0x7FFFFFFF;
	for (int i = 0; i < user; i++)
	{
		int cavin_i = cavinBacon_number(adjMatrix, i, user);
		if (cavin_i < minNumber)
		{
			minNumber = cavin_i;
			minUser = i + 1;
		}
	}
	
	cout << minUser;

	return 0;
}



int cavinBacon_number(const vector<vector<bool>>& adjMatrix, int start, int user)
{
	int result = 0;
	int visitedCount = 0;
	vector<bool> visited(user, false);
	queue<pair<int, int>> BFSQueue;  //vertexNumber, depth

	BFSQueue.emplace(start, 0);


	do {
		pair<int, int> nowElement = BFSQueue.front();
		BFSQueue.pop();

		if (visited[nowElement.first] == true)
			continue;

		visited[nowElement.first] = true;
		visitedCount++;
		result += nowElement.second;


		for (int i = 0; i < user; i++)
		{
			if (adjMatrix[nowElement.first][i] == true && visited[i] == false)
				BFSQueue.emplace(i, nowElement.second + 1);
		}



	} while (visitedCount < user);


	return result;
}
