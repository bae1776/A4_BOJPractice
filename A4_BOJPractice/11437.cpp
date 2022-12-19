//https://www.acmicpc.net/problem/11437

/* LCA (Gold 3)

최대 5만개의 정점으로 이루어진 트리가 주어진다. 각 정점은 1부터 번호가 매겨져 있고 루트는 1이다.
두 노드의 쌍이 최대 10000개 주어질 때, 두 노드의 가장 가까운 공통 조상 번호를 구하시오.

참고 링크 : LCA 알고리즘
https://4legs-study.tistory.com/121

이 문제에선 단순 선형탐색을 이용한 LCA로 풀어도 통과한다. 이때, 시간복잡도는 O(TreeDepth) 이다.
DP+이분탐색을 이용하면 O(log(TreeDepth))로 구할 수 있으며, 이는 11438번 LCA 2 문제에서 쓰인다.
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;
#define NODEMAX 50000

struct Node {
    int parent;
    int number;
    int level;
};

Node nodeList[NODEMAX + 1];
list<int> edgeList[NODEMAX + 1];
queue<pair<int, int>> bfsQueue; //<parent, number>

int LCA(int a, int b);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeCount, pairCount;
    cin >> nodeCount;

    //1. 간선 형성
    for (int i = 0; i < nodeCount - 1; i++)
    {
        int start, end;
        cin >> start >> end;

        edgeList[start].push_back(end);
        edgeList[end].push_back(start);
    }

    //2. BFS로 정점 정보 생성
    int level = 1;
    bfsQueue.emplace(0, 1);

    while (bfsQueue.empty() == false)
    {
        int queueSize = bfsQueue.size();
        while (queueSize--)
        {
            auto& [nodeParent, nodeNumber] = bfsQueue.front();

            nodeList[nodeNumber].parent = nodeParent;
            nodeList[nodeNumber].number = nodeNumber;
            nodeList[nodeNumber].level = level;

            for (const int& edge : edgeList[nodeNumber])
            {
                if (edge != nodeParent)
                    bfsQueue.emplace(nodeNumber, edge);
            }
            
             

            bfsQueue.pop();
        }
        level++;
    }

    //3. 쌍 입력받아 선형으로 LCA
    cin >> pairCount;
    while (pairCount--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        cout << LCA(node1, node2) << '\n';
    }

	return 0;
}

int LCA(int a, int b)
{
    if (nodeList[a].level < nodeList[b].level)
        swap(a, b);

    while (nodeList[a].level != nodeList[b].level)
        a = nodeList[a].parent;

    while (a != b)
    {
        a = nodeList[a].parent;
        b = nodeList[b].parent;
    }

    return a;
}