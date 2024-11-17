//https://www.acmicpc.net/problem/17103

/* 골드바흐 파티션 (Silver 2)
Solution : 에라토스테네스의 체 + 이분탐색
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> prime = { 2, 3 };
	for (int n = 5; n <= 1000000; n++)
	{
		bool isPrime = true;
		for (int& p : prime)
		{
			if (p * p > n)
				break;
			if (n % p == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			prime.push_back(n);
	}

	int tc;
	cin >> tc;

	while (tc--)
	{
		int input;
		cin >> input;

		const int bound = input / 2;
		int ans = 0;
		for (int i = 0; prime[i] <= bound; ++i)
		{
			if (binary_search(prime.begin(), prime.end(), input - prime[i]))
				ans++;
		}

		cout << ans << '\n';
	}



	return 0;
}
