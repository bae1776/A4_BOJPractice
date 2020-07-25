//https://www.acmicpc.net/problem/1162

//도로 짓기
//힙 다익스트라 + DP로
//엣지의 가중치를 0으로 K번 만들 수 있는 그래프에서 최단 거리를 구해보자. 

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int city, road, pave;
vector<vector<pair<int, int>>> road_adjList; //< end , size >
vector<vector<long long>> DP;


void dijkstra_with_pave(int paveCount);



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> city >> road >> pave;

	road_adjList = vector<vector<pair<int, int>>>(road + 1);
	for (int i = 0; i < road; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;

		road_adjList[start].emplace_back(end, time);
		road_adjList[end].emplace_back(start, time);
	}

	DP = vector<vector<long long>>(city + 1, vector<long long>(pave + 1, 0x7FFFFFFFFFFFFFFFll));
	//city, paveCount
	for (int i = 0; i <= pave; i++)
		DP[1][i] = 0;
	

	for (int paved = 0; paved <= pave; paved++)
	{
		dijkstra_with_pave(paved);
	}

	cout << DP[city][pave];
	

	return 0;
}




void dijkstra_with_pave(int paveCount)
{
	vector<char> visited(city + 1, false);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> searchCity_queue;
	//min heap <now_distance, startCity>
	searchCity_queue.emplace(0, 1);

	while (searchCity_queue.empty() == false)
	{
		pair<long long, int> now_city = searchCity_queue.top();
		searchCity_queue.pop();
		long long& now_distance = now_city.first;
		int& start_city = now_city.second;
		if (visited[start_city] == true)
			continue;
		visited[start_city] = true;

		for (pair<int, int>& adjCity : road_adjList[start_city])
		{
			int& road_end = adjCity.first;
			int& road_dist = adjCity.second;

			if (paveCount != 0)
			{
				if (DP[start_city][paveCount - 1] < DP[road_end][paveCount])
					DP[road_end][paveCount] = DP[start_city][paveCount - 1];
			}

			if (now_distance + road_dist < DP[road_end][paveCount])
				DP[road_end][paveCount] = now_distance + road_dist;

			if (visited[road_end] == false)
				searchCity_queue.emplace(DP[road_end][paveCount], road_end);
		}
	}
	


}