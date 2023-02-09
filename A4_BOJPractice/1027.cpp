//https://www.acmicpc.net/problem/1027

/*고층 건물 (Gold 4)
Solution : 건물의 수가 50개이기 때문에 브루트 포스로 해결 가능
단, 구현이 만만치는 않다.
*/

#include <iostream>
using namespace std;

long long heightList[51];

struct Fraction {
	long long up, down;

	long long getInt() {
		return up / down;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int buildings;
	cin >> buildings;

	for (int i = 0; i < buildings; i++)
		cin >> heightList[i];

	int answer = 0;
	for (int now = 0; now < buildings; now++)
	{
		const long long& nowHeight = heightList[now];
		int lookCount = 0;
		
		Fraction maxGradient = {-100000000000ll, 1};
		for (int left = now - 1; left >= 0; left--)
		{
			Fraction minHeight = {
				nowHeight * maxGradient.down + maxGradient.up * (now - left), 
				maxGradient.down
			};

			if (heightList[left] > minHeight.getInt())
			{
				lookCount++;
				maxGradient = {heightList[left] - heightList[now], now - left}; 
			}
		}
 
		maxGradient = {-100000000000ll, 1};
		for (int right = now + 1; right < buildings; right++)
		{
			Fraction minHeight = {
				nowHeight * maxGradient.down + maxGradient.up * (right - now), 
				maxGradient.down
			};

			if (heightList[right] > minHeight.getInt())
			{
				lookCount++;
				maxGradient = {heightList[right] - heightList[now], right - now}; 
			}
		}

		answer = max(lookCount, answer);
	}

	cout << answer;
	
	return 0;
}

