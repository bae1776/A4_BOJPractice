//https://www.acmicpc.net/problem/15899

/* 트리와 색깔 (Platinum 2)

Solution : 오일러 경로 테크닉 + 머지 소트 트리

머지 소트 트리는 세그먼트 트리의 파생형으로
머지 소트 시 조각 냈던 파트를 정렬되도록 합치는 과정처럼 세그먼트 트리 원소를 구성하는 것이다.
이 자료구조를 사용하는 대표적인 문제는 7469(K번째 수)번이고, 그 코드를 참고하라.
-> 참고로 머지 소트 트리의 탐색 시간 복잡도는 각 쿼리당 O((logN) ^ 2), 공간 복잡도는 O(NlogN)이다.

오일러 경로 테크닉이란, 트리의 노드 번호를 전위 순회 방문 순으로 번호를 매기면서
서브트리의 노드를 O(1)만에 알 수 있게 한다. (처음 전위 순회에만 O(N)이 걸린다.)
예를 들어 다음과 같은 트리를 가정하자.
   1		다음 트리를 전위 순회하면, orgin = 1-3-4-2-6-5 순으로 방문한다.
 / | \						여기에, visit = 1-2-3-4-5-6 순으로 번호를 매기면
3  4  5		1번 노드를 루트로하는 서브트리는 visit[0] ~ visit[4]까지 이다.
  / \ 		4번 노드를 ...				 visit[2] ~ visit[4]까지 이다.
 2   6		
			전위 순회 시 서브 트리들을 모두 방문한 후 돌아올 때 가장 마지막으로 방문했던 저장해두면,
			자기 자신부터 ~ 가장 마지막 방문 번호까지가 모두 자기 자신의 서브트리가 된다.

이 문제는 오일러 경로 테크닉으로 정점 번호를 다시 매기면서, 서브트리들에 대한 노드를 저장시킨다.
그리고 다시 새로 매겨진 번호에 대해 노드에 칠해진 색을 하나 저장하는 정보를 리프 노드로 하는 마지 소트 트리를 구성한다.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

struct MergesortTree {
	int start;
	int end;
	vector<int> colorList;
};

MergesortTree tree[(1 << 19) + 2];
int nodeColor[200002]; 
int numToVisit[200002], visitToNum[200002];
int visitEnd[200002]; /*방문 번호의 마지막 서브노드*/ 
deque<int> adjList[200002];
int nodeCount, queryCount, colorCount;

void reNumbering(int parent, int node);
MergesortTree& makeMergesortTree(int num, int start, int end);
int queryFunction(const int& node, const int& color);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeCount >> queryCount >> colorCount;
	for (int i = 1; i <= nodeCount; i++)
		cin >> nodeColor[i];

	int start, end;
	for (int i = 1; i <= nodeCount - 1; i++)
	{
		cin >> start >> end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	//renumbering using VLR traverse
	reNumbering(1, 1);

	//makeMergesortTree
	makeMergesortTree(1, 1, nodeCount);

	int result = 0, num, color;
	while (queryCount--)
	{
		cin >> num >> color;
		result = (result + queryFunction(num, color)) % 1000000007;
	}

	cout << result;

	return 0;
}




void reNumbering(int parent, int node)
{
	static int visitOrder = 1;
	numToVisit[node] = visitOrder;
	visitToNum[visitOrder++] = node;

	for (const int& next : adjList[node])
	{
		if (next != parent)
			reNumbering(node, next);
	}
	visitEnd[numToVisit[node]] = visitOrder - 1;
}

MergesortTree& makeMergesortTree(int num, int start, int end)
{
	MergesortTree& now = tree[num];
	now.start = start;
	now.end = end;

	if (start == end)
	{
		now.colorList.push_back(nodeColor[visitToNum[start]]);
		return now;
	}

	int mid = (start + end) / 2;
	auto& leftSub = makeMergesortTree(num * 2, start, mid).colorList;
	auto& rightSub = makeMergesortTree(num * 2 + 1, mid + 1, end).colorList;

	now.colorList = vector<int>(end - start + 1);
	std::merge(leftSub.begin(), leftSub.end(),
			  rightSub.begin(), rightSub.end(), now.colorList.begin());

	return now;
}


int queryFunction(const int& node, const int& color)
{
	const int& subTreeStart = numToVisit[node];
	const int& subTreeEnd = visitEnd[numToVisit[node]];

	//mergesort Tree find (bfs)
	queue<int> bfsQueue;
	deque<int> resultLists;
	bfsQueue.push(1);

	while (bfsQueue.empty() == false)
	{
		int treeNumber = bfsQueue.front();
		MergesortTree& now = tree[treeNumber];
		bfsQueue.pop();

		if (subTreeStart <= now.start && now.end <= subTreeEnd)
		{
			resultLists.push_back(treeNumber);
		} else {
			int mid = (now.start + now.end) / 2;
			if (subTreeStart <= mid)
				bfsQueue.push(treeNumber * 2);
			if (subTreeEnd >= mid + 1)
				bfsQueue.push(treeNumber * 2 + 1);
		}
	}

	int result = 0;
	for (const int& selectedNode : resultLists)
	{
		const auto& selected = tree[selectedNode].colorList;
		result += upper_bound(selected.begin(), selected.end(), color) - selected.begin();
	}

	return result;
}