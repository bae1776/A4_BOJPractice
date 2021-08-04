//https://www.acmicpc.net/problem/20117

/*호반우 상인의 이상한 품질 계산법
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	int maxValue = 0;

	vector<int> hobanList(count);
	for (int i = 0; i < count; i++)
		cin >> hobanList[i];

	sort(hobanList.begin(), hobanList.end());

	for (int i = (count + 1) / 2; i < count; i++)
	{
		maxValue += hobanList[i] * 2;
	}

	if (count % 2 == 1)
		maxValue += hobanList[count / 2];


	cout << maxValue;

	return 0;
}