//https://www.acmicpc.net/problem/11650

//평면 상의 점을 입력받고 정렬하시오.


#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int pointCount;
	cin >> pointCount;

	vector<pair<int, int>> pointList;
	pointList.reserve(pointCount);

	for (int i = 0; i < pointCount; i++)
	{
		int x, y;
		cin >> x >> y;
		pointList.emplace_back(x, y);
	}

	sort(pointList.begin(), pointList.end());

	for (auto& element : pointList)
	{
		cout << element.first << ' ' << element.second << '\n';
	}


	return 0;
}