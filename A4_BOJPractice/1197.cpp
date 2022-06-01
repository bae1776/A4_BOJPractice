//https://www.acmicpc.net/problem/1197

/*최소 신장 트리


정점 최대 10000개, 간선 최대 10만개의 양방향 정수 가중치 그래프가 주어질 때,
최소 스패닝 트리의 가중치를 구하시오.

Note) 해당 문제는 Prim's Algorithm + MinHeap을 사용하여 풀이함 [ElogV 시간 복잡도]
V가 최대 1만이므로 일반 Prim's (V^2)는 다소 시간이 부족하다. - 일반 Prim's는 밀집 그래프에서 유리
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Node = pair<bool, long long int>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> adjNodeList(vertexCount + 1); //weight, end
    vector<Node> visited(vertexCount + 1, make_pair(false, 0x7FFFFFFFFFll));

    for (int i = 0; i < edgeCount; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        adjNodeList[start].emplace_back(weight, end);
        adjNodeList[end].emplace_back(weight, start);

    }

    long long totalWeight = 0;
    int edgeWeight, nodeNumber;
    MinHeap<pair<int, int>> nodeMinHeap; //edgeWeight, nodeNumber;
    nodeMinHeap.emplace(0, 1);
    visited[1].second = 0;

    while (nodeMinHeap.empty() == false)
    {
        auto [edgeWeight, nodeNumber] = nodeMinHeap.top();
        nodeMinHeap.pop();

        if (visited[nodeNumber].first == true)
            continue;

        visited[nodeNumber].first = true;
        totalWeight += edgeWeight;

        for (const auto& [weight, end] : adjNodeList[nodeNumber])
        {
            if (visited[end].first == false && weight < visited[end].second)
            { 
                visited[end].second = weight;
                nodeMinHeap.emplace(weight, end);
                
            }
        }
        

    }

    cout << totalWeight;
	
	return 0;
}
