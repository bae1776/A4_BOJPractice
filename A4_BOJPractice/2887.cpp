//https://www.acmicpc.net/problem/2887

/*행성 터널

이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있으며, 행성 간을 잇는 터널을 만드려고 한다.
행성은 3차원 좌표 상의 한 점에 위치한다고 하자. 두 행성을 터널로 연결할 때 드는 비용은
min(|x1-x2|, |y1-y2|, |z1-z2|)이다.

민혁이는 터널을 총 N-1개 건설하여 모든 행성이 서로 연결되게 하려고 한다.
이때, 모든 행성을 터널로 연결하는 데 필요한 최소 비용을 구하시오.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
template <typename T>
using MinEdgeHeap = priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T, int, int>>>;
using Planet = tuple<int, int, int, int>;


template <int K>
bool compare(const Planet& pa, const Planet& pb)
{
    return get<K>(pa) < get<K>(pb);
}

struct Node {
        int parent;
        int level;
};


vector<Node> nodeList;
vector<Planet> planet_coordinate;
MinEdgeHeap<int> edgePQ;

template <int K> inline void makeEdge();
bool merge(int node1, int node2);
int find(int node);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int planetCount;
    cin >> planetCount;

    planet_coordinate.reserve(planetCount);

    Planet input;
    for (int i = 0; i < planetCount; i++)
    {
        auto& [number, x, y, z] = input;
        cin >> x >> y >> z;
        planet_coordinate.emplace_back(i, x, y, z);
    }

    //sort By x
    sort(planet_coordinate.begin(), planet_coordinate.end(), compare<1>);
    makeEdge<1>();
    sort(planet_coordinate.begin(), planet_coordinate.end(), compare<2>);
    makeEdge<2>();
    sort(planet_coordinate.begin(), planet_coordinate.end(), compare<3>);
    makeEdge<3>();


    nodeList = vector<Node>(planetCount);

    for (int i = 0; i < planetCount; i++)
    {
        nodeList[i].level = 1;
        nodeList[i].parent = i;
    }

    int totalDistance = 0;
    int treeCount = planetCount;

    while (treeCount != 1)
    {
        auto [weight, start, end] = edgePQ.top();
        edgePQ.pop();

        if (!merge(start, end))
            continue;

        totalDistance += weight;
        treeCount--;
    }

    cout << totalDistance;


    return 0;
}

template <int K>
inline void makeEdge()
{
    auto planetAIter = planet_coordinate.cbegin();

    for (auto planetBIter = planet_coordinate.cbegin() + 1 ; planetBIter != planet_coordinate.cend(); ++planetBIter)
    {
        edgePQ.emplace(get<K>(*planetBIter) - get<K>(*planetAIter), get<0>(*planetAIter), get<0>(*planetBIter));
        planetAIter = planetBIter;
    }
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
