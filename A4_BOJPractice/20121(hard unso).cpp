//https://www.acmicpc.net/problem/20121

/*카드 셔플
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
		int cardCount, start, end;
		cin >> cardCount >> start >> end;

		int suffCount = 0;
		long long min = start;
		long long max = start;
		long long target = end;
		
		while (true) {
			if (target < min)
				target += cardCount;
			else if (target > max)
			{
				min = (min * 2) - 1;
				max *= 2;
				suffCount++;
			}
			else {
				int answer = target - min;

				for (int i = exp(suffCount - 1); i > 0; i /= 2)
					if ((answer & i) == 0)
						cout << 'X';
					else
						cout << 'Y';

				cout << '\n';
				break;
			}
		}
		
	}

	return 0;
}