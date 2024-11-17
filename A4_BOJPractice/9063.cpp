//https://www.acmicpc.net/problem/9063

/* 대지 (Bronze 3)
Solution : 수학
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int leftest = 99999, rightest = -99999, upest = -99999, downest = 99999;
	while (n--)
	{
		int x, y;
		cin >> x >> y;

		leftest = min(leftest, x);
		rightest = max(rightest, x);
		upest = max(upest, y);
		downest = min(downest, y);
	}

	cout << (rightest - leftest) * (upest - downest);

	return 0;
}


