//https://www.acmicpc.net/problem/13305

//주유소
//N개의 도시가 일직선 도로 위에 있다.
//제일 왼쪽의 도시에서 오른쪽의 도시로 자동차를 이용하여 이동한다.
//처음 출발할 때 자동차에는 기름이 없어 주유소에서 기름을 넣고 출발하여야 한다. 기름통의 크기는 무제한이라고 가정하고 1km에 1L를 소모한다.
//각 도시에는 단 하나의 주유소가 있고, 도시마다 리터당 가격은 다를 수 있다.

//도시 사이의 도로 길이와, 각 도시 주유소의 가격이 주어질 때, 맨 오른쪽 도시까지 가는 최소의 비용을 구하시오.

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> roadLength;
	vector<int> gasPrice;

	int cities;
	cin >> cities;

	roadLength.reserve(cities - 1);
	gasPrice.reserve(cities);


	int input;
	for (int i = 0; i < cities - 1; i++)
	{
		cin >> input;
		roadLength.emplace_back(input);
	}

	for (int i = 0; i < cities; i++)
	{
		cin >> input;
		gasPrice.emplace_back(input);
	}

	long long int totalPrice = 0;
	int nowVisit = 0;
	int nextVisit = 1;
	
	do {
		int totalRoad = roadLength[nowVisit];
		
		while (nextVisit < cities - 1 && gasPrice[nowVisit] <= gasPrice[nextVisit])
		{
			totalRoad += roadLength[nextVisit];
			nextVisit++;
		}
		
		totalPrice += (long long)totalRoad * (long long)gasPrice[nowVisit];
		nowVisit = nextVisit++;
		if (nowVisit == cities - 1) break;
	} while (true);


	cout << totalPrice;




	return 0;
}