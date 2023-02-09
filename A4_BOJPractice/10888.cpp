//https://www.acmicpc.net/problem/10888

/*두 섬간의 이동 (Gold 2)
Solution : Union Find
서로 떨어진 섬 집합 A, B를 연결하는 다리를 놓을 때,
다음 식만큼 값이 추가된다. (A의 섬 개수를 a, B의 섬 개수를 b라 하자)
1. 왕래 쌍의 개수 : a * b
2. 섬에서 다른 섬으로 가기 위해 이용해야 하는 최소 다리 개수의 합 : ab(b+1)/2 + b(b-1)

메모리 제한이 고작 16MB임에 유의한다.
섬의 개수는 최대 10만개이고, int가 400만개 넘으면 터진다.
*/

#include <iostream>
using namespace std;

int parent[100001], uRank[100001], setSize[100001];
pair<int, int> union_merge(int a, int b); //returns setSize of a and b before merge
int union_find(int a);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int islandCount;
	cin >> islandCount;

	for (int i = 1; i <= islandCount; i++)
	{
		parent[i] = i;
		uRank[i] = setSize[i] = 1;
	}

	long long islandPair = 0, islandBridge = 0;
	int bridgeNumber;
	for (int i = 0; i < islandCount - 1; i++)
	{
		cin >> bridgeNumber;
		auto sizePair = union_merge(bridgeNumber, bridgeNumber + 1);

		islandPair += (long long)(sizePair.first) * sizePair.second;
		islandBridge += (long long)(sizePair.first) * sizePair.second * 
						(sizePair.first + sizePair.second) / 2;


		cout << islandPair << ' ' << islandBridge << '\n';
	}	


	return 0;
}


pair<int, int> union_merge(int a, int b)
{
	a = union_find(a);
	b = union_find(b);

	pair<int, int> sizePair = {setSize[a], setSize[b]};

	if (uRank[a] < uRank[b])
	{
		parent[a] = b;
		setSize[b] = setSize[a] + setSize[b];
	} else {
		parent[b] = a;
		setSize[a] = setSize[a] + setSize[b];

		if (uRank[a] == uRank[b])
			uRank[a]++;
	}

	return sizePair;
}


int union_find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = union_find(parent[a]); 
}