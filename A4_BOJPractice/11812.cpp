//https://www.acmicpc.net/problem/11812

//K진 트리 (노드 최대 10^15, 1 <= K <= 15)에서
//노드 쌍이 주어질 때, 최단 거리를 logN 시간 복잡도 내에 구하는 알고리즘을 작성하시오.

#include <iostream>
using namespace std;

int childCount;
inline long long get_nodeDistance(long long nodeA, long long nodeB);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	long long nodeCount;
	int query;

	cin >> nodeCount >> childCount >> query;

	for (int rep = 0; rep < query; ++rep)
	{
		long long node1, node2;
		cin >> node1 >> node2;

		cout << get_nodeDistance(node1, node2) << '\n';
	}


	return 0;
}


inline long long get_nodeDistance(long long nodeA, long long nodeB)
{
	long long distance = 0;

	if (childCount == 1)
		if (nodeA > nodeB)
			return nodeA - nodeB;
		else
			return nodeB - nodeA;

	while (nodeA != nodeB)
	{
		distance += 1;
		if (nodeA > nodeB)
			nodeA = (nodeA + childCount - 2) / childCount;
		else
			nodeB = (nodeB + childCount - 2) / childCount;
	}

	return distance;
}