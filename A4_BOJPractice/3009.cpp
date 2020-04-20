//https://www.acmicpc.net/problem/3009

//축에 평행한 직사각형의 좌표가 3개 주어질때,
//나머지 하나의 좌표를 구하시오.

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



