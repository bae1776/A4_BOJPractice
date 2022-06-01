//https://www.acmicpc.net/problem/15681

/* 트리와 쿼리

무방향성 가중치 없는 트리에 루트 노드가 주어질 때, 아래의 쿼리에 답하시오.
- 정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.

트리의 노드 개수는 최대 10만개이고, 쿼리의 개수도 최대 10만개임을 고려하여 풀이하시오.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int subCount;
    vector<int> adjList;
};

vector<Node> adjNodeList;

int dfs(int nowNode, int parent);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nodeCount, rootNode, query;
    cin >> nodeCount >> rootNode >> query;

    adjNodeList = vector<Node>(nodeCount + 1);

    for (int i = 0; i < nodeCount - 1; i++)
    {
        int start, end;
        cin >> start >> end;

        adjNodeList[start].adjList.emplace_back(end);
        adjNodeList[end].adjList.emplace_back(start);
    }

    dfs(rootNode, -1);
    

    while (query--)
    {
        int input;
        cin >> input;

        cout << adjNodeList[input].subCount << '\n';
    }

    return 0;
}





int dfs(int nowNode, int parent)
{
    adjNodeList[nowNode].subCount = 1;

    for (int adjNode : adjNodeList[nowNode].adjList)
    {
        if (adjNode != parent)
            adjNodeList[nowNode].subCount += dfs(adjNode, nowNode);
    }

    return adjNodeList[nowNode].subCount;
}