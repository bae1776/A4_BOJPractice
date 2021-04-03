//https://www.acmicpc.net/problem/14496

//그대, 그머가 되어
//그래프 bfs 문제

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int before, after;
	cin >> before >> after;

	int node, edge;
	cin >> node >> edge;

	vector<vector<int>> adjList(node + 1, vector<int>());

	for (int i = 0; i < edge; i++)
	{
		int start, end;
		cin >> start >> end;

		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	bool* visited = new bool[node + 1];
	for (int i = 0; i <= node; i++)
		visited[i] = false;


	queue<pair<int, int>> bfsQueue; //nodeNumber, depth
	bfsQueue.emplace(before, 0);
	int result = -1;

	while (bfsQueue.empty() == false)
	{
		pair<int, int> nowNode = bfsQueue.front();
		bfsQueue.pop();
		if (nowNode.first == after)
		{
			result = nowNode.second;
			break;
		}

		const vector<int>& nowNode_adjList = adjList[nowNode.first];

		for (auto i = nowNode_adjList.begin(); i != nowNode_adjList.end(); ++i)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				bfsQueue.emplace(*i, nowNode.second + 1);
			}
		}
	}

	cout << result;

	delete[] visited;

	return 0;
}

