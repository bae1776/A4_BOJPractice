//https://www.acmicpc.net/problem/11725

/*트리의 부모 찾기

루트 없는 트리가 주어질때, 트리의 루트를 1이라고 정한 경우의
각 노드의 부모를 구하세요.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int parent;
	vector<int> adjList;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeCount;
	cin >> nodeCount;

	vector<Node> nodeList(nodeCount + 1, {.parent = -1});

	for (int i = 0; i < nodeCount - 1; i++)
	{
		int start, end;
		cin >> start >> end;
		nodeList[start].adjList.emplace_back(end);
		nodeList[end].adjList.emplace_back(start);

	}

	queue<int> bfsQueue;
	bfsQueue.emplace(1);

	while (bfsQueue.empty() == false)
	{
		const auto& nodeNumber = bfsQueue.front();

		for (const int& adjNodeNumber : nodeList[nodeNumber].adjList)
		{
			if (nodeList[adjNodeNumber].parent == -1)
			{
				nodeList[adjNodeNumber].parent = nodeNumber;
				bfsQueue.emplace(adjNodeNumber);
			}
		}

		bfsQueue.pop();
	}

	for (int nodeNum = 2; nodeNum <= nodeCount; nodeNum++)
		cout << nodeList[nodeNum].parent << '\n';
	

	return 0;
}