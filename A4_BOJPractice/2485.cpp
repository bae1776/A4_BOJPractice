//https://www.acmicpc.net/problem/2485

/* ���μ� (Silver 4)
Solution :
������ �迭 �� ���� ������ �ִ������� ���Ѵ�.
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;

int diff[100004];

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cnt, first;
	cin >> cnt >> first;

	int second, gcdval = 0;
	for (int i = 1; i < cnt; i++)
	{
		cin >> second;
		diff[i] = second - first;
		gcdval = gcd(diff[i], gcdval);
		first = second;
	}

	int ans = 0;
	for (int i = 1; i < cnt; i++)
		ans += diff[i] / gcdval - 1;

	cout << ans;

	return 0;
}


