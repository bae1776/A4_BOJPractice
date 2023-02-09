//https://www.acmicpc.net/problem/22865

/*가장 먼 곳 (Gold 4)

친구 A, B, C로부터의 거리 중 최소가 가장 큰 위치를 구하세요.

Solution : 다익스트라 * 3
(정점이 10만개, 간선이 50만개이므로 시간 제한이 빡빡하다. 우선 순위 큐는 필수)
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3FFFFFFF

int nodeCount, friendNode[3];
list<pair<int, int>> edgeList[100001];

vector<int> dijkstra(int startNode);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> nodeCount;
    cin >> friendNode[0] >> friendNode[1] >> friendNode[2];
	
    int edgeCount;
    cin >> edgeCount;

    while (edgeCount--)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        edgeList[start].emplace_back(end, weight);
        edgeList[end].emplace_back(start, weight);
    }

    vector<int> minDist[3];
    for (int i = 0; i < 3; i++)
        minDist[i] = dijkstra(friendNode[i]);


    int answer = 1;
    for (int i = 1; i <= nodeCount; i++)
    {
        minDist[0][i] = min(min(minDist[0][i], minDist[1][i]), minDist[2][i]);
        if (minDist[0][i] > minDist[0][answer])
            answer = i;
    }

    cout << answer;


    return 0;
}


vector<int> dijkstra(int startNode)
{
    vector<char> visited(nodeCount + 1, false);
    vector<int> minDist(nodeCount + 1, INF);
    minDist[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.emplace(0, startNode);

    while (minHeap.empty() == false)
    {
        auto [dist, nodeNumber] = minHeap.top();
        minHeap.pop();
        if (visited[nodeNumber])
            continue;

        visited[nodeNumber] = true;

        for (const auto& adjEdge : edgeList[nodeNumber]) //end, weight
        {
            if (visited[adjEdge.first] == false && dist + adjEdge.second < minDist[adjEdge.first])
            {
                minDist[adjEdge.first] = dist + adjEdge.second;
                minHeap.emplace(minDist[adjEdge.first], adjEdge.first);
            }
        }
    }

    return minDist;
}