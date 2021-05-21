//https://www.acmicpc.net/problem/20115

/*에너지 드링크
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int drinkCount;
	
	cin >> drinkCount;

	vector<long long> drinkList(drinkCount);
	
	long long drinkSum = 0;
	long long maxDrink = 0;

	for (int i = 0; i < drinkCount; i++)
	{
		cin >> drinkList[i];
		drinkSum += drinkList[i];
		if (maxDrink < drinkList[i])
			maxDrink = drinkList[i];
	}

	double result = maxDrink + (drinkSum - maxDrink) / 2.0;
	cout << result;

	return 0;
}