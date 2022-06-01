//https://www.acmicpc.net/problem/4386

/*별자리 만들기

도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

1.별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
2. 모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.

별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.
별은 최대 100개이며, 각 별의 좌표는 실수이다.

Note) 보루프카(=Sollin) 알고리즘으로 풀이함. [시간복잡도 : ElogV]
https://gazelle-and-cs.tistory.com/80
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
	int parent;
	int level;
};

vector<Node> nodeList;

void merge(int node1, int node2);
int find(int node);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int starCount;
    cin >> starCount;

    vector<pair<double, double>> starCoord(starCount);
    vector<vector<double>> edgeList(starCount, vector<double>(starCount, 0.0));
    nodeList = vector<Node>(starCount);

    for (auto& starElem : starCoord)
        cin >> starElem.first >> starElem.second;

    for (int starA = 0; starA < starCount; starA++)
    {
        nodeList[starA].parent = starA;
        nodeList[starA].level = 1;

        for (int starB = 0; starB < starA; starB++)
        {
            edgeList[starA][starB] = edgeList[starB][starA]
                = sqrt(pow(starCoord[starA].first - starCoord[starB].first, 2.0) + 
                       pow(starCoord[starA].second - starCoord[starB].second, 2.0));
        }
    }

        
    int treeCount = starCount;
    double totalDistance = 0.0;

    while (treeCount != 1) 
    {
        vector<pair<int, int>> minEdge(starCount, {-1, -1});

        for (int start = 0; start < starCount; start++)
        {
            for (int end = 0; end < starCount; end++)
            {
                int setA = find(start);
                int setB = find(end);

                if (setA == setB) continue;

                if (minEdge[setA].second == -1 || edgeList[start][end] < edgeList[minEdge[setA].first][minEdge[setA].second])
                    minEdge[setA] = {start, end};
            }
        }
        
        for (int i = 0; i < starCount; i++)
        {
            if (minEdge[i].first != -1)
            {
                int setA = find(i);
                int setB = find(minEdge[i].second);

                if (setA == setB) continue;

                totalDistance += edgeList[minEdge[i].first][minEdge[i].second];
                merge(i, minEdge[i].second);
                treeCount--;
            }
        }
    }

    cout << totalDistance;
    
	

	return 0;
}




void merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);


    if (nodeList[node1].level < nodeList[node2].level)
    {
        int temp = node1;
        node1 = node2;
        node2 = temp;
    }

    nodeList[node2].parent = node1;

    if (nodeList[node1].level == nodeList[node2].level)
        ++nodeList[node1].level;

}


int find(int node)
{
    if (node == nodeList[node].parent)
        return node;
    else
        return nodeList[node].parent = find(nodeList[node].parent);
}
