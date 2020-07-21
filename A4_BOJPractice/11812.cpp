//https://www.acmicpc.net/problem/11812

//K�� Ʈ�� (��� �ִ� 10^15, 1 <= K <= 15)����
//��� ���� �־��� ��, �ִ� �Ÿ��� logN �ð� ���⵵ ���� ���ϴ� �˰����� �ۼ��Ͻÿ�.

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