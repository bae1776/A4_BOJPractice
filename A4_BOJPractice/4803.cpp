//https://www.acmicpc.net/problem/4803

/*트리

그래프는 정점과 간선으로 이루어져 있다. 두 정점 사이에 경로가 있다면, 두 정점은 연결되어 있다고 한다. 
연결 요소는 모든 정점이 서로 연결되어 있는 정점의 부분집합이다. 그래프는 하나 또는 그 이상의 연결 요소로 이루어져 있다.

트리는 사이클이 없는 연결 요소이다. 트리에는 여러 성질이 있다. 
예를 들어, 트리는 정점이 n개, 간선이 n-1개 있다. 또, 임의의 두 정점에 대해서 경로가 유일하다.

그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 작성하시오.

(노드는 최대 500개, 간선은 중복되지 않는 최대한으로 주어질 수 있다.)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<bool>> adjList;
int vertex, edge;

bool isTree(int root);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    
    for (int tc = 1; ; ++tc)
    {
        cin >> vertex >> edge;
        if (vertex == 0 && edge == 0)
            break;
        
        visited = vector<bool>(vertex + 1, false);
        adjList = vector<vector<bool>>(vertex + 1, vector<bool>(vertex + 1, false));

        for (int i = 0; i < edge; i++)
        {
            int start, end;
            cin >> start >> end;
            adjList[start][end] = true;
            adjList[end][start] = true;
        }

        int treeCount = 0;
        for (int nodeNumber = 1; nodeNumber <= vertex; nodeNumber++)
        {
            if (visited[nodeNumber] == false)
                treeCount += isTree(nodeNumber);
        }

        cout << "Case " << tc << ": ";
        switch (treeCount)
        {
            case 0:
                cout << "No trees.\n";
                break;
            
            case 1:
                cout << "There is one tree.\n";
                break;
            
            default:
                cout << "A forest of " << treeCount << " trees.\n";
        }
    }

    return 0;
}


bool isTree(int root)
{
    bool hasCycle = false;

    queue<pair<int, int>> bfsQueue; //parent, now
    visited[root] = true;
    bfsQueue.emplace(-1, root);

    while (bfsQueue.empty() == false)
    {
        const auto& nowNode = bfsQueue.front();

        for (int edgeEnd = 1; edgeEnd <= vertex; edgeEnd++)
            if (adjList[nowNode.second][edgeEnd] == false || edgeEnd == nowNode.first)
                continue;
            else {
                if (visited[edgeEnd] == true)
                    hasCycle = true;
                else {
                    visited[edgeEnd] = true;
                    bfsQueue.emplace(nowNode.second, edgeEnd);
                }
            }
        
        bfsQueue.pop();
    }

    return !hasCycle;
}