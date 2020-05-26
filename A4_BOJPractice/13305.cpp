//https://www.acmicpc.net/problem/13305

//������
//N���� ���ð� ������ ���� ���� �ִ�.
//���� ������ ���ÿ��� �������� ���÷� �ڵ����� �̿��Ͽ� �̵��Ѵ�.
//ó�� ����� �� �ڵ������� �⸧�� ���� �����ҿ��� �⸧�� �ְ� ����Ͽ��� �Ѵ�. �⸧���� ũ��� �������̶�� �����ϰ� 1km�� 1L�� �Ҹ��Ѵ�.
//�� ���ÿ��� �� �ϳ��� �����Ұ� �ְ�, ���ø��� ���ʹ� ������ �ٸ� �� �ִ�.

//���� ������ ���� ���̿�, �� ���� �������� ������ �־��� ��, �� ������ ���ñ��� ���� �ּ��� ����� ���Ͻÿ�.

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