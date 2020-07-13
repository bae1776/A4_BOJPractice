//https://www.acmicpc.net/problem/2146

//다리 만들기

//육지와 바다가 있는 지도가 주어진다.
//서로 떨어져 있는 육지를 이을 수 있게 다리를 지을 때,
//지을 수 있는 가장 짧은 다리의 길이를 구하시오.

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define OCEAN 0
#define LAND 1

class Bridge {
public:
	int from;
	int distance;

	Bridge(int from = 0, int distance = 0) {
		this->from = from;
		this->distance = distance;
	};
};

int mapSize;

int separateIsland(vector<vector<Bridge>>& dotMap);
int getshortestBridge(vector<vector<Bridge>>& dotMap);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> mapSize;

	vector<vector<Bridge>> dotMap(mapSize, vector<Bridge>(mapSize));

	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++)
			cin >> dotMap[i][j].from;
	
	//separate distinct island
	int islandCount = separateIsland(dotMap);
	int result = getshortestBridge(dotMap);

	
	cout << result;

	return 0;
}



int separateIsland(vector<vector<Bridge>>& dotMap)
{
	int islandNumber = 2;

	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++)
		{
			if (dotMap[i][j].from != LAND) 
				continue;

			queue<pair<int, int>> mapCoord_BFS;
			mapCoord_BFS.emplace(i, j);
			dotMap[i][j] = islandNumber;

			while (!mapCoord_BFS.empty())
			{
				pair<int, int> now_pos = mapCoord_BFS.front();
				mapCoord_BFS.pop();


				if (now_pos.first != 0 && dotMap[now_pos.first - 1][now_pos.second].from == LAND)
				{
					dotMap[now_pos.first - 1][now_pos.second].from = islandNumber;
					mapCoord_BFS.emplace(now_pos.first - 1, now_pos.second);
				}

				if (now_pos.second != 0 && dotMap[now_pos.first][now_pos.second - 1].from == LAND)
				{
					dotMap[now_pos.first][now_pos.second - 1].from = islandNumber;
					mapCoord_BFS.emplace(now_pos.first, now_pos.second - 1);
				}

				if (now_pos.first != mapSize - 1 && dotMap[now_pos.first + 1][now_pos.second].from == LAND)
				{
					dotMap[now_pos.first + 1][now_pos.second].from = islandNumber;
					mapCoord_BFS.emplace(now_pos.first + 1, now_pos.second);
				}

				if (now_pos.second != mapSize - 1 && dotMap[now_pos.first][now_pos.second + 1].from == LAND)
				{
					dotMap[now_pos.first][now_pos.second + 1].from = islandNumber;
					mapCoord_BFS.emplace(now_pos.first, now_pos.second + 1);
				}
				
			}

			islandNumber++;
		}

	return islandNumber - 2;
}



int getshortestBridge(vector<vector<Bridge>>& dotMap)
{
	int maxDistance = 1;

	while (1)
	{
		int totalDist = 0x7FFFFFFF;
		for (int i = 0; i < mapSize; i++)
			for (int j = 0; j < mapSize; j++)
			{
				if (dotMap[i][j].distance != maxDistance - 1 || dotMap[i][j].from == OCEAN)
					continue;

				if (i != 0)
				{
					if (dotMap[i - 1][j].from == OCEAN)
					{
						dotMap[i - 1][j].from = dotMap[i][j].from;
						dotMap[i - 1][j].distance = dotMap[i][j].distance + 1;
					}
					else if (dotMap[i][j].from != dotMap[i-1][j].from) {
						int distance = dotMap[i][j].distance + dotMap[i - 1][j].distance;
						if (distance < totalDist)
							totalDist = distance;
					}
				}

				if (j != 0)
				{
					if (dotMap[i][j - 1].from == OCEAN)
					{
						dotMap[i][j - 1].from = dotMap[i][j].from;
						dotMap[i][j - 1].distance = dotMap[i][j].distance + 1;
					}
					else if (dotMap[i][j].from != dotMap[i][j - 1].from) {
						int distance = dotMap[i][j].distance + dotMap[i][j - 1].distance;
						if (distance < totalDist)
							totalDist = distance;
					}
				}

				if (i != mapSize - 1)
				{
					if (dotMap[i + 1][j].from == OCEAN)
					{
						dotMap[i + 1][j].from = dotMap[i][j].from;
						dotMap[i + 1][j].distance = dotMap[i][j].distance + 1;
					}
					else  if (dotMap[i][j].from != dotMap[i + 1][j].from) {
						int distance = dotMap[i][j].distance + dotMap[i + 1][j].distance;
						if (distance < totalDist)
							totalDist = distance;
					}
				}

				if (j != mapSize - 1)
				{
					if (dotMap[i][j + 1].from == OCEAN)
					{
						dotMap[i][j + 1].from = dotMap[i][j].from;
						dotMap[i][j + 1].distance = dotMap[i][j].distance + 1;
					}
					else if (dotMap[i][j].from != dotMap[i][j + 1].from) {
						int distance = dotMap[i][j].distance + dotMap[i][j + 1].distance;
						if (distance < totalDist)
							totalDist = distance;
					}
				}
			}
		if (totalDist != 0x7FFFFFFF)
			return totalDist;

		maxDistance++;
	}
	return -1;
}
