//https://www.acmicpc.net/problem/19535

//ㄷㄷㄷㅈ
//정점 4개로 만들어진 트리는 ㄷ 모양 혹은 ㅈ 모양을 이룬다.
//최대 정점이 30만개의 트리에서도
//이 중 정점을 4개를 골라 집합을 만들었을 때의 모양은 ㄷ 혹은 ㅈ일 것이다.
//해당 트리에서 ㄷ, ㅈ 모양의 개수를 세어
//D, G, DUDUDUNGA 트리 중에 무엇인지 구해보자.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


typedef struct _node {
	int parent;	//for count D shape
	int number;
	int childCount; //for count G shape
} Node;


int getDCount(vector<Node>& nodeList, int startNode);
long long combination(int n, int k);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodeCount;
	cin >> nodeCount;

	long long Dshape = 0, Gshape = 0;


	vector<vector<int>> adjList(nodeCount + 1, vector<int>());
	for (int i = 0; i < nodeCount - 1; i++)
	{
		int start, end;
		cin >> start >> end;

		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	vector<Node> nodeList(nodeCount + 1);
	for (int i = 0; i <= nodeCount; i++)
	{
		nodeList[i].number = i;
		nodeList[i].childCount = adjList[i].size() - 1;
	}
	

	nodeList[1].childCount += 1;
	queue<pair<int, int>> bfsQueue; //<parent, myself> numbers
	bfsQueue.emplace(1, 1);

	while (bfsQueue.empty() == false)
	{
		pair<int, int> nowNode = bfsQueue.front();
		bfsQueue.pop();
		nodeList[nowNode.second].parent = nowNode.first;

		for (int& adjNode : adjList[nowNode.second])
		{
			if (adjNode == nowNode.first)
				continue;
			else
				bfsQueue.emplace(nowNode.second, adjNode);
		}
	}
	

	//Count G shape
	Gshape = combination(nodeList[1].childCount, 3);
	
	for (int i = 2; i <= nodeCount; i++)
	{
		Gshape += combination(nodeList[i].childCount, 2);
		Gshape += combination(nodeList[i].childCount, 3);
	}


	//Count D shape
	for (int i = 1; i <= nodeCount; i++)
		Dshape += getDCount(nodeList, i);


	if (Dshape > Gshape * 3ll)
		cout << "D";
	else if (Dshape < Gshape * 3ll)
		cout << "G";
	else
		cout << "DUDUDUNGA";




	return 0;
}




long long combination(int n, int k)
{
	if (n < k)
		return 0;

	long long result = 1;

	for (int i = 0; i < k; i++)
		result *= (n - i);
	
	for (int i = 2; i <= k; i++)
		result /= i;

	return result;
}


int getDCount(vector<Node>& nodeList, int startNode)
{
	int findRoot = 0;
	while (startNode != 1)
	{
		startNode = nodeList[startNode].parent;
		findRoot++;
		if (findRoot == 2)
			if (startNode == 1)
				return nodeList[startNode].childCount - 1;
			else
				return nodeList[startNode].childCount;
	}

	return 0;
}