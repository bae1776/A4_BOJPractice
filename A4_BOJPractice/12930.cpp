//https://www.acmicpc.net/problem/12930

/* 두 가중치 (Platinum 5)

N개의 정점으로 이루어진 그래프 G가 있고, 그래프의 정점은 0 ~ N-1까지 번호가 매겨져 있다.
그래프 G의 모든 간선은 가중치를 2개 가지고 있고 각각 A, B라 하자.
0에서 1번 정점으로 가는 최단 경로를 찾는 프로그램을 작성하시오.
경로 길이는 (A 가중치 합) * (B 가중치 합)으로 계산한다.

Solution : 벨만-포드를 이용해 DP[nodeIndex][weightA] = minWeightB 를 처리한다.
*/

#include <vector>
#include <iostream>
#include <list>
using namespace std;
#define INF 0x3FFFFFFF

struct Element {
    int weightA, weightB, destination;
};

list<Element> edgeList[20];
int DP[20][200];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeCount;
	cin >> nodeCount;

	//Weight A Input
	char edgeInput[30];
	for (int i = 0; i < nodeCount; i++)
	{
		cin >> edgeInput;
		for (int j = 0; j < nodeCount; j++)
		{
			if (edgeInput[j] != '.')
				edgeList[i].push_back({.weightA = edgeInput[j] - '0', .destination = j});
		}
	}

	//Weight B Input
	for (int i = 0; i < nodeCount; i++)
	{
		cin >> edgeInput;
		auto listIterator = edgeList[i].begin();
		for (int j = 0; j < nodeCount; j++)
		{
			if (edgeInput[j] != '.')
			{
				listIterator->weightB = edgeInput[j] - '0';
				++listIterator;
			}
		}
	}

	fill(DP[0], DP[0] + 4000, INF);
	DP[0][0] = 0;

	//벨만 포드  (최악의 경우 20 * 20 * 200 * 20 = 16만)
	for (int times = 0; times < nodeCount - 1; times++)
	{
		for (int startNode = 0; startNode < nodeCount; startNode++)
		{
			for (int weightA = 0; weightA < 190; weightA++)
			{
				if (DP[startNode][weightA] == INF) continue;

				for (const Element& edge : edgeList[startNode])
				{
					DP[edge.destination][weightA + edge.weightA] = min(DP[startNode][weightA] + edge.weightB, 
					DP[edge.destination][weightA + edge.weightA]);
				}
			}
		}
	}

	int result = INF;

	for (int weightA = 0; weightA < 200; weightA++)
	{
		if (DP[1][weightA] != INF)
			result = min(result, DP[1][weightA] * weightA);
	}

	if (result == INF)
		cout << -1;
	else
		cout << result;

    return 0;
}