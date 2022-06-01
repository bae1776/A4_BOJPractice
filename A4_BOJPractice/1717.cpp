//https://www.acmicpc.net/problem/1717

/*집합의 표현

초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다.
여기에 합집합 연산과 두 원소가 같은 집합에 포함되는지 확인하는 연산을 수행하려고 하는 프로그램을 작성하시오.

n은 최대 100만, 연산은 최대 10만개 이다.

Union find의 기본 문제이다.
https://www.apexcel.blog/algorithm/graph/union-find/union-find/

union Find는 경로 압축까지 제대로 프로그래밍하면 거의 상수시간에 동작한다.
*/

#include <iostream>
#include <vector>
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

    int nodeCount, query;
    cin >> nodeCount >> query;

    nodeList = vector<Node>(nodeCount + 1);
    for (int i = 1; i <= nodeCount; i++)
    {
        nodeList[i].parent = i;
        nodeList[i].level = 0;
    }


    int queryType, node1, node2;
    while (query--)
    {
        cin >> queryType >> node1 >> node2;

        if (queryType == 0)
            merge(node1, node2);
        else
            if (find(node1) == find(node2))
                cout << "YES\n";
            else
                cout << "NO\n";

    }

    return 0;
}



void merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2) return;

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
