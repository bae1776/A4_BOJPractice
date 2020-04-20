//https://www.acmicpc.net/problem/16435

//스네이크버드의 주요 먹이는 과일이며 과일 하나를 먹으면 길이가 1만큼 늘어납니다.
//과일들은 지상으로부터 일정 높이를 두고 떨어져 있으며 i(1 ≤ i ≤ N) 번째 과일의 높이는 hi입니다.
//스네이크버드는 자신의 길이보다 작거나 같은 높이에 있는 과일들을 먹을 수 있습니다.
//스네이크버드의 처음 길이가 L일때 과일들을 먹어 늘릴 수 있는 최대 길이를 구하세요.


#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int fruitCount, length;
	cin >> fruitCount >> length;

	int* fruit_heightList = new int[fruitCount];
	
	for (int i = 0; i < fruitCount; i++)
	{
		cin >> fruit_heightList[i];
	}

	sort(fruit_heightList, fruit_heightList + fruitCount);


	for (int i = 0; i < fruitCount; i++)
	{
		if (fruit_heightList[i] <= length)
			length++;
		else
			break;
	}

	
	cout << length;


	delete[] fruit_heightList;
	
	return 0;
}