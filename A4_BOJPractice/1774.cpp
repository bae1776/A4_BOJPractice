//https://www.acmicpc.net/problem/1774

/*우주신과의 교감
4386 문제에서 이미 이어진 경로가 주어진 문제.

Note) Kruskal Algorithm으로 풀이 [시간복잡도 : ElogV]

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;
template <typename T>
using MinEdgeHeap = priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T, int, int>>>;
using lint = long long;

struct Node {
	int parent;
	int level;
};

vector<Node> nodeList;

bool merge(int node1, int node2);
int find(int node);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int godCount, connected;
    cin >> godCount >> connected;

    nodeList = vector<Node>(godCount);
    vector<pair<lint, lint>> godCoordList(godCount);
    for (auto& [x, y] : godCoordList)
        cin >> x >> y;

    MinEdgeHeap<lint> edgePQ;

    for (int start = 0; start < godCount; start++)
    {
        nodeList[start].level = 1;
        nodeList[start].parent = start;

        for (int end = start + 1; end < godCount; end++)
            edgePQ.emplace(
                pow(godCoordList[start].first - godCoordList[end].first, 2) +
                pow(godCoordList[start].second - godCoordList[end].second, 2)
                , start, end);
    }

    int mergeCount = 0;

    for (int i = 0; i < connected; i++)
    {
        int start, end;
        cin >> start >> end;

        mergeCount += merge(start - 1, end - 1);
    }


    long double totalDistance = 0.0;

    while (mergeCount < godCount - 1)
    {
        auto [weight, start, end] = edgePQ.top();
        edgePQ.pop();

        if (!merge(start, end))
            continue;
        
        totalDistance += sqrt(weight);
        mergeCount++;
    }

    cout << fixed;
    cout.precision(2);
    cout << totalDistance;
	

	return 0;
}




bool merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2)
        return false;

    if (nodeList[node1].level < nodeList[node2].level)
    {
        int temp = node1;
        node1 = node2;
        node2 = temp;
    }

    nodeList[node2].parent = node1;

    if (nodeList[node1].level == nodeList[node2].level)
        ++nodeList[node1].level;

    return true;
}


int find(int node)
{
    if (node == nodeList[node].parent)
        return node;
    else
        return nodeList[node].parent = find(nodeList[node].parent);
}
