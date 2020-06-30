//https://www.acmicpc.net/problem/1389

//케빈 베이컨의 6단계 법칙

//위 법칙에 따르면 지구에 모든 사람들은 여섯 다리 이내로 서로 아는 사람끼리 연결될 수 있다고 한다.
//사람의 수(노드 수)와 친구 관계의 수(간선 수),
//그리고 친구 관계 시작점/끝점이 주어질 때(양방향임)

//케빈 베이컨 수는 노드 상의 모든 사람과 이어질 때까지 거친 다리 수의 합을 일컫는다.
//예를 들어 A, B, C가 있는데 B는 A의 친구이고, C는 B의 친구일 때
//A의 케빈 베이컨 수는 1+2=3이 된다.

//이때 모든 사람들 중 케빈 베이컨 수의 최소를 구하시오.


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
