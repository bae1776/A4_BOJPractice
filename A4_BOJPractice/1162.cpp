//https://www.acmicpc.net/problem/1162

//µµ·Î Áþ±â

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

	for (int paved = 0; paved <= pave; paved++)
	{
		dijkstra_with_pave(paved);
	}
	

	return 0;
}




void dijkstra_with_pave(int paveCount)
{
	vector<char> visited(city + 1, false);

	priority_queue<int, vector<int>, greater<int>> searchCity_queue;
	//min heap
	searchCity_queue.push(1);

	while (searchCity_queue.empty() == false)
	{
		int city_number = searchCity_queue.top();
		searchCity_queue.pop();

		for (auto itr = road_adjList[city_number].begin();
			itr != road_adjList[city_number].end());
	}
	


}