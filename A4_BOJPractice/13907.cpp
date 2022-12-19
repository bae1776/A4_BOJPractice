//https://www.acmicpc.net/problem/13907

/*세금 (Platinum 4)

주언이는 두 도시를 오가며 장사를 한다.
각 도시는 양 방향 도로로 연결되어 있고, 도로마다 통행료를 징수한다.
그런데, 정부는 세금 인상안을 발표하면서, 각 도로 통행료를 일괄적으로 조금씩 여러번 증가시킬 예정이다.

주언이를 위해 초기 통행료와 세금이 오를 때마다의 최소 통행료를 구해주자.
(도시 최대 1000, 도로 최대 30000, 세금 인상 횟수 최대 30000회
시작 통행료 1000, 세금 인상액 1~10)

*/

#include <iostream>
#include <list>
#include <queue>
#include <tuple>
using namespace std;

#define INF 0x3FFFFFFF
using pair3 = tuple<int, int, int>;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cityCount, roadCount, taxRiseCount;
	int startCity, endCity;

	cin >> cityCount >> roadCount >> taxRiseCount;
	cin >> startCity >> endCity;

	vector<pair<int, int>> costList[1020];
	vector<vector<int>> minCost(cityCount + 1, vector<int>(cityCount + 1, INF));
	vector<int> taxRise(taxRiseCount + 1);

	while (roadCount--)
	{
		int start, end, roadCost;
		cin >> start >> end >> roadCost;

		costList[start].emplace_back(end, roadCost);
		costList[end].emplace_back(start, roadCost);
	}

	for (int i = 1; i <= taxRiseCount; i++)
		cin >> taxRise[i];


	//DijkStra
	priority_queue<pair3, vector<pair3>, greater<pair3>> dijkstraPQ;
	dijkstraPQ.emplace(0, 0, startCity);
	minCost[startCity][0] = 0;

	while (dijkstraPQ.empty() == false)
	{
		int cost, count, cityNumber;
		tie(cost, count, cityNumber) = dijkstraPQ.top();
		dijkstraPQ.pop();

		if (count == cityCount) continue;
		if (cost > minCost[cityNumber][count]) continue;

		for (const auto& road : costList[cityNumber])
			if (minCost[road.first][count + 1] > cost + road.second)
			{	
				minCost[road.first][count + 1] = cost + road.second;
				dijkstraPQ.emplace(minCost[road.first][count + 1], count + 1, road.first);
			}
		
	}


	list<pair<int, int>> endCityCostList;
	for (int count = 1; count <= cityCount; ++count)
	{
		if (minCost[endCity][count] != INF)
			endCityCostList.emplace_back(count, minCost[endCity][count]);
	}


	for (int i = 0; i <= taxRiseCount; i++)
	{
		int value = INF;
		for (auto it = endCityCostList.begin(); it != endCityCostList.end();)
		{
			it->second += it->first * taxRise[i];

			if (value > it->second)
			{
				value = min(value, it->second);
				++it;
			} else
				it = endCityCostList.erase(it);
		}

		cout << value << '\n';
	}



	return 0;
}