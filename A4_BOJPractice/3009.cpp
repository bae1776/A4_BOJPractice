//https://www.acmicpc.net/problem/3009

//�࿡ ������ ���簢���� ��ǥ�� 3�� �־�����,
//������ �ϳ��� ��ǥ�� ���Ͻÿ�.

#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> point[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> point[i].first >> point[i].second;
	}



	pair<int, int> fourthPoint;


	if (point[0].first == point[1].first)
		fourthPoint.first = point[2].first;
	else if (point[0].first == point[2].first)
		fourthPoint.first = point[1].first;
	else
		fourthPoint.first = point[0].first;

	if (point[0].second == point[1].second)
		fourthPoint.second = point[2].second;
	else if (point[0].second == point[2].second)
		fourthPoint.second = point[1].second;
	else
		fourthPoint.second = point[0].second;

	
	cout << fourthPoint.first << ' ' << fourthPoint.second;

	

	return 0;
}



