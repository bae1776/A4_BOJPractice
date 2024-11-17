//https://www.acmicpc.net/problem/4134

/* 다음 소수 (Silver 4)
Solution : 에라토스테네스의 체
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

	vector<long long> prime = { 2, 3 };
	for (int n = 5; n <= 80000; n++)
	{
		bool isPrime = true;
		for (long long& p : prime)
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
		long long input;
		cin >> input;

		if (input <= 2)
		{
			cout << 2 << '\n';
			continue;
		}

		for (long long n = input; ; ++n)
		{
			bool isPrime = true;
			for (long long& p : prime)
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
			{
				cout << n << '\n';
				break;
			}
		}
	}



	return 0;
}




