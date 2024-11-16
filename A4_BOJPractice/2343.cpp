//https://www.acmicpc.net/problem/2343

/* 기타 레슨 (Silver 1)
Solution : 이분 탐색
블루레이 크기 기준으로 이분 탐색을 하는 것이다.
블루레이는 최대 10억이고, 각 이분 탐색에는 디스크 순차 탐색을 해야하므로
그러면 시간 복잡도는 log(10억) * 10만 으로 제한 시간 내에 가능하다. 
(Left 출력)
*/

#include <iostream>
using namespace std;
int lectureCount, bluerayCount;
int lectureList[100001];

int countBluerayCount(int bluerayLimit)
{
	int blueray = 1;
	int nowCapacity = 0;
	for (int i = 0; i < lectureCount; i++)
	{
		if (lectureList[i] > bluerayLimit)
			return 999999;
		else if (nowCapacity + lectureList[i] > bluerayLimit)
		{
			blueray++;
			nowCapacity = lectureList[i];
		}
		else
			nowCapacity += lectureList[i];
	}

	return blueray;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> lectureCount >> bluerayCount;

	for (int i = 0; i < lectureCount; i++)
		cin >> lectureList[i];

	int left = 1, right = 1000000000;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int result = countBluerayCount(mid);

		if (result > bluerayCount)
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << left;

	return 0;
}
