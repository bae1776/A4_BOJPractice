//https://www.acmicpc.net/problem/16437

/*양 구출 작전
N개의 섬으로 이루어진 나라에서 2~N번 섬에 있는 양들은 1번 섬으로 가고 싶어한다.
2~N번의 각 섬에는 양 또는 늑대가 있는데 늑대 1마리는 그 섬을 지나가려는 양 1마리를 잡아먹는다.
모든 섬에서 1번 섬으로 가는 경로가 존재하고 늑대는 섬에서 움직이지 않는다.
각 섬의 양, 늑대 여부, 서식 마리 수가 주어질 때
1번 섬에 도달할 수 있는 양의 수를 구하세요.
*/

#include <vector>
#include <iostream>
using namespace std;

struct Island {
	long long animals;
	vector<int> adjList;
};

vector<Island> islandList;
long long dfs(int islandNumber);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int islandCount;
	cin >> islandCount;

	islandList = vector<Island>(islandCount + 1);
	islandList[1].animals = 0;

	for (int num = 2; num <= islandCount; num++)
	{
		char animalWhat;
		long long count;
		int to;
		cin >> animalWhat >> count >> to;

		if (animalWhat == 'W')
			count = -count;

		islandList[num].animals = count;
		islandList[to].adjList.emplace_back(num);
	}

	cout << dfs(1);

	return 0;
}


long long dfs(int islandNumber)
{	
	long long& nowSheeps = islandList[islandNumber].animals;

	for (const int& adjIslandNumber : islandList[islandNumber].adjList)
		nowSheeps += dfs(adjIslandNumber);

	if (nowSheeps < 0)
		return 0;
	else
		return nowSheeps;
}