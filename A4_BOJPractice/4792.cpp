//https://www.acmicpc.net/problem/4792

/*레드 블루 스패닝 트리 (Platinum 3)
무방향, 무가중치, 연결 그래프가 주어진다. 각 간선은 빨간색 또는 파란색으로 색칠되어있고,
자기 자신을 향하는 간선은 없으며 임의 두 정점을 연결하는 간선은 유일하다.

그래프가 주어질 때, 파란색 간선이 정확히 k개인 스패닝 트리를 구성할 수 있으면 1, 없으면 0을 출력하여라.
각 그래프는 정점이 최대 1000개 이다.

Solution : https://everenew.tistory.com/176
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;
using ListVector = vector<list<pair<short, short>>>; //dest, weight

int prim(const ListVector& edgeList);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int node, edge, blue;
    while (true)
    {
        cin >> node >> edge >> blue;
        if (node == 0) break;

        ListVector graphEdgeList(node);

        while (edge--)
        {
            char color; int start, end;
            cin >> color >> start >> end;

            graphEdgeList[start - 1].emplace_back(end - 1, (color == 'B') ? 1 : 0);
            graphEdgeList[end - 1].emplace_back(start - 1, (color == 'B') ? 1 : 0);            
        }

        //Blue 간선에만 가중치를 1 먹여서 최소 Blue 간선 갯수를 구한다.
        int minBlue = prim(graphEdgeList);
        if (minBlue == -1)
        {
            cout << "0\n";
            continue;
        }

        for (auto& nodeEdgeList : graphEdgeList)
            for (auto& edge : nodeEdgeList)
                edge.second = (1 - edge.second);

        //Red 간선에만 가중치를 1 먹여서 최소 Red 간선 갯수를 구한다. (maxBlue = n - 1 - minRed);
        int maxBlue = node - 1 - prim(graphEdgeList);

        if (minBlue <= blue && blue <= maxBlue)
            cout << "1\n";
        else
            cout << "0\n";
    }
}


int prim(const ListVector& edgeList)
{
    vector<char> visited(edgeList.size(), false);
    vector<short> minCost(edgeList.size(), 0x3FFF);

    int nowVisit = 0, weightSum = 0;
    minCost[0] = 0;

    for (int visitedNodeCount = 1; visitedNodeCount <= edgeList.size(); ++visitedNodeCount)
    {
        visited[nowVisit] = true;

        for (const auto& edgefromVisited : edgeList[nowVisit])
            minCost[edgefromVisited.first] = min(minCost[edgefromVisited.first], edgefromVisited.second);
        
        if (visitedNodeCount == edgeList.size())
            break;

        int nextVisit = -1;
        for (int i = 0; i < edgeList.size(); i++)
        {
            if (visited[i] == false && minCost[i] != 0x3FFF)
            {
                if (nextVisit == -1)
                    nextVisit = i;
                else {
                    if (minCost[i] < minCost[nextVisit])
                        nextVisit = i;
                }
            }
        }

        if (nextVisit == -1) return -1;
        else
            weightSum += minCost[nextVisit];

        nowVisit = nextVisit;

    }

    return weightSum;
}