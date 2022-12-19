//https://www.acmicpc.net/problem/1219

/*오민식의 고민 (Gold 1)
오민식은 세일즈맨으로 최대한의 이윤을 남기고 싶어한다.
N개의 도시(최대 50개)가 있고, 한 도시에서 다른 도시로 가는 M개의 단방향 교통수단 M개(최대 50개)를 알고 있다.

오민식은 각 도시를 방문할 때마다 돈을 벌며, 교통 수단을 이용할 때마다 비용이 든다.
출발 도시, 도착 도시가 주어질 때 (0 ~ N-1로 매겨짐)
가질 수 있는 돈의 최대 액수를 구하시오.
도착 도시에 불가능한 경우 gg, 도착 시, 돈을 무한히 가질 수 있다면 Gee를 출력하시오.

Solution : 벨만-포드
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INFINITY 0x1FFFFFFFFFFFFFFF

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cityCount, startCity, endCity, transportCount;
    cin >> cityCount >> startCity >> endCity >> transportCount;
    vector<vector<pair<int, int>>> cityTransportList(cityCount);

    while (transportCount--)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        cityTransportList[start].emplace_back(end, cost);
    }

    vector<int> cityEarnings(cityCount);
    for (int cityNumber = 0; cityNumber < cityCount; cityNumber++)
        cin >> cityEarnings[cityNumber];

    for (auto& oneCityTransports : cityTransportList)
        for (auto& singleTransport : oneCityTransports)
        {
            singleTransport.second -= cityEarnings[singleTransport.first];
        }

    //Bellman-ford
    vector<long long> minCost(cityCount, INFINITY);
    minCost[startCity] = -cityEarnings[startCity];
    for (int i = 0; i < cityCount; i++)
    {
        for (int cityNumber = 0; cityNumber < cityCount; cityNumber++)
        {
            if (minCost[cityNumber] == INFINITY)
                continue;

            for (const auto& transport : cityTransportList[cityNumber])
                minCost[transport.first] = min(minCost[transport.first], minCost[cityNumber] + transport.second);
        }
    }

    vector<int> negativeCycleCity;
    
    for (int cityNumber = 0; cityNumber < cityCount; cityNumber++)
    {
        if (minCost[cityNumber] == INFINITY)
            continue;

        for (const auto& transport : cityTransportList[cityNumber])
            if (minCost[transport.first] > minCost[cityNumber] + transport.second)
            {
                negativeCycleCity.push_back(transport.first);
            }
    }

    //사이클에 포함된 정점에서 도착 도시까지 도달할 수 있는가 BFS 체크
    bool hasInfinityEarnings = false;
    for (int start : negativeCycleCity)
    {
        if (hasInfinityEarnings) break;
        vector<char> visited(cityCount, false);
        queue<int> bfsQueue;
        visited[start] = true;
        bfsQueue.push(start);

        while (bfsQueue.empty() == false)
        {
            int nowIndex = bfsQueue.front();
            for (const auto& availableTransport : cityTransportList[nowIndex])
            {
                if (availableTransport.first == endCity)
                {
                    hasInfinityEarnings = true;
                    break;
                } else if (visited[availableTransport.first] == false) {
                    visited[availableTransport.first] = true;
                    bfsQueue.push(availableTransport.first);
                }
            }

            if (hasInfinityEarnings) break;
            bfsQueue.pop();   
        }
    }
    

    if (minCost[endCity] == INFINITY)
        cout << "gg";
    else if (hasInfinityEarnings)
        cout << "Gee";
    else
        cout << -minCost[endCity];

    

    return 0;
}