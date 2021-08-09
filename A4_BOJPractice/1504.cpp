//https://www.acmicpc.net/problem/1504

/*특정한 최단 경로

무방향성 양수 가중치 그래프가 주어진다. (정점 최대 800, 간선 최대 20만개)
1번에서 N번 정점으로 이동할 때 주어진 두 정점은 반드시 거치는 최단 경로를 구하여라.
(한번 방문한 정점, 간선은 다시 이용할 수 있다.)

*/


#include <iostream>
#include <vector>
#define INF 0x7FFFFFFFu
using namespace std;
using Node = vector<pair<short, int>>;

int vertex, edge, mid1, mid2;
vector<Node> graph;

vector<unsigned int> dijkstra(int startPos);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> vertex >> edge;

    graph = vector<Node>(vertex + 1);

    for (int i = 0; i < edge; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        graph[start].emplace_back(weight, end);
        graph[end].emplace_back(weight, start);
    }
    
    cin >> mid1 >> mid2;

    auto fromStart = dijkstra(1);
    auto fromMid = dijkstra(mid1);
    auto fromEnd = dijkstra(vertex);

    unsigned int result = INF;

    if (fromStart[mid1] != INF && fromMid[mid2] != INF && fromEnd[mid2] != INF)
        result = min(fromStart[mid1] + fromMid[mid2] + fromEnd[mid2], result);

    if (fromStart[mid2] != INF && fromMid[mid2] != INF && fromEnd[mid1] != INF)
        result = min(fromStart[mid2] + fromMid[mid2] + fromEnd[mid1], result);

    if (result == INF)
        cout << "-1";
    else
        cout << result;

    return 0;
}



vector<unsigned int> dijkstra(int startPos)
{
    vector<unsigned int> minDistance(vertex + 1, INF);
    vector<bool> visited(vertex + 1, false);

    int nowPos = startPos;
    visited[nowPos] = true;
    minDistance[nowPos] = 0;

    while (nowPos != 0)
    {
        visited[nowPos] = true;

        for (const auto& edge : graph[nowPos])
            minDistance[edge.second] = min(minDistance[edge.second], minDistance[nowPos] + edge.first);

        nowPos = 0;
        for (int i = 1; i <= vertex; i++)
            if (minDistance[i] < minDistance[nowPos] && visited[i] == false)
                nowPos = i;
    }

    return minDistance;
}