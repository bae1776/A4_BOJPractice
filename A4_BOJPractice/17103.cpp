//https://www.acmicpc.net/problem/17103

/* ������ ��Ƽ�� (Silver 2)
Solution : �����佺�׳׽��� ü + �̺�Ž��
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
